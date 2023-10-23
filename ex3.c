#include <stdio.h>
int main(){
    int height;
    printf("Please enter your height in centimeters: ");
    scanf("%d",&height);
    if (height<150){
        printf("\nDwarf");
    }
    else if (height==150){
        printf("\nAverage");
    }
    else if(height>=165){
        printf("\nTall");
    }
    return 0;
}