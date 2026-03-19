/*Reverse a string*/

#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

void printArray(char* s, int sSize) {
    printf("[");
    for (int i = 0; i < sSize; i++)
        printf(i < sSize - 1 ? "'%c'," : "'%c'", s[i]);
    printf("]\n");
}

int main() {

    char s1[] = {'h','e','l','l','o'};
    reverseString(s1, 5);
    printf("Example 1: ");
    printArray(s1, 5); 

    char s2[] = {'H','a','n','n','a','h'};
    reverseString(s2, 6);
    printf("Example 2: ");
    printArray(s2, 6);   

    return 0;
}
