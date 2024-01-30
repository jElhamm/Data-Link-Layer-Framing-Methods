/**
  * The code provided consists of two functions within a class. Let's summarize the code in three lines:
  * The 'addByteCountFraming' function adds byte count framing to the given data
  * The 'removeByteCountFraming' function removes byte count framing from the received data:
**/



#include "framing.h"
#include <string.h>


// Function to add byte count framing to the data
void addByteCountFraming(char* data, int dataLength, char* framedData) {
    framedData[0] = (char)(dataLength & 0xFF);                                       // Stores the least significant byte
    framedData[1] = (char)((dataLength >> 8) & 0xFF);                                // Stores the most significant byte
    memcpy(framedData + 2, data, dataLength);                                        // Copies the data into framedData
}

// Function to remove byte count framing from the received data
int removeByteCountFraming(char* framedData, int framedDataLength, char* data) {
    if (framedDataLength < 2) {
        return -1;                                                                  // Error: Invalid frame length
    }
    int dataLength = (framedData[1] << 8) | framedData[0];                          // Retrieves the stored data length
    if (dataLength > MAX_FRAME_SIZE - 2 || framedDataLength != dataLength + 2) {
        return -1;                                                                  // Error: Invalid frame length or data length
    }
    memcpy(data, framedData + 2, dataLength);                                       // Copies the data into the data buffer
    return dataLength;                                                              // Returns the length of the extracted data
}