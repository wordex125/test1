#ifndef _USB_COM_
#define _USB_COM_

#include "usbd_cdc_if.h"
#include "bmp280.h"
#include <string.h>
#include <stdio.h>

// turns float into array of chars
bool formatFloat(float value, char *buffer);

// prints the num amount of strings
bool USBprint(int num, ...);

// prints the num amount of strings in new line
bool USBprintln(int num, ...);

// prints one string
void print(char *pointer);

// prints one string in a new line
void println(char *pointer);


#endif // _USB_COM_ //