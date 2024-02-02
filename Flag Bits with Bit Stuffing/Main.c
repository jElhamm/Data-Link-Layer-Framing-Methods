// This main.c file includes necessary headers, declares arrays for input, stuffed, and destuffed messages, and defines the main function.



#include <stdio.h>
#include <string.h>
#include "bit_operations.h"


int main() {
    char input[100];                                                // Array to store the user input message
    char stuffed[200];                                              // Array to hold the stuffed message (with extra bits)
    char destuffed[100];                                            // Array to hold the destuffed message (original message)
    printf("******************************************************************");
    printf("---> Enter a message to stuff: ");
    gets(input);                                                    // Allowing user to input a message
    bit_stuffing(input, stuffed);                            // Performing bit stuffing on the input message
    printf("\n---> Stuffed message: %s\n", stuffed);                // Displaying the stuffed message
    bit_destuffing(stuffed, destuffed);               // Performing bit destuffing on the stuffed message
    printf("\n---> Destuffed message: %s\n", destuffed);            // Displaying the destuffed message
    printf("******************************************************************");
    return 0;
}