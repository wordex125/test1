#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32f4xx_hal.h"
// Pressure sensor config
#define SEA_PRESSURE 1002	// pressure at sea level [hPa]

// Timing parameters [ms]
#define DATA_PRINT_DELAY 1000
#define LOG_SAVE_DELAY 2373
#define LOG_BMP_DELAY 100
#define LOG_IMU_DELAY 100
#define LOG_MOT_DELAY 100
#define LOG_GPS_DELAY 2000
#define LOG_TARGET_YAW_DELAY 1000
// Radio timeout value is set in SX1278 config 
#define SENSING_BMP_DELAY 50

// Peripherial state
#define BMP_1_ENABLE 1
#define SD_ENABLE 1
#define RADIO_ENABLE 1
#define BMP_ENABLE 1
#define GPS_ENABLE 1
#define IMU_ENABLE 1
#define SPS_ENABLE 1
#define STEERING_ENABLE 1	// defines MOTOR_ENABLE

// Debug messages
#define RUN_DEBUG 1
#define LOGING_DEBUG 0
#define LOGING_PRINT_DATA 1
#define LOGING_PRINT_SENSORS 1
#define LOGING_PRINT_RADIO 1
#define LOGING_PRINT_INFO 1
#define DUPLEX_DEBUG 0
#define SENSING_DEBUG 1
#define STEERING_DEBUG 0

#endif /* CONFIG_H_ */
