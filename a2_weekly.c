// Name: Hasin Shadab Rahman
// Net Id : hasinrahman
// description: a C program to calculate weekly pay.If the user has worked longer than 40 hours, the excessive hours are overtime, and the user will get paid 1.5 of the pay rate for those hours.This is how you calculate tax.The first $300 is taxed at 10%, the next $150 at 15%, and the rest at 20%.
#include <stdio.h>

int main(){
    double h, p; // declare variables for hours and pay rate
    double  t1, t2, t3,pay; // declare variables for tax and pay
    while(1){ // start infinite loop
        printf("Enter the number of hours worked in the week (enter 0 to stop): ");
        scanf("%lf",&h);
        // breaks the loop/ends the program if the value is 0
        if(h==0){
            break;
        }
        if(h<0){
            printf("Invalid number\n");
            continue;
        }
        printf("Enter the pay rate (per hour, enter 0 to stop): ");
        scanf("%lf",&p);
        // breaks the loop/ends the program if the value is 0
        if(p==0){
            break;
        }
        if(p<0){
            printf("Invalid number\n");
            continue;

        }
        if(h<40){
            pay = h * p; // calculate pay for less than 40 hours
        }
        else{
            pay = p * 40 + p * (h-40)*1.5; // calculate pay for more than 40 hours
        }
        if (pay < 300)
        {
            t1 = pay * 0.1; // calculate tax for first $300
        }
        else{
            t1 = 300 * 0.1;
        }
        if((pay-300)<150){
            t2 = (pay-300)*0.15; // calculate tax for next $150
        }
        else{
            t2 = 150 * 0.15;
        }
        if(pay > 450){
            t3 = t1 + t2 + (pay-450)*0.20; // calculate tax for rest
        }
        printf("Weekly pay (Gross): $%.2f \n", pay);
        printf("Tax: $%.2f\n", t3);
        printf("Weekly pay (Net): $%.2f\n", (pay-t3));
    }
    return 0;
}