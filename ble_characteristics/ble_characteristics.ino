#include <CurieBle.h>

static const char* bluetoothDeviceName = "MyDevice"; 

static const char* serviceUuid = "1800"; // Unregulated Service 
static const char* characteristicUuid = "2803"; // Unregulated Charactersitic
static const int   characteristicTransmissionLength = 20; // expect a 20 byte transmission

// create a service
BLEService service(serviceUuid); 

// create a characteristic with Read and write attributes
BLECharacteristic characteristic(
  characteristicUuid,
  BLERead | BLEWrite,
  characteristicTransmissionLength
);


BLEPeripheral blePeripheral; 

void setup() {
  blePeripheral.setLocalName(bluetoothDeviceName); 


  blePeripheral.setAdvertisedServiceUuid(service.uuid()); // attach service
  blePeripheral.addAttribute(service);

  blePeripheral.addAttribute(characteristic); // attach characteristic
  
  blePeripheral.begin(); 
}

void loop() {}

