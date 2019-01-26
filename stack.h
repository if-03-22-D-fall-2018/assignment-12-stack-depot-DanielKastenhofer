#include "memcheck.h"
#ifndef __STACK_H
#define __STACK_H



typedef struct StackImplementation* Stack;

Stack create_stack ();
void delete_stack(Stack stack);
void push_stack (Stack stack, void* data);
int get_count(Stack stack);
void* pop_stack (Stack stack);
void* peek_stack (Stack stack);

#endif
