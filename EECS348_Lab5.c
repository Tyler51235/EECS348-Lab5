#include <stdio.h>
#define MONTHS 12 
//is a macro for months
double averages(double[], int);
void salesReport(double[], char*[]);
void salesSummary(double[], char*[]);
void movingAverageReport(double[], char*[]);
void salesSortedReport(double[], char*[]);
// this block of code creates the functions needed for the program
// Function to generate and print the sales report
void salesReport(double sales[], char *months[]) {
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-9s\t$%9.2f\n", months[i], sales[i]);
    }
}

// Function to generate and print the sales summary
void salesSummary(double sales[], char *months[]) {
    double min = sales[0], max = sales[0];
    int minIndex = 0, maxIndex = 0;

    // Find minimum and maximum sales
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }

    double average = calculateAverage(sales, MONTHS);

    printf("Minimum sales: $%9.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: $%9.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: $%9.2f\n", average);
}

// Function to generate and print the six-month moving averages
void movingAveragesReport(double sales[], char *months[]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s\t$%9.2f\n", months[i], months[i + 5], sum / 6);
    }
}

// Function to generate and print the sales report sorted from highest to lowest
void saleSortedReport(double sales[], char *months[]) {
    // Copying sales data to a temporary array for sorting
    double sortedSales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
    }

    // Sorting sales data in descending order
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                // Swap sales values
                double temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp;
                // Swap month names
                char *tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }

    // Print sorted sales report
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-9s\t$%9.2f\n", months[i], sortedSales[i]);
    }
}

int main() {
    //Months names
    char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    // Monthly sales data
    double sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };
    // sales assoicated with months
}

