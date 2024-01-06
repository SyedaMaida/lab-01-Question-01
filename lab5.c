// #include<stdio.h>
// int main(){
//     FILE* fptr;
//     fptr=fopen("test1.txt","w");
//     fputs("I love C programming\n",fptr);
//     fclose(fptr);
//     fptr=fopen("test1.txt","a");
//     if (fptr!=NULL){
//         fprintf(fptr,"File Handling in C");       
//     }
//     else{
//         printf("Unable to append");
//     }
//     fclose(fptr);
//      fptr=fopen("test1.txt","r");
//      char content[1000];
//     if (fptr!=NULL){
//         while(fgets(content,1000,fptr)){
//         printf("%s",content);}       
//     }
//     else{
//         printf("Unable to read");
//     }
//     fclose(fptr);
//     return 0;
// }
//Question :02
// #include<stdio.h>
// int main(){
//     FILE* fptr;
//     fptr=fopen("newfile.txt","r");
//      char content[1000];
//      int words=0;
//     if (fptr!=NULL){
//         while(fgets(content,1000,fptr)){
//         for (int i = 0; content[i] != '\0'; ++i){
//         if (content[i]==' ' || content[i]=='\n' || content[i]=='\t' || content[i]==',' || content[i]==';' || content[i]=='.'){
//              printf("%s",content);} 
//             words++;
     
//         }
//         }        
//     }
//     else{
//         printf("Unable to read");
//     }
//     fclose(fptr);
//     printf("The number of words are: %d",words);
//     return 0;
// }
// #include <stdio.h>

// int main() {
//     FILE* fptr;
//     fptr = fopen("newfile.txt", "r");
//     char content[1000];
//     int words = 0;
//     if (fptr!=NULL){
//     fgets(content,1000,fptr);
//         printf("%s",content);}      

//     else{
//         printf("Unable to read");
//     }
//     fclose(fptr);
//     // if (fptr != NULL) {
//     //     printf("if");
//     //     while (fgets(content, 1000, fptr)) {
//     //         printf("if");
//     //         for (int i = 0; content[i] != '\0'; ++i) {
//     //             if (content[i] == ' ' || content[i] == '\n' || content[i] == '\t' || content[i] == ',' || content[i] == ';' || content[i] == '.') {
//     //                 printf(" ");
//     //             } else {
//     //                 printf("%c", content[i]);
//     //                 if (i == 0 || (content[i - 1] == ' ' || content[i - 1] == '\n' || content[i - 1] == '\t' || content[i - 1] == ',' || content[i - 1] == ';' || content[i - 1] == '.')) {
//     //                     words++;
//     //                 }
//     //             }
//     //         }
//     //     }
//     //     fclose(fptr);
//     // } else {
//     //     printf("Unable to read");
//     // }

//     // printf("\nThe number of words are: %d\n", words);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// Structure to represent a student record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks;
} Student;

// Function to add a student record to the file
void addStudentToFile(const char *fileName, const Student *student) {
    FILE *file = fopen(fileName, "a");

    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %d %.2f\n", student->name, student->rollNumber, student->marks);

    fclose(file);
}

// Function to display the current student records from the file
void displayStudentRecords(const char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    printf("Student Records:\n");

    Student student;
    while (fscanf(file, "%s %d %f", student.name, &student.rollNumber, &student.marks) == 3) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", student.name, student.rollNumber, student.marks);
    }

    fclose(file);
}

// Function to modify a student record in the file
void modifyStudentRecord(const char *fileName, int rollNumber, const Student *newData) {
    FILE *file = fopen(fileName, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Student student;
    int found = 0;

    while (fscanf(file, "%s %d %f", student.name, &student.rollNumber, &student.marks) == 3) {
        if (student.rollNumber == rollNumber) {
            fprintf(tempFile, "%s %d %.2f\n", newData->name, newData->rollNumber, newData->marks);
            found = 1;
        } else {
            fprintf(tempFile, "%s %d %.2f\n", student.name, student.rollNumber, student.marks);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(fileName);
    rename("temp.txt", fileName);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    } else {
        printf("Student record modified.\n");
    }
}

// Function to delete a student record from the file
void deleteStudentRecord(const char *fileName, int rollNumber) {
    FILE *file = fopen(fileName, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Student student;
    int found = 0;

    while (fscanf(file, "%s %d %f", student.name, &student.rollNumber, &student.marks) == 3) {
        if (student.rollNumber == rollNumber) {
            found = 1;
        } else {
            fprintf(tempFile, "%s %d %.2f\n", student.name, student.rollNumber, student.marks);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(fileName);
    rename("temp.txt", fileName);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    } else {
        printf("Student record deleted.\n");
    }
}

int main() {
    const char *fileName = "students.txt";
    Student student, newData;
    int choice, rollNumber;

    do {
        printf("\nStudent Record Management\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Modify Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", student.name);
                printf("Enter student roll number: ");
                scanf("%d", &student.rollNumber);
                printf("Enter student marks: ");
                scanf("%f", &student.marks);

                addStudentToFile(fileName, &student);
                printf("Student record added.\n");
                break;

            case 2:
                displayStudentRecords(fileName);
                break;

            case 3:
                printf("Enter the roll number of the student to modify: ");
                scanf("%d", &rollNumber);
                printf("Enter new data:\n");
                printf("Enter student name: ");
                scanf("%s", newData.name);
                printf("Enter student marks: ");
                scanf("%f", &newData.marks);

                modifyStudentRecord(fileName, rollNumber, &newData);
                break;

            case 4:
                printf("Enter the roll number of the student to delete: ");
                scanf("%d", &rollNumber);

                deleteStudentRecord(fileName, rollNumber);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
