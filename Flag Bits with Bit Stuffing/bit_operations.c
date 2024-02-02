/**
  * These functions implement a simple form of bit stuffing where bytes that
  * match the FLAG or ESCAPE values are escaped and XOR'ed with 0x20.
  * The bit_stuffing function adds flag bytes at the beginning and end of the output,
  * and the bit_destuffing function reverses these operations.
**/




#include <stdio.h>
#include <string.h>
#define FLAG 0x7E
#define ESCAPE 0x7D
#define XOR 0x20


// The bit_stuffing function surrounds the output with flag bytes and escapes necessary characters.
void bit_stuffing(char *input, char *output) {
    int count = 0;
    *output++ = FLAG;                                   // Add start flag
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == FLAG || input[i] == ESCAPE) {
            *output++ = ESCAPE;                         // Handle ESCAPE character
            *output++ = input[i] ^ XOR;                 // XOR'ed with 0x20
            count += 2;                                 // Increase the count by 2 for each stuffed byte
        } else {
            *output++ = input[i];                       // Copy the byte as it is
            count++;
        }
    }
    *output++ = FLAG;                                   // Add end flag
    *output = '\0';                                     // Add null terminator at the end of the output
    printf("Number of stuffed bits: %d\n", count);
}
 