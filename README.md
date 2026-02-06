**# ESP8266-KOReader-Remote**
ESP8266 based koreader controller that gives hardware buttons to ereaders. The current version performs the following:
Page Turning
Chapter Turning

**Pinout:**
Next Page        : D1

Previous Page    : D2

Next Chapter     : D5

Previous Chapter : D6

**Usage:**
1. Upload the bin file.
2. Reboot the esp
3. Connect your ereader to "**KOReader-Turner"**
4. Password is "12345678" without quotes.
5. Enable https inspector in koreader. Click on the wrech icon>more tools>KOReader HTTP inspector. Make sure port is set to 8080. Start HTTP server.
6. For convenience check "Auto start HTTP server"
7. Make sure no other device is connect to esp AP.

I made the project via ChatGpt. I got the idea from koreader-page-turner by askobee. https://github.com/akosbeke/koreader-page-turner.
