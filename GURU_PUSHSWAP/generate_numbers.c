#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to check if a number already exists in the array
bool isDuplicate(int num, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, lowerLimit, upperLimit;

    // Seed the random number generator
    srand(time(NULL));

    // Get input from the user
    printf("Enter the number of random numbers to generate (n): ");
    scanf("%d", &n);

    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);

    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    // Validate input (important!)
    if (n <= 0 || lowerLimit >= upperLimit || (upperLimit - lowerLimit + 1) < n) {
        printf("Invalid input. Please check your values for n, lower limit, and upper limit.\n");
        return 1; // Indicate an error
    }


    int *randomNumbers = (int *)malloc(n * sizeof(int)); //Dynamically allocate memory

    if (randomNumbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  //Exit with error code
    }

    int count = 0;
    while (count < n) {
        int randomNumber = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;

        if (!isDuplicate(randomNumber, randomNumbers, count)) {
            randomNumbers[count] = randomNumber;
            count++;
        }
    }

    // Print the generated random numbers
    printf("Generated random numbers (without duplicates):\n");
    printf("./push_swap ");
    for (int i = 0; i < n; i++) {
        printf("%d ", randomNumbers[i]);
    }
    printf(" | wc -l\n");

    free(randomNumbers); // Free the dynamically allocated memory.  Crucial to prevent memory leaks.

    return 0; // Indicate successful execution
}