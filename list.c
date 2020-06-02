#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct List { // create a "private" structure of the linked list
char *word; // it stores a word
struct List *next ; // it stores the next element in the linked list
};

struct List *head; // initialize the head of the linked list

int addWord(char *s) { // a function which takes a string as an input and 
	char *toAdd; // create a new variable to store the string input
	toAdd = malloc(strlen(s)+1); // allocate memory to it
	strcpy(toAdd,s); // copy the input string to the variable
    struct List *temp = head; // create another pointer pointing to the head
	
    if (head == NULL) { // if it's the first element
        head = (struct List *) malloc(sizeof(struct List)); // allocate the memory for it in the heap
		head->word = toAdd; // store the word
        head->next = NULL; // make the next word be null
        return 1; // return 1 on correct execution
    }
	
    else if (strcmp(head->word,s) > 0) { // if the head->word is greater than s lexicographically
        struct List *new = (struct List *) malloc(sizeof(struct List)); // allocate memory for the new word to be added
		new->word = toAdd;
        new->next = head;
        head = new; // make this new word the head
        return 1;
    }
    else { // if the head->word is less than s lexicographically
        while (head->next != NULL) { // loop through the words
            if (strcmp(head->next->word,s) < 0) {
                head = head->next; // move on to the next word
            }
            else { // if the word is in the right place, break out of the loop
                break;
            }
        }
        struct List *new = (struct List *) malloc(sizeof(struct List)); // allocate memory for the new word to be added
		new->word = toAdd;
        new->next = head->next; 
        head->next = new; // insert the new word in between head and head->next
        head = temp; // reset the pointer to the head
		
        return 1;
    }
}

void displayList() {
	// traverses through the linked list and prints out the words in the list to the screen
    struct List *temp = head;
    while (head != NULL) {
		printf("%s\n",head->word);
		head = head->next;
	}
}
