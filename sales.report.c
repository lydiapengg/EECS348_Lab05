#include <stdio.h> 

#define num_months 12


//declare functions
void print_monthly_sales(double sales[]);
void print_summary(double sales[]);
void six_month_average(double sales[]);
void high_to_low(double sales[]);

const char *months[num_months] = { //holds the names of the months to display
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void print_monthly_sales(double sales[]){ //calculates the monthly sales
    printf("%-12s %-10s\n", "Month", "Sales"); //formats the way the output is printed
    for(int i=0; i<num_months; i++){ //iterates through the months 
        printf("%-12s $%.2f\n", months[i], sales[i]); //prints each month and corresponding sale
    }
}
void print_summary(double sales[]){ 
    //initalize all variables
    double min = sales[0];
    double max = sales[0];
    double total = 0;
    for(int i = 0; i < num_months; i++){ //loops through the months
        if (sales[i] < min) min = sales[i]; //compares and updates the min
        if (sales[i] > max) max = sales[i]; //compares and updates the max
        total += sales[i]; //adds the sales to the total
    }
    double average = total/num_months; //calculates average
    printf("Minimum Sales: $%.2f\n", min);
    printf("Maximum sales: $%.2f\n", max);
    printf("Average sales: $%.2f\n", average);
}

void six_month_average(double sales[]){
    for (int i=0; i <= num_months-6; i++) { //loops through the months
        double sum = 0; //variable to hold to the sum
        for (int index=i; index < i +6; index++){ //starting from the index, loops through the months
            sum += sales[index];
        }
        double six_month_moving_average = sum/6; //calculates average
        printf("%s-%s: $%.2f\n", months[i], months[i+5], six_month_moving_average);
    }
}
int compare(const void *a, const void *b){ //compare function for the qsort in the high_to_low function
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    if (num1 < num2) return 1;
    if (num1 > num2) return -1;
    return 0;
}
void high_to_low(double sales[]){
    double sales_sorted[num_months];
    for (int i=0; i<num_months; i++){ //creates new array without modifying original
        sales_sorted[i] = sales[i]; 
    }
    qsort(sales_sorted, num_months, sizeof(double), compare); //sorts the sales from greatest to least
    printf("Sales report (highest to lowest)\n");
    for (int i = 0; i<num_months; i++){ 
        printf("$%.2f\n", sales_sorted[i]);
    }
}
int main(){
    double sales[num_months];
    char user_file[100]; //created to hold the file name
    printf("Enter the filename: "); //gets file from user
    scanf("%s", user_file);
    FILE *file = fopen(user_file,"r"); //opens the file
    if (file == NULL) {
        printf("File not found.");
        return 0;
    }
    for (int i = 0; i<num_months; i++){ //reads the 12 sales from the file
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file); 
    //calls the functions to generate all the reports
    printf("Monthly Sales Report:\n");
    print_monthly_sales(sales);
    printf("Sales summary report:\n");
    print_summary(sales);
    printf("Six-Month moving average report:\n");
    six_month_average(sales);
    printf("Sales report (highest to lowest):\n");
    high_to_low(sales);

    return 0;
}