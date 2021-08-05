/**
 * @file dyarray.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Dynamically allocated arrays prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the GNU General Public License v3.0 or later
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

/**
 * @brief Creates a dynamic array 
 * 
 * @param size Inital size of the array
 * @return dyarray* Pointer to the dyarray struct 
 */
dyarray* dyarray_create(int size);

/**
 * @brief Adds data to your Dynamic Array
 * 
 * @param array The array in which data will be added to
 * @param data The data to be added to the array
 * @param bytes The size of the data to be added in bytes
 */
void dyarray_add(dyarray* array, void* data, size_t bytes);

/**
 * @brief Removes data from your Dynamic Array
 * 
 * @param array The array in which data will be removed from
 * @param index The place in which the data will be deleted
 */
void dyarray_remove(dyarray* array, int index);

/**
 * @brief Gets data from a Dynamic Array at the position of (int index)
 * 
 * @param array The Dynamic Array from which data will be returned
 * @param index The place in the Dynamic Array in which the data is located
 * 
 * @return void* Data from the Dynamic Array 
 */
void* dyarray_get(dyarray* array, int index);

/**
 * @brief Delete's the entire Dynamic Array
 * 
 * @param array The Dynamic Array which is to be deleted
 */
void dyarray_delete(dyarray* array);



#endif /* DYARRAY_H */