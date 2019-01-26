#include "depot.h"
#include <stdlib.h>

struct DepotImplementation{
  Stack stack_of_stacks;
};

Depot create_depot()
{
  Depot depot = (Depot)smalloc(sizeof(DepotImplementation));
  depot->stack_of_stacks = create_stack();
  return depot;
}

void delete_depot(Depot depot)
{
  while (get_count(depot->stack_of_stacks) != 0) {
    delete_stack((Stack) pop_stack(depot->stack_of_stacks));
  }
  sfree(depot->stack_of_stacks);
  sfree(depot);
}

int get_count(Depot depot)
{
  return get_count(depot->stack_of_stacks);
}

static void _add_to_new_stack(Depot depot, Product *product);
void 	push_depot(Depot depot, Product *product)
{
  if (get_count(depot->stack_of_stacks) == 0) {
    _add_to_new_stack(depot, product);
    return;
  }
  Stack curr_stack = (Stack)peek_stack(depot->stack_of_stacks);
  if (get_count(curr_stack) == STACK_SIZE) {
    _add_to_new_stack(depot, product);
    return;
  }
  push_stack(curr_stack, product);
}

static void _add_to_new_stack(Depot depot, Product *product)
{
  Stack new_stack = create_stack();
  push_stack(new_stack, product);
  push_stack(depot->stack_of_stacks, new_stack);
}

Product* pop_depot(Depot depot)
{
  if (get_count(depot->stack_of_stacks) == 0) return 0;
  Stack curr_stack = (Stack) peek_stack(depot->stack_of_stacks);
  if (get_count(curr_stack) == 1) {
    curr_stack = (Stack) pop_stack(depot->stack_of_stacks);
    Product *product = (Product*) pop_stack(curr_stack);
    delete_stack(curr_stack);
    return product;
  }
  return(Product*) pop_stack(curr_stack);
}
