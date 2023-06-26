//
// Created by Amit on 18/04/2022.
//

#include "AsciiArtTool.h"
#include "RLEList.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 256

RLEList asciiArtRead(FILE* in_stream) {
    RLEList list = RLEListCreate();
    if (list == NULL || in_stream == NULL) {
        return NULL;
    }
    char buffer[CHUNK];
    while (fgets(buffer, CHUNK, in_stream) != NULL){
        for (int i = 0; i < CHUNK; ++i) {
            if (buffer[i] == EOF || buffer[i] == '\0') {
                break;
            }
            if (RLEListAppend(list, buffer[i]) != RLE_LIST_SUCCESS) {
                RLEListDestroy(list);
                return NULL;
            }
        }
    }
    return list;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream){
    if (list == NULL || out_stream == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    int i = 0;
    RLEListResult* result = (RLEListResult*) malloc(sizeof(*result));
    if (result == NULL){
        return RLE_LIST_OUT_OF_MEMORY;
    }
    *result = RLE_LIST_SUCCESS;
    while (*result != RLE_LIST_SUCCESS){
        if (fputc(RLEListGet(list, i, result),out_stream) == EOF){
            return RLE_LIST_ERROR;
        }
        if (*result == RLE_LIST_NULL_ARGUMENT){
            return RLE_LIST_NULL_ARGUMENT;
        }
        if (*result == RLE_LIST_OUT_OF_MEMORY){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        i++;
    }
    return RLE_LIST_SUCCESS;
}


RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream){
    if (list == NULL || out_stream == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEListResult* result = (RLEListResult*) malloc(sizeof(RLEListResult));
    if (result == NULL){
        return RLE_LIST_OUT_OF_MEMORY;
    }
    char* str = RLEListExportToString(list, result);
    if (str == NULL){
        free(result);
        return RLE_LIST_ERROR;
    }
    if (*result != RLE_LIST_SUCCESS){
        free(result);
        free(str);
        return RLE_LIST_ERROR;
    }
    fprintf(out_stream, "%s\n", str);
    free(result);
    free(str);
    return RLE_LIST_SUCCESS;
}



