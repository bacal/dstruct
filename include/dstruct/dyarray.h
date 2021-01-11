#ifndef DYARRAY_H
#define DYARRAY_H


typedef struct dyarray_struct{
    int size;
    int count;
    void** data;
}dyarray;

dyarray* dyarray_create(int size);
void dyarray_add(dyarray* array, void* data, size_t bytes);
void dyarray_remove(dyarray* array, int index);
void dyarray_erase(dyarray* array);


#endif /* DYARRAY_H */