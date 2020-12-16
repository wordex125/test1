#include "USB_com.h"
#include <stdarg.h>

// TODO: try to get rid of delays

// formats the given float value to char array
// takes two digits after period of the fraction without proper rounding
// huh, do we want to round it properly?
// leave your vote in the comment section below!

bool formatFloat(float value, char* buffer){

    if(buffer == NULL){ return false; }

    // holds the pointer to the first element of the buffer
    char *tempPointer = buffer;
    if(value == 0) { 
        strcpy(buffer, "0"); 
        return true;
    }
    // if value < 0 we add '-' to the beginning
    // and move the beginning of the buffer one byte up
    // that way the rest of the program stays the same
    if(value < 0){ 
        *(tempPointer++) = '-'; 
        value = -value;
    }

    char intiger[8] = {'\0'};
    char fraction[4] = {'.'};
    
     itoa((int)value, intiger, 10);
     itoa(((int)(value * 100)) % 100, (fraction+1), 10);
     sprintf(tempPointer, "%s%s", intiger, fraction);
     return true;
}


// prints the given amount of Cstrings to the console
// arguments: number of Cstrings, Cstring1, Cstring2, ...
bool USBprint(int num, ...){

    va_list valist;
    va_start(valist, num);

    // craftes a message
    // "craft" sounds so nice, like craftsmanship
    // perhaps we should start saying cod crafting instead of programing
    char *buffer[128];
    for(int i=0; i<num; i++){
        strcat(buffer, va_arg(valist, char*));
    }
    va_end(valist);

    uint8_t len = strlen(buffer);
    CDC_Transmit_FS(buffer, len);
    HAL_Delay(len);
    return true;
}

// same as above, but in a new line
bool USBprintln(int num, ...){

    va_list valist;
    va_start(valist, num);

    char *buffer[128];
    buffer[0] = '\n';
    for(int i=0; i<num; i++){
        strcat(buffer, va_arg(valist, char*));
    }
    va_end(valist);

    uint8_t len = strlen(buffer);
    CDC_Transmit_FS(buffer, len);
    HAL_Delay(len);
    return true;
}

// prints the string pointed to by pointer
void print(char *pointer){
    uint8_t len = strlen(pointer);
    CDC_Transmit_FS(pointer, len);
    HAL_Delay(len);
}

// prints the string pointed to by pointer in a new line
void println(char *pointer){
    CDC_Transmit_FS("\n", 2);
    HAL_Delay(2);
    uint8_t len = strlen(pointer);
    CDC_Transmit_FS(pointer, len);
    HAL_Delay(len);
}




//**************** COMMENT SECTION THAT IS BELOW ****************//

//-> user Jacob says:
//      We have to think about that. It would give more accurate
//      data for an analysis later. It is not hard, might be done soon