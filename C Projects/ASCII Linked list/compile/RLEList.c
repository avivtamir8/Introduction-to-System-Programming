#include "RLEList.h"
#include <stdlib.h>
#include <string.h>
#define BASE 10

struct RLEList_t {
    int timesInARow;
    char letter;
    struct RLEList_t* next;
};

char* itoa(int num, char* str){
    int i = 0;
    while (num != 0){
        int remaining = num % BASE;
        str[i++] = (remaining > 9)? (remaining-10) + 'a' : remaining + '0';
        num = num/BASE;
    }
    return str;
}

RLEList createNode(int times, char letter, RLEList next){
    RLEList newNode = (RLEList) malloc(sizeof (*newNode));
    if (newNode == NULL){
        return NULL;
    }

    newNode->timesInARow = times;
    newNode->letter = letter;
    newNode->next = next;
    return newNode;
}

int countNodes(RLEList list)
{
    if (list == NULL)
    {
        return 0;
    }
    int count = 0;
    while (list->next !=NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}

RLEList RLEListCreate(){
    RLEList node = createNode(0,0,NULL);
    if (node == NULL){
        return NULL;
    }
    return node;
}

void RLEListDestroy(RLEList list)
{
    if (list == NULL)
    {
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
    if (list->letter == value){
        list->timesInARow++;
        return RLE_LIST_SUCCESS;
    } else {
        RLEList newNode = createNode(1,value,NULL);
        if (newNode == NULL)
        {
            return RLE_LIST_OUT_OF_MEMORY;
        }
        list->next = newNode;
        return RLE_LIST_SUCCESS;
    }
}

int RLEListSize(RLEList list){
    if (list == NULL){
        return  -1;
    }
    int totalCharacters = 0;
    while (list != NULL){
        totalCharacters += list->timesInARow;
        list = list->next;
        }
    return totalCharacters;
}

RLEListResult RLEListRemove(RLEList list, int index){
    if (list == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList placeHolder = malloc(sizeof(*placeHolder));
    if (placeHolder == NULL){
        return RLE_LIST_OUT_OF_MEMORY;
    }
    placeHolder = list->next;
    while (list->next != NULL){
        for (int i = 0; i < list->timesInARow ;i++){
            if (index == 0){
                if (list->timesInARow > 1){//if timeInARow > 1
                    list->timesInARow--;
                    return RLE_LIST_SUCCESS;
                }
                else if (list->timesInARow == 1){ //if timesInARow = 1
                        if ((list->next)->letter != placeHolder->letter){//if there is no need to connect after deleting
                            list = placeHolder;
                            placeHolder = list->next;
                            list->next = (list->next)->next;
                            free(placeHolder);
                            return RLE_LIST_SUCCESS;
                        }
                        if ((list->next)->letter == placeHolder->letter){//if there is a need to connect after deleting
                            list = placeHolder;
                            placeHolder = list->next;
                            list->timesInARow += ((list->next)->next)->timesInARow;
                            list->next = ((list->next)->next)->next;
                            free((placeHolder->next));
                            free(placeHolder);
                            return RLE_LIST_SUCCESS;
                        }
                    }
            }
            index--;
        }
        placeHolder = list;
        list = list->next;
    }
    return RLE_LIST_INDEX_OUT_OF_BOUNDS;
}

char RLEListGet(RLEList list, int index, RLEListResult* result){
    if (list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
        return 0;
    }
    while (list != NULL){
        for (int i=0; i < list->timesInARow; i++){
            if (index == 0){
                *result = RLE_LIST_SUCCESS;
                return list->letter;
            }
            index--;
        }
        list = list->next;
    }
    *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    return 0;
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    if (list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    char* str = (char*) malloc(countNodes(list)*3 + 1);
    if (!str){
        *result = RLE_LIST_OUT_OF_MEMORY;
        return NULL;
    }
    char* ptr = str;
    while (list !=NULL){
        if (list->timesInARow == 0){
            list = list->next;
            continue;
        }
        *str = list->letter;
        str++;
        str = itoa(list->timesInARow , str);
        str++;
        strcat(str, "\n");
        str++;
        list = list->next;
    }
    return ptr;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if (list == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    while (list != NULL) {
        for (int i = 0; i < list->timesInARow; ++i) {
            list->letter = map_function(list->letter);
        }
        list = list->next;
    }
    return RLE_LIST_SUCCESS;
}
