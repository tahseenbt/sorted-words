#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" //use the list module

// Assumption made: the words are arranged in a lexicographical order

int main(int argc, char **argv) {
  FILE *file = fopen(argv[1], "r"); // open the file from the argument provided
  char a[100]; // initialize the variable a
  // if (file == NULL) return(0); // uncomment this to do data validation. it returns 0 if file is empty
while (fscanf(file,"%s\n",a) != EOF) { // keep taking input until end of file is reached
	addWord(a); // call the addWord function from the list module to add the word to the list
  }
   displayList(); // call the function from the list module to print the contents of the list
}
