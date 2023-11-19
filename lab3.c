//question:01
// #include <stdio.h>  
// void swap(int *, int *);  
// int main()  
// {  
//     int a = 10;  
//     int b = 20;   
//     printf("Before swapping the values in main a = %d, b = %d\n",a,b); 
//     swap(&a,&b);  
//     printf("After swapping values in main a = %d, b = %d\n",a,b);
// }
// void swap (int *a, int *b)  
// {  
//     int temp;   
//     temp = *a;  
//     *a=*b;  
//     *b=temp;  
//     printf("After swapping values in function a = %d, b = %d\n",*a,*b);
// }
//question:02
// #include <stdio.h>  
// #include <string.h>  
  
// int str_len( char *st);  
// void revstr( char *st);  
// int main()  
// {  
//     char st[50];  
//     printf (" Enter a string to be reversed: ");  
//     scanf( "%s", st);  
      
//     revstr(st);   
      
//     printf (" The reverse string is: %s", st);  
//     return 0;  
// }  
  
// void revstr (char *st)  
// {  
//     int len, i;  
//     char *start, *end, temp;  
      
//     len = str_len (st);  
//     start = st;  
//     end = st;  
      
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
// }  
  
// int str_len (char *ptr)  
// {  
//     int i = 0;  
//     while ( *(ptr + i) != '\0')  
//     i++;  
//     return i;  
// }  
// //question:03
// #include <stdio.h>

// #define MAX_SIZE 100 // Maximum array size

// int main()
// {
//     int arr[MAX_SIZE];
//     int N, i;
//     int * ptr = arr;    // Pointer to arr[0] 

//     printf("Enter size of array: ");
//     scanf("%d", &N);

//     printf("Enter elements in array:\n");
//     for (i = 0; i < N; i++)
//     {
//         scanf("%d", ptr);
//         ptr++;   
//     }

//     // Make sure that pointer again points back to first array element
//     ptr = arr;

//     printf("Array elements: ");
//     for (i = 0; i < N; i++)
//     {
//         printf("%d, ", *ptr);
//         ptr++;
//     }

//     return 0;
// }
//question:04
// #include<stdio.h>
// void search(int *x, int *y);
// int main()
// {
//     int a[5], n, i;
//     int *pa, *pn;
//     pa = &a[0], pn = &n;

//     printf("Enter array element: ");
//     for (i=0;i<5;i++)
//     {
//         scanf("%d",pa+i);
//     }

//     printf("Enter element for search: ");
//     scanf("%d",pn);

//     search(&a[0],pn);

//     return 0;
// }

// void search (int *x, int *y)
// {
//     int i, f=0;

//     for (i=0;i<5;i++)
//     {
//         if ( *(x+i) == *y)
//         {
//             f=1;
//             break;
//         }
//         else
//             continue;
//     }

//     if (f==1)
//         printf("Found.\n");

//     else
//         printf("Not found.\n");
// }
//question:05
#include<stdio.h>

void main()
{
    int a[10][10], b[10][10], c[10][10];

    int m, n, i, j;

    printf("Enter size of the matrix\n");
    scanf("%d %d", &m, &n);

    printf("Enter elements of matrix 'a' of size %d\n", (m * n));
    
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", (*(a + i) + j));
     printf("Enter elements of matrix 'b' of size %d\n", (m * n));
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", (*(b + i) + j));

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            (*(*(c + i) + j)) = (*(*(a + i) + j)) + (*(*(a + i) + j));

    printf("The sum of matrix is:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++) {
            printf("%d\t", (*(*(c + i) + j)));
        }
        printf("\n");
    }
}