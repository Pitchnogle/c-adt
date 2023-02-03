/** 
@file queue.h
@brief 
Definitions of a generic queue ADT

@note
Code based on content from "Mastering Algorithms with C" (O'Reilly 1999)

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef QUEUE_h
#define QUEUE_h

#include <stdlib.h>

#include "list.h"

#ifdef __cplusplus
extern "C"
{
#endif

// -------------------------------------------------------------------------------------------------
// Definitions
// -------------------------------------------------------------------------------------------------

typedef List Queue;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Queue Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
MACRO to init the queue. Functionally same as *list_init*
*/
#define queue_init list_init

/**
MACRO to destroy the queue. Functionally same as *list_destroy*
*/
#define queue_destroy list_destroy

/**
Function to add an element to the end of the queue

@note
The queue is implemented internally as a linked-list, so an enqueue is equivalent to
`list_insert_next()` where the element is added to the tail of the list

@param [in,out] *queue  The queue to add element to
@param [in]     *data   The data to enqueue

@return 0 if enqueue operation was successful, otherwise -1
*/
int queue_enqueue(Queue *queue, const void *data);

/**
Function to remove an element from the front of a queue

@note
The queue is implemented internally as a linked-list, so a dequeue is equivalent to
`list_remove_next()` where the element is removed from the head of the list

@param [in,out] *queue  The queue to remove element from
@param [in]     **data  The dequeued data

@return 0 if dequeue operation was successful, otherwise -1
*/
int queue_dequeue(Queue *queue, void **data);

/**
MACRO that provides mechanism to inspect the element at front of queue
*/
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

/**
MACRO that evaluates to the number of elements in the queue
*/
#define queue_size list_size

#ifdef __cplusplus
}
#endif
#endif // QUEUE_h
