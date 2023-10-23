#include <stdio.h>
int main(){
    int x, y;
    printf("Enter a number: ");
    scanf("%d",&x);
    printf("Enter a number: ");
    scanf("%d",&y);
    if (x>5&&y>5){
        printf("The numbers are added: %d",x+y);
    }
    else if(x>5||y>5){
        printf("The numbers are multiplied: %d",x*y);
    }
    else if(x<5&&y<5){
        printf("the value of first no: %d",x+1);
        printf("The value of second no: %d",y+1);
    }
    else{
        printf("Hello World");
    }
    return 0;
}