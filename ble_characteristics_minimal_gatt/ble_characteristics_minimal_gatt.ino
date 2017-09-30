#include <CurieBle.h>

static const char* bluetoothDeviceName = "MyDevice"; 
static const char* modelNumber = "1AB2";
static const char* serialNumber = "1234";
static const uint8_t batteryLevel = 100;

static const char* deviceInformationServiceUuid = "180a"; // Device Information Service 
static const char* batteryLevelServiceUuid = "180f"; // Battery Level Service 
static const char* deviceNameCharacteristicUuid = "2a00"; // Device Name Charactersiticc
static const char* modelNumberCharacteristicUuid = "2a24"; // Model Number Charactersitic
static const char* serialNumberCharacteristicUuid = "2a25"; // Serial Number Charactersiti
static const char* batteryLevelCharacteristicUuid = "2a19"; // Battery Level Charactersitic
static const int   characteristicTransmissionLength = 20; // expect a 20 byte transmission

// create a service
BLEService deviceInformationService(deviceInformationServiceUuid); 
BLEService batteryLevelService(batteryLevelServiceUuid); 

// create minimal GATT profile
BLECharacteristic deviceNameCharacteristic(
  deviceNameCharacteristicUuid,
  BLERead,
  characteristicTransmissionLength
);
BLECharacteristic modelNumberCharacteristic(
  modelNumberCharacteristicUuid,
  BLERead,
  characteristicTransmissionLength
);
BLECharacteristic serialNumberCharacteristic(
  serialNumberCharacteristicUuid,
  BLERead,
  characteristicTransmissionLength
);
BLEUnsignedCharCharacteristic batteryLevelCharacteristic(
  batteryLevelCharacteristicUuid,
  BLERead | BLENotify
);


BLEPeripheral blePeripheral; 

void setup() {
  blePeripheral.setLocalName(bluetoothDeviceName); 

  blePeripheral.setAdvertisedServiceUuid(deviceInformationService.uuid()); // attach service to advertising packet

  // build GATT profile
  blePeripheral.addAttribute(deviceInformationService);
  blePeripheral.addAttribute(deviceNameCharacteristic); 
  blePeripheral.addAttribute(modelNumberCharacteristic); 
  blePeripheral.addAttribute(serialNumberCharacteristic);
  
  blePeripheral.addAttribute(batteryLevelService);
  blePeripheral.addAttribute(batteryLevelCharacteristic); 

  // set the values of the characteristics
  deviceNameCharacteristic.setValue((unsigned char*) bluetoothDeviceName, characteristicTransmissionLength);
  modelNumberCharacteristic.setValue((unsigned char*) modelNumber, characteristicTransmissionLength);
  serialNumberCharacteristic.setValue((unsigned char*) serialNumber, characteristicTransmissionLength);
  batteryLevelCharacteristic.setValue(batteryLevel);
  
  blePeripheral.begin(); 
}

void loop() {}

