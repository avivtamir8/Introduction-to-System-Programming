//
// Created by Amit on 18/04/2022.
//

#ifndef EX1_MTM_ASCIIARTTOOL_H
#define EX1_MTM_ASCIIARTTOOL_H

#include <stdio.h>
#include "RLEList.h"
/**
 * The following functions are available:
 * asciiArtRead              -Encode a document using RLE.
 * asciiArtPrint             -Makes a photo using a RLE list in a file.
 * asciiArtPrintEncoded      -Makes an encoded photo using RLE list in a file.
 */

/**
 * asciiArtRead: Creates a new RLE list from the picture provided.
 *
 * The function takes the file provided as input and compress is using functions from RLEList.
 *
 * @param in_stream - The file containing the picture to be compress.
 * @return A new RLE list in case of success.
 */
RLEList asciiArtRead(FILE* in_stream);

/**
 * asciiArtPrint: Prints into a file a new picture from a provided RLE list.
 *
 * The function receives a RLE list and with functions from RLEList creates a picture in the output file.
 *
 * @param list - RLE list containing nodes to be turned into a photo.
 * @param out_stream - The file to output the photo into.
 *
 * @return
 *          -RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters.
 *          -RLE_LIST_SUCCESS if the picture was encoded successfully.
 *
 *
 */
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

/**
 * asciiArtPrintEncoded: Encodes a RLE list into a photo.
 *
 * This function receives a RLE list and outputs an encoded photo into a desired file.
 *
 * @param list - RLE list to be encoded.
 * @param out_stream = The file to output the photo into.
 *
 * @return
 *          -RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters.
 *          -RLE_LIST_SUCCESS if the picture was encoded successfully.
 */
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif //EX1_MTM_ASCIIARTTOOL_H
