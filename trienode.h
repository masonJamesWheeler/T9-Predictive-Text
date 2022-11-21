// CSE 374
// HW 5
// Mason Wheeler
//
// Trie.h:
// Interface to trie data structure. Trie here is a variation
// of tree where each node contains 8 children

#ifndef TRIENODE_H
#define TRIENODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXLEN 50
#define NUM_ALPHABET 26
#define BRANCHES 9

typedef struct trieNode {
  char * word;
  struct trieNode * next;
  struct trieNode ** children;
    struct trieNode *branches[BRANCHES];
} trieNode;


// Initializes trie node with default fields:
// word, next, children[i] = NULL
trieNode * makeNode();


void insert(trieNode * root, char * word);

trieNode * build_tree(FILE * fp);

trieNode * get_word(char * keySeq, trieNode * root);

int getChildIndex(char letter);


void free_tree(trieNode * node);


void freeList(trieNode * front);


void freeNode(trieNode * node);


void printTrie(trieNode * root, int level);


void printTabs(int numTabs);

#endif
