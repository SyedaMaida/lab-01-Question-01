#include <stdio.h>
int main(){
    int amount;
    float hours;
    float answer;
    char id[10];
    printf("Please enter employee's ID: ");
    scanf("%s",&id);
    printf("\nPlease enter your total hours worked: ");
    scanf("%f",&hours);
    printf("\nPlease enter your amount per hours: ");
    scanf("%d",&amount);
    answer=hours*amount;
    printf("The Employee's ID is :%s\nMonthly salary is :Rs %.2f",id,answer);
    return 0;
}
