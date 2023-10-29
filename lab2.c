// Question:1
//#include<stdio.h>
// int main(){
//     int x,i,j=1,sum=0;
//     printf("Enter the number: ");
//     scanf("%d",&x);
//     for(i=1;i<=x;i++){
//         sum+=j;
//         j+=2;
//     }
//     printf("The sum is: %d",sum);
//     return 0;
// }
// Question:2
#include <stdio.h>
int main() {
   int i, space, rows, k = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
   return 0;
}