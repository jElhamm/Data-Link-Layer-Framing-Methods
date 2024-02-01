// This code is a C program that uses the 'byte_stuffing.h' header file 
// to perform byte stuffing and byte unstuffing operations on user input.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "byte_stuffing.h"


int main() {
    char input[100];
    char stuffed[200];
    char unstuffed[100];
    int inputLen, stuffedLen, unstuffedLen;
    printf("****************************************************");
    printf("---> Enter data to be framed: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from input
    inputLen = strlen(input);
    if (input[inputLen - 1] == '\n') {
        input[inputLen - 1] = '\0';
        inputLen--;
    }
    // Perform byte stuffing
    stuffedLen = byteStuffing(input, inputLen, stuffed);
    printf("\n---> Stuffed data: ");
    for (int i = 0; i < stuffedLen; i++) {
        printf("%02X ", (unsigned char)stuffed[i]);
    }
    // Perform byte unstuffing
    unstuffedLen = byteUnstuffing(stuffed, stuffedLen, unstuffed);
    printf("\n---> Unstuffed data: %s\n", unstuffed);
    printf("********************************************************\n"); 
    return 0;
}