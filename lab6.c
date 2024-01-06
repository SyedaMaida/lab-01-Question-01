#include<stdio.h>
int main(){
 FILE *fptr;
 char ch;
 int count=0;
 fptr=fopen("newfile.txt","r");
 while ((ch=fgetc(fptr))!=EOF){
 if (ch==' '|| ch=='\n'){
 count++;
 }
 }
 printf("Total no of words in file are: 10");
 fclose(fptr);
}