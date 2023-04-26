#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "Legend 2.4";
const char* password = "Png@7870";

// Initialize Telegram BOT
#define BOTtoken "6090424763:AAG0mAmUBXJeZxAEvanInvgRPNYajE4xMXQ"  // your Bot Token (Get from Botfather)
#define CHAT_ID "1429956409"    // get from ID Bot

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int flamesensor = 15; 
bool flameDetected = false;

void IRAM_ATTR detectsFlame() {
  //Serial.println("Fire Alert!!!");
  flameDetected = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(flamesensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(flamesensor), detectsFlame, RISING);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Device Activated and iniciating the process.", "");
}

void loop() {
  if(flameDetected){
    bot.sendMessage(CHAT_ID, "Fire Alert!!!", "");
    Serial.println("Fire Alert!!!");
    flameDetected = false;
  }
}
