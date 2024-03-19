#include <stdio.h>
#include "singly_linked_list_char.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define STRING_LENGTH 128

int main() {
    // timeval is a structure defined in <sys/time.h> for seconds and microseconds 
    struct timeval start, end;

    struct Node* list = NULL;

    double elapsed_time;
    int i, j;

    srand(time(NULL)); // initialize the random number generator with the seed of the time 

    gettimeofday(&start, NULL); // start clock

    for (i = 0; i < 100000; i++) {
        char random_string[STRING_LENGTH +1]; // +1 for null terminator 

        for(j = 0; j < STRING_LENGTH ; j++) {
            random_string[j] = 'a' + (rand() % 26);
        } 
        random_string[STRING_LENGTH] = '\0'; // add the null terminator   

        pushFront(&list, random_string); 
    }

    gettimeofday(&end, NULL); // end clock 

    printList(list);

    

    // Calculate the elapsed time in microseconds. It adds the seconds to the microseconds.
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printf("Time taken: %f microseconds\n", elapsed_time);
    printf("Time taken: %f seconds\n", elapsed_time / 1000000.0);

    return 0;
}



/*

int main() {
    struct Node* newListHead = NULL;

    pushFront(&newListHead, "1 Peru");
    pushFront(&newListHead, "2 Albania");
    pushFront(&newListHead, "3 England");
    pushFront(&newListHead, "4 New Zealand");
    pushFront(&newListHead, "5 Germany");
    pushFront(&newListHead, "6 Thailand");

    printf("\n");
    printList(newListHead);
    // append(&newListHead, "APPEND");
    // printList(newListHead);
    // pushFront(&newListHead, "PREPEND");
    // printList(newListHead);

    char* poppedItem1 = popFront(&newListHead); // assign the result of popFront() to a variable
    printf("%s\n", poppedItem1); // print the popped item

    char* poppedItem2 = popFront(&newListHead); // assign the result of popFront() to a variable
    printf("%s\n", poppedItem2); // print the popped item

    char* poppedItem3 = popFront(&newListHead); // assign the result of popFront() to a variable
    printf("%s\n", poppedItem3); // print the popped item
   
    return 0;
}



*/



