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
 