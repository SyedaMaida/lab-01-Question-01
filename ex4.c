#include <stdio.h>
int main(){
    long int decimal, binary;
    printf("Decimal to binary converter");
    printf("Please enter the number in decimal: ");
    scanf("%ld",&decimal);
    binary=myBinary(decimal);
    printf("Decimal (%ld) =Binary (%ld)",decimal,binary);
    return 0;
}

int myBinary(long int a){
    long int binary=0,rem,num,base=1;
    num=a;
    while (num!=0){
        rem=num%2;
        binary=binary+base*rem;
        base=base*10;
        num=num/2;
    }
    return binary;
}
    