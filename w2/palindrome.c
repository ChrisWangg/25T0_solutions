#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define colour macros
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

bool isPalindrome(char *string, int length);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./palindrome <word to test>\n");
        return 1;
    }

    if (isPalindrome(argv[1], strlen(argv[1]))) {
        printf(GREEN "Yes, it's a palindrome.\n" RESET);
    } else {
        printf(RED "No, it's not a palindrome.\n" RESET);
    }
    return 0;
}

bool isPalindrome(char *string, int length) {
    int l = 0;
    int r = length - 1;

    while (l < r) {
        if (string[l] != string[r]) {
            return false;
        };
        l++;
        r--;
    }
    return true;
}