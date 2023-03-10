/**
@file stack.c

See header

@author Justin Hadella (pitchnogle@gmail.com)
*/

#include "stack.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Stack Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int stack_push(Stack *stack, const void *data)
{
  return list_insert_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data)
{
  return list_remove_next(stack, NULL, data);
}
