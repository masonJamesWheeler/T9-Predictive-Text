
#include "Util.h"
#include "trienode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

trieNode * get_word(char * keySeq, trieNode * root) {
  trieNode * current = root;
  int len = strlen(keySeq) - 1;
  int i = 0;

  while (i < len && current && keySeq[i] != '#') {
    int childIndex = keySeq[i] - '0' - 2;
    if (childIndex < 0 || !isdigit(keySeq[i])) {
      return NULL;
    }
    current = current->children[childIndex];
    i++;
  }
  return current;
}

void insert(trieNode * root, char * word) {
  trieNode * current = root;
  int wordIndex = 0;


  while (*(word + wordIndex)) {
    char letter = word[wordIndex];
    int childIndex = getChildIndex(letter);

    trieNode * child = current->children[childIndex];
   
    if (!child) {
      child = makeNode();
      current->children[childIndex] = child;
    }
    current = child;
    wordIndex++;
  }

  if (current->word) {
    trieNode * temp = current;
    while (temp && temp->next) {
      temp = temp->next;
    }
    trieNode * newNode = makeNode();
    temp->next = newNode;
    current = newNode;
  }
  int len = wordIndex + 1;

  current->word = (char *) mallocVerif(len);
  strncpy(current->word, word, len);
}


trieNode * build_tree(FILE * fp) {
  char * word;
  trieNode * root;

  word = (char *) mallocVerif(MAXLEN);
  root = makeNode();

  while (fgets(word, MAXLEN, fp)) {
    int len = strlen(word);
  
    if (word[len - 1] == '\n') {
      word[len - 1] = '\0';
    }
    insert(root, word);
  }
  free(word);
  return root;
}


int getChildIndex(char letter) {
  int chMap[NUM_ALPHABET] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7, 7,
    8, 8, 8,
    9, 9, 9, 9
  };
  int i = letter - 'a';

  return chMap[i] - 2;
}

void free_tree(trieNode * root) {
  if (root) {
    int i;
    for (i = 0; i < BRANCHES; i++) {
      free_tree(root->children[i]);
    }
    freeList(root->next);
    freeNode(root);
  }
}


void freeList(trieNode * front) {
  while (front) {
    trieNode * next = front->next;
    freeNode(front);
    front = next;
  }
}

void freeNode(trieNode * node) {
  free(node->word);
  free(node->children);
  free(node);
}

void printTrie(trieNode * root, int level) {
  if (root) {
    if (root->word != NULL) {
      printTabs(level);
      trieNode * temp = root;
      printf("word = ");
      while (temp) {
        printf("%s -> ", temp->word);
        temp = temp->next;
      }
      printf("NULL\n");
    }
    int i;
    for (i = 0; i < BRANCHES; i++) {
      trieNode * child = root->children[i];
      if (child != NULL) {
        printTabs(level);
        printf("key=%d, index=%d, level=%d : \n", i + 2, i, level);
        printTrie(child, level + 1);
      }
    }
  }
}

void printTabs(int numTabs) {
  int i;
  for (i = 0; i < numTabs; i++) {
    printf("\t");
  }
}
