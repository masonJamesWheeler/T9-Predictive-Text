# Makefile for t9 Trie program
# CSE 374
# HW 5
#


trie: Util.o trienode.o trie.o tnine.o 
	gcc -Wall -g -std=c11 -o t9 Util.o trie.o trienode.o tnine.o

Util.o: Util.c Util.h
	gcc -Wall -g -std=c11 -c Util.c

trie.o: trie.c trienode.h Util.h
	gcc -Wall -g -std=c11 -c trie.c

tnine.o: tnine.c trienode.h Util.h
	gcc -Wall -g -std=c11 -c tnine.c

clean: 
	rm -f *.o trie 
