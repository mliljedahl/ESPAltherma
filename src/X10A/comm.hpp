#ifndef COMM_H
#define COMM_H

#include <HardwareSerial.h>
#include "arduinoC.hpp"
#include "x10a.hpp"
#include "debugSerial.hpp"

#define SER_TIMEOUT 300 // leave 300ms for the machine to answer

#ifdef ARDUINO_ARCH_ESP8266
#define SERIAL_FLUSH_TX_ONLY // empty, as SoftwareSerial.flush() takes no parameter
#else
#define SERIAL_FLUSH_TX_ONLY false
#endif

bool queryRegistry(RegistryBuffer *registryBuffer, X10AProtocol protocol);

#endif