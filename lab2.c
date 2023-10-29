Question:1
#include<stdio.h>
int main(){
    int x,i,j=1,sum=0;
    printf("Enter the number: ");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        sum+=j;
        j+=2;
    }
    printf("The sum is: %d",sum);
    return 0;
}
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
//Question :03
#include <stdio.h>
int main ()
{
    int temp, i;
    char string1[5], string2[5];
    printf ("Enter the first integer: ");
    scanf ("%s", &string1);
    printf ("Enter the second integer: ");
    scanf ("%s", &string2);
    for (i=0;string1[i]!='\0';i++){
        if (string1[i]==string2[i]){
            temp=1;
    }
    else{ 
        temp=0;}
    }
    if(temp==1){
        printf("The strings are same");
    }
    else if(temp==0){
        printf("The strings are different");
    }
    else{
        printf("none");
    }
  return 0;
}
// Questions :04
#include <stdio.h>
#include <ctype.h>
int main ()
{
    int temp, i;
    char string1[15], my[20];
    printf ("Enter the first integer: ");
    scanf ("%s", &string1);
    for(i=0;string1[i]!='\0';i++){
        if(string1[i]>=65&&string1[i]<=90){
            string1[i]=tolower(string1[i]);
            
        }
        else if(string1[i]>97&&string1[i]<=122){
            string1[i]=toupper(string1[i]);
        }
    }
    printf("The string is %s",string1);
  return 0;
}
// Question : 05
#include <stdio.h>
int main()
{
    int arr1[100], n,ctr=0;
    int i, j, k;
       printf("\n\nPrint all unique elements of an array:\n");
       printf("------------------------------------------\n");	
       printf("Input the number of elements to be stored in the array: ");
       scanf("%d",&n);
       printf("Input %d elements in the array :\n",n);
       for(i=0;i<n;i++)
            {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }
    printf("\nThe unique elements found in the array are: \n");
    for(i=0; i<n; i++)
    {
        ctr=0;
        for(j=0,k=n; j<k+1; j++)
        {
            if (i!=j)
            {
		       if(arr1[i]==arr1[j])
              {
                 ctr++;
               }
             }
        }
       if(ctr==0)
        {
          printf("%d ",arr1[i]);
        }
    }
       printf("\n\n");
    return 0;
}
// Question :06
#include<stdio.h>

struct distance
{
    int feet;
    int inch;
};

int main()
{
    struct distance d1, d2, sum;
    printf("Enter feet and inch of first distance: ");
    scanf("%d%d", &d1.feet, &d1.inch);
    printf("Enter feet and inch of second distance: ");
    scanf("%d%d", &d2.feet, &d2.inch);

    sum.inch = d1.inch + d2.inch;
    sum.feet = d1.feet + d2.feet;

    if(sum.inch>=12)
    {
        sum.feet += sum.inch/12;
        sum.inch %= 12;
    }
    printf("Sum is %d' %d''", sum.feet, sum.inch);
    return 0;
}