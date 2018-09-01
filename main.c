#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX 7

int intArray[MAX];


void swap(int a, int b){
    int temp;
    temp=intArray[a];
    intArray[a]=intArray[b];
    intArray[b]=temp;
}


void printline() {
    int i;
    for(i = 0;i < 50;i++)
        printf("#");
    printf("\n");
}

void display() {
    int i;
    printf("[ ");

    for(i = 0;i< MAX;i++) {
        printf("%d ",intArray[i]);
    }

    printf("]\n");
}

void selectionSort() {
    int indexMin,i,j;

    // loop through all numbers
    for(i = 0; i < MAX-1; i++) {

        // set current element as minimum
        indexMin = i;

        // check the element to be minimum
        for(j = i+1;j < MAX;j++) {
            if(intArray[j] < intArray[indexMin]) {
                indexMin = j;
            }
        }

        if(indexMin != i) {
            printf("Items swapped: [ %d, %d ]\n" , intArray[i], intArray[indexMin]);

            // swap the numbers
            int temp = intArray[indexMin];
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }

        printf("Iteration %d#:",(i+1));
        display();
    }
}

void insertionSort(){
    int i;
    int valueToInsert;
    int holePosition;


    // loop through all numbers
    for(i = 1; i < MAX; i++) {

        // select a value to be inserted.
        valueToInsert = intArray[i];

        // select the hole position where number is to be inserted
        holePosition = i;

        // check if previous no. is larger than value to be inserted
        while (holePosition > 0 && intArray[holePosition-1] > valueToInsert) {
            intArray[holePosition] = intArray[holePosition-1];
            holePosition--;
            printf(" item moved : %d\n" , intArray[holePosition]);
        }

        if(holePosition != i) {
            printf(" item inserted : %d, at position : %d\n" , valueToInsert,holePosition);
            // insert the number at hole position
            intArray[holePosition] = valueToInsert;
        }

        printf("Iteration %d#:",i);
        display();

    }
}


void bubbleSort() {
    int temp;
    int i,j;

    _Bool swapped;

    // loop through all numbers
    for(i = 0; i < MAX-1; i++) {
        swapped = false;

        // loop through numbers falling ahead
        for(j = 0; j < MAX-1-i; j++) {
            printf("     Items compared: [ %d, %d ] ", intArray[j],intArray[j+1]);

            // check if next number is lesser than current no
            //   swap the numbers.
            //  (Bubble up the highest number)

            if(intArray[j] > intArray[j+1]) {
                temp = intArray[j];
                intArray[j] = intArray[j+1];
                intArray[j+1] = temp;

                swapped = true;
                printf(" => swapped [%d, %d]\n",intArray[j],intArray[j+1]);
            } else {
                printf(" => not swapped\n");
            }

        }

        // if no number was swapped that means
        //   array is sorted now, break the loop.
        if(!swapped) {
            break;
        }

        printf("Iteration %d#: ",(i+1));
        display();
    }

}


int partition(int left, int right, int pivot) {
    int leftPointer = left -1;
    int rightPointer = right;

    while(1==1) {
        while(intArray[++leftPointer] < pivot) {
            //do nothing
        }

        while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
            //do nothing
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            printf(" item swapped :%d,%d\n", intArray[leftPointer],intArray[rightPointer]);
            swap(leftPointer,rightPointer);
        }
    }

    printf(" pivot swapped :%d,%d\n", intArray[leftPointer],intArray[right]);
    swap(leftPointer,right);
    printf("Updated Array: ");
    display();
    return leftPointer;
}

void quickSortImpl(int left, int right) {
    if(right-left <= 0) {
        return;
    } else {
        int pivot = intArray[right];
        int partitionPoint = partition(left, right, pivot);
        quickSortImpl(left,partitionPoint-1);
        quickSortImpl(partitionPoint+1,right);
    }
}

void quickSort(){
    quickSortImpl(0, MAX-1);
}

void randomizer(){
    srand(time(NULL));   // should only be called once
    for(int i=0;i<=MAX;i++){
        intArray[i]=rand() % 100+1;//random is an int between 1 and 100
    }
    printf("Your New Array is: ");
    display();
}

int main( ) {
    while(true) {
        int choice;
        randomizer();
        printf("Select a sorting algorithm!\n1. Bubble short\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n0. Exit\n");
        scanf("%d", &choice);
        if(choice==0){
            return 0;
        }
        printf("Input Array: ");
        display();
        printline();
        switch (choice) {
            case 1:
                bubbleSort();
                break;
            case 2:
                selectionSort();
                break;
            case 3:
                insertionSort();
                break;
            case 4:
                quickSort();
                break;
            default:
                printf("Oops! Type 1-4!\n");
        }
        printf("Output Array: ");
        display();
        printline();
    }
}
//https://www.tutorialspoint.com/data_structures_algorithms/sorting_algorithms.htm
//https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_program_in_c.htm