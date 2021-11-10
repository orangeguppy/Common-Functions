#include <stdio.h>
#include <stdlib.h>

/***************** 1D ARRAYS *****************/
void print_1D_int_array(int array[], int length) {
// How to use: pass in the int array to print in the first parameter, then pass in the length of the array
    for (int i = 0 ; i < length ; i++) {
        printf("%d ", array[i]);
    }
}

int *copy_1D_array(int array[], int length) { // free the memory after using this!!!
    int *array_copy = calloc(length, sizeof(int));
    for (int i = 0 ; i < length ; i++) {
        array_copy[i] = array[i];
    }
    return array_copy;
}

// Reverse one-dimensional int array completely from start to end
void reverse_1D_int_array(int array[], int length) { 
// How to use: pass in the int array to reverse in the first parameter, and then pass in the length of the array

    for (int i = 0 ; i < length / 2; i++) {
        int temp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temp;
    }
}

// Reverse a specific portion of a 1D int array
void reverse_part_of_1D_int_array(int array[], int length, int start, int end) {
// How to use: pass in the array to reverse, the array's length, the start index to start reversing from, and then the end index when the reverse process is stopped
// E.g. reverse {1, 2, 3, 4, 5} to obtain {3, 2, 1, 4, 5}. Pass in (array, 5, 0, 2)
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

// Sort an array from smallest to largest
void bubble_sort(int array[], int length) {
    for (int i = 0 ; i < length ; i++) {
        for (int j = 0 ; j < length ; j++) {
            if (array[j] > array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Faster way to sort an array from smallest to largest
int partition(int *array, int lo, int hi);
void quicksort(int *array, int lo, int hi) {
    int p;
    if (lo < hi) {
        p = partition(array, lo, hi);
        quicksort(array, lo, p - 1);
        quicksort(array, p + 1, hi);
    }
}

int partition(int *array, int lo, int hi) {
    int i;
    int j;

    int pivot = array[hi];
    i = lo;
    for (j = lo ; j < hi ; j++) {
        if (array[j] < pivot) {
            int temp = array[i]; // swap A[i] with A[j]
            array[i] = array[j];
            array[j] = temp;

            i = i + 1;
        }
    }
    int temp = array[i]; // swap A[i] with A[hi]
    array[i] = array[hi];
    array[hi] = temp;

    return i;
}

// Sort an array from largest to smallest
void sort_int_array_from_largest_to_smallest(int array[], int length) {
    for (int i = 0 ; i < length ; i++) {
        for (int j = 0 ; j < length ; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/***************** 2D ARRAYS *****************/
void print_2D_array(int rows, int cols, int array[rows][cols]) {
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void copy_2D_array(int rows, int cols, int array[rows][cols], int array_copy[rows][cols]) { // copy all elements from one 2d array to another
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            array_copy[i][j] = array[i][j];
        }
    }
}

// Reverse each row in the 2D array
void reverse_rows_of_2D_array(int rows, int cols, int array[rows][cols]) {
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols / 2 ; j++) {
            int temp = array[i][cols - 1 - j];
            array[i][cols - 1 - j] = array[i][j];
            array[i][j] = temp;
        }
    }
}

// Reverse each column in the 2D array
void reverse_cols_of_2D_array(int rows, int cols, int array[rows][cols]) {
    for (int i = 0 ; i < cols ; i++) {
        for (int j = 0 ; j < rows / 2 ; j++) {
            int temp = array[j][i];
            array[j][i] = array[rows - 1 - j][i];
            array[rows - 1 - j][i] = temp;
        }
    }
}

int main() {
    {
        printf("Test case 1\n");
        int array[] = {1, 2, 3, 4, 5};
        int length = 5;
        reverse_1D_int_array(array, length);
        print_1D_int_array(array, length);
        printf("\n\n");
    }

    {
        printf("Test case 2\n");
        int array[] = {1, 2, 3, 4, 5};
        int length = 5;
        reverse_part_of_1D_int_array(array, length, 2, 4);
        print_1D_int_array(array, length);
        printf("\n\n");
    }

    {
        printf("Test case 3\n");
        int array[] = {3, 1, 4, 5, 0};
        int length = 5;
        sort_int_array_from_largest_to_smallest(array, 5);
        print_1D_int_array(array, length);
        printf("\n\n");
    }

    {
        printf("Test Case 4\n");
        int array[][3] = { {1, 2, 3}, {4, 5, 6}};
        reverse_rows_of_2D_array(2, 3, array);
        print_2D_array(2, 3, array);
        printf("\n\n");
    }

    {
        printf("Test Case 5\n");
        int array[][3] = { {1, 2, 3}, {4, 5, 6}};
        reverse_cols_of_2D_array(2, 3, array);
        print_2D_array(2, 3, array);
        printf("\n\n");
    }

    {
        printf("Test Case 6\n");
        int array[] = {1, 2, 3, 4, 5};
        int *array_copy = copy_1D_array(array, 5);
        print_1D_int_array(array_copy, 5);
        free(array_copy);
        printf("\n\n");
    }

}