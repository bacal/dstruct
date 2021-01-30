/**
 * @file dyarray.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Dynamically allocated arrays prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the MIT License
 * 
 */
#ifndef DYARRAY_H
#define DYARRAY_H

/**
 * @brief Dynamic Array structure
 * 
 */
typedef struct dyarray_struct{
    int size; ///< Size of the array
    int count; ///< Number of elements in the array
    void** data; ///< An array of void* elements
}dyarray;

dyarray* dyarray_create(int size);
void dyarray_add(dyarray* array, void* data, size_t bytes);
void dyarray_remove(dyarray* array, int index);
void dyarray_delete(dyarray* array);


#endif /* DYARRAY_H */