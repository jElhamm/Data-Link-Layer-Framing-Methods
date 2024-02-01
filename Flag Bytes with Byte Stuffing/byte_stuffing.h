// This code is a header file (byte_stuffing.h) that defines the constants 
// and function prototypes for byte stuffing and byte unstuffing.



#ifndef BYTE_STUFFING_H
#define BYTE_STUFFING_H
#define FLAG_BYTE 0x7E
#define ESCAPE_BYTE 0x7D

int byteStuffing(const char* input, int inputLen, char* output);
int byteUnstuffing(const char* input, int inputLen, char* output);

#endif



/**
  * The 'byteStuffing' function prototype declares a function that performs byte stuffing. 
  * It takes an input byte array (input), its length (inputLen), and an output byte array (output).
  * The function returns an integer representing the length of the output array.
 
  * The byteUnstuffing function prototype declares a function that performs byte unstuffing.
  * It takes the input byte array (input), its length (inputLen), and an output byte array (output).
  * The function returns an integer representing the length of the output array.
 **/