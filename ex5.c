#include <stdio.h>
int fib(int);
int main(){
    int n;
    printf("Fibonacci Series\n");
    printf("Enter the nth term of fibonacci series: ");
    scanf("%d",&n);
    printf(" the %d term in the fibonacci series is %d",n,fib(n));
}
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1||n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}