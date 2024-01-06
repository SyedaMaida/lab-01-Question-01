#include<stdio.h>
// int main(){
//     int a=2;
//     int b=3;
//     int temp, *c,*d;
//     printf("The numbers before swaping: %d\t%d\n",a,b);
//     c=&a;
//     d=&b;
//     temp=*c;
//     *c=*d;
//     *d=temp;
//     printf("after swaping %d\t%d",*c,*d);
//     return 0;
// }
// #include<string.h>
// int main(){
//     char str[100];
//     printf("Enter the string: \n");
//     scanf("%s",str);
//     char *me=&str;
//     // end=str+len-1;
//     int len, i;  
//     char *start, *end, temp;  
//     // len = str_len (me);  
//     len=strlen(str);
//     start = me;  
//     end = me;  
      
//     for (i = 0; i < len - 1; i++)  
//     end++;  
      
//     for (i = 0; i < len/2; i++)  
//     {  
//         temp = *end;  
//         *end = *start;  
//         *start = temp;  
          
//         start++;  
//         end--;  
//     }  
//     printf (" The reverse string is: %s", me);  
//     return 0;  
// }
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int N, i;
    int * ptr = arr;    // Pointer to arr[0] 

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("Enter elements in array:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", ptr);
        ptr++;   
    }

    // Make sure that pointer again points back to first array element
    ptr = arr;

    printf("Array elements: ");
    for (i = 0; i < N; i++)
    {
        printf("%d, ", *ptr);
        ptr++;
    }

    return 0;
}



