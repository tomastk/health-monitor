// HeartMonitor App - BLE para ESP32 S3
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Configuración BLE
BLEServer *pServer = nullptr;
BLECharacteristic *pCharacteristic = nullptr;
bool deviceConnected = false;
std::string bleServiceUUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";  // UUID del servicio
std::string bleCharacteristicUUID = "6E400002-B5A3-F393-E0A9-E50E24DCCA9E";  // UUID de la característica

void setup() {
  Serial.begin(115200);
  BLEDevice::init("HeartMonitor ESP32 S3");

  pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(bleServiceUUID);

  pCharacteristic = pService->createCharacteristic(
    bleCharacteristicUUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
  );

  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(bleServiceUUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x06); // Tiempo mínimo de conexión
  pAdvertising->setMaxPreferred(0x12); // Tiempo máximo de conexión
  BLEDevice::startAdvertising();

  Serial.println("HeartMonitor ESP32 S3 - BLE inicializado");
}

void loop() {
  // Enviar datos solo si el dispositivo está conectado
  if (deviceConnected) {
    String data = "80";  // Simulación de frecuencia cardíaca
    pCharacteristic->setValue(data.c_str());
    pCharacteristic->notify();
    Serial.println("Frecuencia cardíaca enviada: " + data);
    delay(1000);
  }
}
