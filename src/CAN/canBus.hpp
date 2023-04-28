#ifndef CAN_BUS_H
#define CAN_BUS_H

#include "debugSerial.hpp"
#include "CANConfig.hpp"
#include "CANDriver.hpp"
#include "CAN/Drivers/MCP2515.hpp"
#include "CAN/Drivers/ELM327.hpp"
#include "CAN/Drivers/SJA1000.hpp"

void canBus_setup(const CAN_Config* CANConfig);

void canBus_loop();

void canBus_stop();

#endif