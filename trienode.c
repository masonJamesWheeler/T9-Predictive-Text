#include "Util.h"
#include <stdlib.h>
#include <stdio.h>
#include "trienode.h"

trieNode * makeNode() {
  trieNode * nodePointer = (trieNode *) mallocVerif(sizeof(trieNode));
  nodePointer->word = NULL;
  nodePointer->next = NULL;
  nodePointer->children = (trieNode **) malloc(BRANCHES * sizeof(trieNode *));
  int i;
  for (i = 0; i < BRANCHES; i++) {
    nodePointer->children[i] = NULL;
  }
  return nodePointer;
}
