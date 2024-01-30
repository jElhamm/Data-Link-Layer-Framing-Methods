/**
  * the program checks if the received data length is -1, indicating an error in the framed data. 
  * If there is no error, the received data is printed.
**/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "framing.h"


int main() {
    char data[MAX_FRAME_SIZE];                                          // Buffer to hold input data
    char framedData[MAX_FRAME_SIZE + 2];                                // Buffer to hold framed data
    printf("\n********************************************************"); 
    printf("---> Enter data: ");                                        // Prompting user for input
    fgets(data, sizeof(data), stdin);                                   // Reading user input
    int dataLength = strlen(data) - 1;                                  // Excluding newline character
    addByteCountFraming(data, dataLength, framedData);                  // Adding byte count framing to the data
    printf("---> Framed data: ");
    for (int i = 0; i < dataLength + 2; ++i) {
        printf("%02X ", (unsigned char)framedData[i]);                  // Printing framed data in hexadecimal format
    }
    printf("\n");
    char receivedData[MAX_FRAME_SIZE];                                  // Buffer to hold received data
    int receivedDataLength = removeByteCountFraming(framedData, dataLength + 2, receivedData);
    if (receivedDataLength == -1) {
        printf("  (  ! Error: Invalid framed data !  )\n");
    } else {
        printf("---> Received data: %s\n", receivedData);               // Printing the received data
    }
    printf("********************************************************\n"); 
    return 0;
}