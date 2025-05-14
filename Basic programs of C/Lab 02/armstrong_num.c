#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, digit, sum;

    printf("Armstrong numbers from 1 to 1000 are:\n");

    for (num = 1; num <= 1000; num++) {
        temp = num;
        sum = 0;

        int digits = (int)log10(num) + 1; //153
        printf("digits: %d\n", digits);

        while (temp != 0) {
            digit = temp % 10;
            // printf("digit: %d\n", digit);
            sum += pow(digit, digits);
            temp = temp / 10;
            // printf("Sum: %d\n", sum);
        }

        if (sum == num)
            printf("%d ", num);
    }

    return 0;
}
