#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

#define LED_PIN 2    // Change to the pin connected to your LED/relay
#define DEVICE_PIN 3 // Change to the pin connected to your LED/relay

BLECharacteristic *pCharacteristic;

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();
    Serial.println(value.c_str());
    if (value.length() > 0)
    {
      if (value[0] == '1')
      {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(DEVICE_PIN, LOW);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(DEVICE_PIN, HIGH);
      }
      else if (value[0] == '2')
      {
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        delay(1000);
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
      }
      else if (value[0] == '3')
      {
        digitalWrite(LED_PIN, HIGH);
        delay(5000);
        digitalWrite(LED_PIN, LOW);
      }
    }
  }
};

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(DEVICE_PIN, OUTPUT);
  digitalWrite(DEVICE_PIN, HIGH);

  BLEDevice::init("ESP32 LED Control");
  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void loop()
{
  delay(2000);
}