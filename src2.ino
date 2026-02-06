#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <user_interface.h> // For wifi_softap_get_station_info()

// ==============================
// CONFIGURATION
// ==============================

const char* AP_SSID = "KOReader-Turner";
const char* AP_PASS = "12345678";

const int KOREADER_PORT = 8080;

// Pin assignments
const int BUTTON_NEXT_PIN      = D1;
const int BUTTON_PREV_PIN      = D2;
const int NEXT_CHAPTER_PIN     = D5;
const int PREV_CHAPTER_PIN     = D6;
const int LED_PIN = D4;

// ==============================

WiFiClient koreaderClient;

bool prevNextState       = HIGH;
bool prevPrevState       = HIGH;
bool prevNextChapter     = HIGH;
bool prevPrevChapter     = HIGH;

IPAddress clientIP;              // Will store KOReader's actual IP
bool clientConnected = false;    // Flag for first client connection

// ---------- SEND COMMAND ----------
void sendCommand(const String& path)
{
  if (!clientConnected) return; // No client connected yet

  HTTPClient http;
  String url = "http://" + clientIP.toString() + ":" + String(KOREADER_PORT) + path;
  http.begin(koreaderClient, url);
  http.setReuse(true);
  int code = http.GET();
  Serial.println("Response: " + String(code));
  http.end();

  // Blink LED for feedback
  digitalWrite(LED_PIN, HIGH);
  delay(25);
  digitalWrite(LED_PIN, LOW);
}

// ---------- BUTTONS ----------
void checkButtons()
{
  bool currentNext       = digitalRead(BUTTON_NEXT_PIN);
  bool currentPrev       = digitalRead(BUTTON_PREV_PIN);
  bool currentNextChap   = digitalRead(NEXT_CHAPTER_PIN);
  bool currentPrevChap   = digitalRead(PREV_CHAPTER_PIN);

  // Page forward (+1 page)
  if (prevNextState == HIGH && currentNext == LOW)
    sendCommand("/koreader/event/GotoViewRel/1");

  // Page backward (-1 page)
  if (prevPrevState == HIGH && currentPrev == LOW)
    sendCommand("/koreader/event/GotoViewRel/-1");

  // Chapter forward
  if (prevNextChapter == HIGH && currentNextChap == LOW)
    sendCommand("/koreader/event/GotoNextChapter");

  // Chapter backward
  if (prevPrevChapter == HIGH && currentPrevChap == LOW)
    sendCommand("/koreader/event/GotoPrevChapter");

  prevNextState     = currentNext;
  prevPrevState     = currentPrev;
  prevNextChapter   = currentNextChap;
  prevPrevChapter   = currentPrevChap;
}

// ---------- GET FIRST CLIENT IP ----------
void detectClientIP()
{
  if (clientConnected) return; // Already detected

  struct station_info *station = wifi_softap_get_station_info();
  if (station) {
    clientIP = IPAddress(station->ip.addr);
    clientConnected = true;
    Serial.print("First client connected with IP: ");
    Serial.println(clientIP);
    wifi_softap_free_station_info(); // Free memory
  }
}

// ---------- SETUP ----------
void setup()
{
  Serial.begin(115200);
  delay(500);

  pinMode(BUTTON_NEXT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PREV_PIN, INPUT_PULLUP);
  pinMode(NEXT_CHAPTER_PIN, INPUT_PULLUP);
  pinMode(PREV_CHAPTER_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  // Setup AP with ESP static IP
  IPAddress ESP_IP(4,3,2,1);
  IPAddress GATEWAY(4,3,2,1);
  IPAddress SUBNET(255,255,255,0);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ESP_IP, GATEWAY, SUBNET);
  WiFi.softAP(AP_SSID, AP_PASS);

  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  Serial.println("AP Ready, waiting for KOReader to connect...");
}

// ---------- LOOP ----------
void loop()
{
  // Detect first connected client dynamically
  detectClientIP();

  // Check buttons and send commands
  checkButtons();

  delay(10);
}
