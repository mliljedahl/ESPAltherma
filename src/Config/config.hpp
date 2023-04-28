#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <LittleFS.h>
#include "parameterDef.hpp"
#include "ArduinoJson.h"
#include "CAN/CANConfig.hpp"

#define CONFIG_FILE "/config.json"
#define MODELS_CONFIG_SIZE 1024*10

enum class X10AProtocol : uint8_t {
    I,
    S
};

struct Config
{
    bool configStored;
    bool STANDALONE_WIFI;
    String SSID;
    String SSID_PASSWORD;
    bool SSID_STATIC_IP;
    String SSID_IP;
    String SSID_SUBNET;
    String SSID_GATEWAY;
    String SSID_PRIMARY_DNS;
    String SSID_SECONDARY_DNS;
    String MQTT_SERVER;
    String MQTT_USERNAME;
    String MQTT_PASSWORD;
    bool MQTT_USE_JSONTABLE;
    bool MQTT_USE_ONETOPIC;
    String MQTT_TOPIC_NAME;
    String MQTT_ONETOPIC_NAME;
    uint16_t MQTT_PORT;
    uint32_t FREQUENCY;
    uint8_t PIN_ENABLE_CONFIG;
    bool X10A_ENABLED;
    uint8_t PIN_RX;
    uint8_t PIN_TX;
    X10AProtocol X10A_PROTOCOL;
    bool HEATING_ENABLED;
    uint8_t PIN_HEATING;
    bool COOLING_ENABLED;
    uint8_t PIN_COOLING;
    bool SG_ENABLED;
    uint8_t PIN_SG1;
    uint8_t PIN_SG2;
    bool SG_RELAY_HIGH_TRIGGER;
    bool CAN_ENABLED;
    CAN_ICTypes CAN_IC;
    CAN_ICBus CAN_BUS;
    DriverUARTConfig CAN_UART;
    DriverSPIConfig CAN_SPI;
    DriverBluetoothConfig CAN_BLUETOOTH;
    uint16_t CAN_SPEED_KBPS;
    String CAN_MQTT_TOPIC_NAME;
    bool CAN_READONLY_ENABLED;
    bool CAN_SNIFFING_ENABLED;
    CAN_PollMode CAN_AUTOPOLL_MODE;
    uint16_t CAN_AUTOPOLL_TIME;
    size_t PARAMETERS_LENGTH;
    ParameterDef** PARAMETERS;
    size_t COMMANDS_LENGTH;
    CommandDef** COMMANDS;
    String WEBUI_SELECTION_VALUES;

    ~Config();
};

extern Config* config;

void readConfig();

void saveConfig();

#endif