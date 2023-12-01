/*
Invalid solution, I need to solve it in a C style

Use pointers to access arrays, locate the tens place then the ones place. 

possble solution, https://github.com/mendelmunkis/AoC/blob/master/2023/treb.c
*/
#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *fptr;

    char line[100];
    int sum = 0;

    // Open the calibration document file
    fptr = fopen("input", "r");

    // Check if the file is opened successfully
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read each line from the file and calculate the calibration value
    while (fgets(line, sizeof(line), fptr)) {
        int first_digit = -1;
        int last_digit = -1;

        // Find the first digit
        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                first_digit = line[i] - '0';
                break;
            }
        }

        // Find the last digit
        for (int i = sizeof(line) - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                last_digit = line[i] - '0';
                break;
            }
        }

        // Check if both first and last digits are found
        if (first_digit != -1 && last_digit != -1) {
            int calibration_value = first_digit * 10 + last_digit;
            sum += calibration_value;
            printf("%d\n", calibration_value);
        }
    }

    // Print the total sum of calibration values
    printf("Sum of Calibration Values: %d\n", sum);

    // Close the file
    fclose(fptr);

    return 0;
}
