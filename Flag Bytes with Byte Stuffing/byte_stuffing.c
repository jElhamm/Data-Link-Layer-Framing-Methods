/** Byte stuffing is a process of adding an escape character before certain predefined bytes in a byte stream.
  * In this code, the byteStuffing function takes an input byte array (input), its length (inputLen), and an output byte array (output). 
  * It iterates over each byte in the input array and checks if it is equal to a FLAG_BYTE or ESCAPE_BYTE. 
  * If it matches, it adds an ESCAPE_BYTE before the byte in the output array. Finally, it returns the length of the output array.
  **/



#include <stdio.h>
#include "byte_stuffing.h"


// Function to perform byte stuffing
int byteStuffing(const char* input, int inputLen, char* output) {
    int i, j;
    j = 0;
    for (i = 0; i < inputLen; i++) {
        // If input byte is FLAG_BYTE or ESCAPE_BYTE, add an ESCAPE_BYTE before it
        if (input[i] == FLAG_BYTE || input[i] == ESCAPE_BYTE) {
            output[j++] = ESCAPE_BYTE;
        }
        output[j++] = input[i];
    }
    return j;
}

// Function to perform byte unstuffing
int byteUnstuffing(const char* input, int inputLen, char* output) {
    int i, j;
    j = 0;
    for (i = 0; i < inputLen; i++) {
        // If input byte is ESCAPE_BYTE, skip it and take the next byte as is
        if (input[i] == ESCAPE_BYTE) {
            i++;
        }
        output[j++] = input[i];
    }
    return j;
}