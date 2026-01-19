#include <stdio.h>

int main() {
    int n, i;
    float temp[50];
    float min, max, sum = 0, avg;

    printf("Enter number of temperature readings: ");
    scanf("%d", &n);

    printf("Enter temperatures:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &temp[i]);
    }

    // Initialize min and max with first element
    min = temp[0];
    max = temp[0];

    // Calculate min, max, and sum
    for (i = 0; i < n; i++) {
        if (temp[i] < min)
            min = temp[i];

        if (temp[i] > max)
            max = temp[i];

        sum += temp[i];
    }

    avg = sum / n;

    printf("\nTemperature Statistics:\n");
    printf("Minimum Temperature = %.2f\n", min);
    printf("Maximum Temperature = %.2f\n", max);
    printf("Average Temperature = %.2f\n", avg);

    return 0;
}
