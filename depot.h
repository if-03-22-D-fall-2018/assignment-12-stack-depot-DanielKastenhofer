#ifndef __DEPOT_H
#define __DEPOT_H
#include "stack.h"

#define STACK_SIZE 3

typedef struct DepotImplementation* Depot;

struct Product{
  int serial_no;
};

Depot create_depot();
void delete_depot(Depot depot);
int get_count(Depot depot);
void 	push_depot(Depot depot, Product *product);
Product* pop_depot(Depot depot);

#endif
