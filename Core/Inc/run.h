#ifndef _RUN_H_
#define _RUN_H_

#include "main.h"

#include "usbd_cdc_if.h"
#include <stdlib.h>
#include <string.h>

#include "bmp280.h"
#include "config.h"

// this struct will hold all data about sensors
// its point is to be able to quickly change individual
// sensor structs just by changing a pointer
// kind of like "common" last year
// might evolve into something similar later on
// we can create multiple instances of BMP, IMU etc structs
// the ones in use will be located in the sensor struct
struct {
    BMP280 *bmp1;
    BMP280_config *bmpConfig;
} sensor;

// BMP280 struct no.1
BMP280 bmp1;

void setup(void);
void loop(void);

#endif // _RUN_H_
