// Simple implementation of a utility function
// to make sure that the memory that is allocated
// for the program isn't causing any memory leaks
#include "Util.h"

// Allocated 'size' memory to heap and verifies the result.
// If malloc fails, then program exits with error message.

void * mallocVerif(size_t size) {
  void * checker = malloc(size);
  if (!checker) {
    printf("Something is going very wrong, closing program");
    exit(EXIT_FAILURE);
  }
  return checker;
}
