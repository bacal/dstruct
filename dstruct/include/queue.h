/**
 * @file queue.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Queue prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the GNU General Public License v3.0 or later
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Queue Structure
 * 
 */
typedef struct queue_struct{
    void** data;
    size_t size;
}queue;

/**
 * @brief Enqueue data to the queue
 * 
 * @param q The Queue that data will be added to
 * @param data The data that is being enqueued
 * @param bytes Size of the data in bytes
 */
void queue_enqueue(queue* q, void* data, size_t bytes);

/**
 * @brief Dequeue data from the queue
 * 
 * @param q The Queue that data will be removed from
 * @return void* Data that has been dequeued
 */
void* queue_dequeue(queue* q);

#endif /* QUEUE_H */