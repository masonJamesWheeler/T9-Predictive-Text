/* tnine is a program that drives a trie / t9 program.  This code
   will build a trie, according to trienode.  It will also run
   an interactive session where the user can retrieve words using
   t9 sequences.
   CSE374, HW5, 22wi 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Util.h"
#include "trienode.h"

void run_session(trieNode *wordTrie);

int main(int argc, char * argv[]) {
  FILE *dictionary = NULL;
  trieNode *wordTrie = NULL;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s [DICTIONARY]\n", argv[0]);
    return EXIT_FAILURE;
  } else {
    FILE * dictionary = fopen(argv[1], "r");
    if (!dictionary) {
      fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
      return EXIT_FAILURE;
    }
  }

  trieNode * root = build_tree(dictionary);
  fclose(dictionary);
  char * input = (char *) mallocVerif(MAXLEN);
  trieNode * currWord = NULL;

  printf("Enter \"exit\" to quit.\n");
  printf("Enter Key Sequence (or \"#\" for next word):\n");

  while (fgets(input, MAXLEN, stdin) &&
         strncmp("exit\n", input, strlen(input))) {

    // filter out first letter: # possibilities
    if (isdigit(input[0])) {
      currWord = get_word(input, root);
    }
    char * poundPtr = strstr(input, "#");
    while (poundPtr && *poundPtr == '#' && currWord) {
      currWord = currWord->next;
      poundPtr++;
    }
    if (currWord && currWord->word) {
      printf("        '%s'\n", currWord->word);
    } else {
      printf("        There are no more T9onyms\n");
    }
    printf("Enter Key Sequence (or \"#\" for next word):\n");
  }

  free(input);
  free_tree(root);
  return 0;
}
