#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Print char array and display the terminating character (you can see the end of the string)
void print_char_array(char array[]) {
    for (int i = 0 ; i < strlen(array) + 1 ; i++) {
        printf("%c", array[i]);
        if (array[i] == '\0') {
            printf("\\0");
        }
    }
    printf("\n");
}

// Remove all occurrences of a character in a string
void remove_all_chars_in_string(char array[], char to_remove) {
    int length = strlen(array);

    int i;
    for (i = 0 ; i < length ; i++) {
        if (array[i] == to_remove) {
            for (int j = i ; j < length ; j++) {
                array[j] = array[j + 1];
            }
            length--;
            i--;
        }
    }
}

// Remove characters from index start to index end of a char array
void remove_from_start_to_end(char array[], int start, int end) {
    for (int i = start ; i < end + 1 ; i++) {
        for (int j = start ; j < strlen(array) ; j++) {
            array[j] = array[j + 1];
        }
    }
}

// Reverse char array completely
void reverse_char_array(char array[]) {
    for (int i = 0 ; i < strlen(array) / 2; i++) {
        char temp = array[i];
        array[i] = array[strlen(array) - i - 1];
        array[strlen(array) - i - 1] = temp;
    }
}

// Reverse part of the char array from array[start] to array[end]
// Reverse a specific portion of a 1D int array
void reverse_part_of_char_array(char array[], int start, int end) {
// How to use: pass in the array to reverse the start index to start reversing from, and then the end index when the reverse process is stopped
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int main() {
    {
        char array[] = "Let's C";
        print_char_array(array);
        remove_all_chars_in_string(array, 'C');
        print_char_array(array);
        printf("\n");
    }

    {
        char *array = calloc(3, sizeof(char));
        print_char_array(array);
        free(array);
        printf("\n");
    }
    
    {
        char array[] = "The quick brown fox jumped over the lazy dog";
        print_char_array(array);
        reverse_char_array(array);
        print_char_array(array);
        printf("\n");
    }

    {
        char array[] = "Live. Laugh. Love.";
        print_char_array(array);
        reverse_part_of_char_array(array, 4, 8);
        print_char_array(array);
        printf("\n");
    }

    {
        char array[] = "Death. Despair. Despise.";
        print_char_array(array);
        remove_from_start_to_end(array, 0, 6);
        print_char_array(array);
        printf("\n");
    }
}
