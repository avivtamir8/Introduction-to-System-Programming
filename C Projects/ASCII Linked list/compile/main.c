//
// Created by Amit on 19/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLEList.h"
#include "AsciiArtTool.h"

#define FLAG 1
#define SOURCE 2
#define TARGET 3

char mapFunction(char in){
    if (in == ' '){
        return '@';
    }
    if (in == '@'){
        return ' ';
    } else {
        return in;
    }
}

int main(int argc, char **argv) {
    FILE *out = fopen(argv[TARGET], "w");
    if (out == NULL) {
        return 0;
    }
    FILE *in = fopen(argv[SOURCE], "r");
    if (in == NULL) {
        fclose(out);
        return 0;
    }
    RLEList list = RLEListCreate();
    if (list == NULL){
        return 0;
    }
    RLEListResult result;
    list = asciiArtRead(in);
    if (strcmp(argv[FLAG], "-i") == 0) {
        RLEListMap((list,));
        result = asciiArtPrint(list, out);
    }
    if (strcmp(argv[FLAG], "-e") == 0) {
        result = asciiArtPrintEncoded(list, out);
    }
    RLEListDestroy(list);
    fclose(in);
    fclose(out);
    return 0;
}