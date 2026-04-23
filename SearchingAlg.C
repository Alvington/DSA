#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; //middle index

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            left = mid + 1; // right half
        } else {
            right = mid - 1; // left half
        }
    }
    return -1; 
}

int hashFunction(int key, int size) {
    return key % size;
}
int hashSearch(int arr[], int size, int key) {
    int index = hashFunction(key, size);
    if (arr[index] == key) {
        return index; 
    }
    return -1; 
}

int main() {
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
       scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    int key;
    scanf("%d", &key);
        
    //Create a menu
    printf("    Menu\n");
    printf("-------------------\n");
    printf("a. Linear Search\n");
    printf("b. Binary Search\n");
    printf("c. Hash Search\n");
    printf("q. Quit\n");
    printf("Enter your choice: ");
    char choice;
    scanf(" %c", &choice);

    while (choice != 'q')
    {
        if (choice == 'a') {
            clock_t start = clock();
            int linearResult = linearSearch(arr, size, key);
            clock_t end = clock();
            double timeTaken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
            if (linearResult != -1) {
                printf("Element found at index: %d\n", linearResult);
            } else {
                printf("Element not found in the array.\n");
            }
            printf("Time taken: %.2f microseconds\n\n", timeTaken);
        }
        else if (choice == 'b') {
            clock_t start = clock();
            int binaryResult = binarySearch(arr, size, key);
            clock_t end = clock();
            double timeTaken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
            if (binaryResult != -1) {
                printf("Element found at index: %d\n", binaryResult);
            } else {
                printf("Element not found in the array.\n");
            }
            printf("Time taken: %.2f microseconds\n\n", timeTaken);
        }
        else if (choice == 'c') {
            clock_t start = clock();
            int hashResult = hashSearch(arr, size, key);
            clock_t end = clock();
            double timeTaken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
            if (hashResult != -1) {
                printf("Element found at index: %d\n", hashResult);
            } else {
                printf("Element not found in the array.\n");
            }
            printf("Time taken: %.2f microseconds\n\n", timeTaken);
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
        printf("Enter your choice: ");
        scanf(" %c", &choice);
    }
    return 0;
}
