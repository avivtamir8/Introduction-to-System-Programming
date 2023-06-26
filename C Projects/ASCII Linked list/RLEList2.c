#include "RLEList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RLEList_t {
    int timesInARow;
    char letter;
    struct RLEList_t* next;
};

RLEList RLEListCreate(){
    RLEList dummy = malloc(sizeof (*dummy));
    if (dummy == NULL){
        return NULL;
    }
    RLEList firstNode = malloc(sizeof (*dummy));
    if (firstNode == NULL){
        return NULL;
    }
    dummy->next = firstNode;
    dummy->timesInARow = 0;
    firstNode->next = NULL;
    return dummy;
}

void RLEListDestroy(RLEList list){
    if (list->next == NULL)
    {
        free (list);
        return;
    }
    RLEListDestroy(list->next);
    free(list);
}

RLEListResult RLEListAppend(RLEList list, char value){
    if (list == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while (list->next != NULL){
        list = list->next;
    }
    if (value == list->letter){
        list->timesInARow++;
        return RLE_LIST_SUCCESS;
    }
    else {
        RLEList newNode = malloc(sizeof (*newNode));
        if (newNode == NULL){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        list->next = newNode;
        newNode->next = NULL;
        newNode->timesInARow = 1;
        newNode->next = NULL;
        return RLE_LIST_SUCCESS;
    }
}

int RLEListSize(RLEList list){
    if (list == NULL){
        return -1;
    }
    int length = 0;
    while (list->next != NULL){
        while(list->timesInARow > 0){
            length++;
            list->timesInARow--;
        }
        list = list->next;
    }
    return length;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result){
    if (list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
        return 0;
    }
    while (list->next != NULL){
        while (list->timesInARow > 0){
            if (index == 0){
                *result = RLE_LIST_SUCCESS;
                return list->letter;
            }
            index --;
        }
    }
    *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    return 0;
}

char* RLEListExportToString(RLEList list, RLEListResult* result){
    if (list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    char* str = malloc(RLEListSize(list)*5 + 1);
    char* strStart = str;
    if (str == NULL){
        *result = RLE_LIST_OUT_OF_MEMORY;
        return NULL;
    }
    while (list->next != NULL){
        *str = list->letter;
        str++;
        sprintf(str ,"%d" ,list->timesInARow);
        str++;
        strcat(str ,"\n");
    }
    *result = RLE_LIST_SUCCESS;
    return strStart;
}
/*
RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if (list == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while (list->next != NULL) {
        char value = list->letter;
        char newValue = map_function(value);
        list = list->next;
    }
    return RLE_LIST_SUCCESS;
}
*/










