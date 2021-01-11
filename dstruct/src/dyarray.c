#include <stdlib.h>
#include <string.h>
#include "dyarray.h"


dyarray* dyarray_create(int size)
{
    dyarray* array = malloc(sizeof(struct dyarray_struct));
    array->data = malloc(size* sizeof(dyarray));
    array->size = size;
    array->count = 0;
}
void dyarray_add(dyarray* array, void* data, size_t bytes)
{
    if(array->count == array->size){
        realloc(array->data,array->size+10);
        array->size+=10;
    }
    array->data[array->count] = malloc(bytes);
    memcpy(array->data[array->count],data,bytes);
}
void dyarray_remove(dyarray* array, int index)
{
    
}
void dyarray_erase(dyarray* array)
{

}