
#ifndef NODE_H
#define NODE_H

#define NUM_CHILDREN 8


// It's a single node that stores pointers to children, a word,
// and a next node.
typedef struct trieNode {
  char * word;
  struct trieNode * next;
  struct trieNode ** children;
} trieNode;


// Initializes trie node with default fields:
// word, next, children[i] = NULL
trieNode * makeNode();

#endif
