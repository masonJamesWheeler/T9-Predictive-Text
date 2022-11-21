// Implementation the struct trieNode, which can be used as 'trieNode'.
// Allows for one instance of a trieNode

#include "Util.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

// initializes a trieNode with the following fields:
//   word = '\0'
//   children = pointer to 8 node pointers, each of which
//   reporesents a reference to a child node
trieNode * makeNode() {
  trieNode * nodePointer = (trieNode *) mallocVerif(sizeof(trieNode));
  nodePointer->word = NULL;
  nodePointer->next = NULL;
  nodePointer->children = (trieNode **) malloc(NUM_CHILDREN * sizeof(trieNode *));
  int i;
  for (i = 0; i < NUM_CHILDREN; i++) {
    nodePointer->children[i] = NULL;
  }
  return nodePointer;
}
