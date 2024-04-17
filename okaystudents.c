#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
/*OLWASI LINDA ENE212-0146/2021*/


typedef struct {
    char name[MAX_LENGTH];
    char reg_number[MAX_LENGTH];
    char courses[3][MAX_LENGTH];
} Student;


void getStudentDetails(Student *student);
void saveStudentDetails(const Student *student, FILE *file);
void editStudentDetails(Student *student);
void displayStudentDetails(const Student *student);

int main() {
    FILE *file;
    Student students[3];

    
    file = fopen("C:\\Users\\OLWASI LINDA\\Desktop\\student_details.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    
    for (int i = 0; i < 3; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        getStudentDetails(&students[i]);
        saveStudentDetails(&students[i], file);
    }

    
    fclose(file);

    
    int choice;
    printf("\nDo you want to edit any information? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter student number to edit (1-3): ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3) {
            editStudentDetails(&students[choice - 1]);
            
            file = fopen("C:\\Users\\OLWASI LINDA\\Desktop\\student_details.txt", "w");
            if (file == NULL) {
                printf("Error opening file.\n");
                return 1;
            }
            
            for (int i = 0; i < 3; i++) {
                saveStudentDetails(&students[i], file);
            }
            fclose(file);
        } else {
            printf("Invalid student number.\n");
        }
    }

    
    printf("\nStudent Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nDetails for Student %d:\n", i + 1);
        displayStudentDetails(&students[i]);
    }

    return 0;
}


void getStudentDetails(Student *student) {
    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);
    printf("Enter registration number: ");
    scanf(" %[^\n]", student->reg_number);
    for (int i = 0; i < 3; i++) {
        printf("Enter course %d: ", i + 1);
        scanf(" %[^\n]", student->courses[i]);
    }
}


void saveStudentDetails(const Student *student, FILE *file) {
    fprintf(file, "Name: %s\n", student->name);
    fprintf(file, "Registration Number: %s\n", student->reg_number);
    for (int i = 0; i < 3; i++) {
        fprintf(file, "Course %d: %s\n", i + 1, student->courses[i]);
    }
    fprintf(file, "\n");
}


void editStudentDetails(Student *student) {
    printf("Enter new details for Student:\n");
    getStudentDetails(student);
}


void displayStudentDetails(const Student *student) {
    printf("Name: %s\n", student->name);
    printf("Registration Number: %s\n", student->reg_number);
    for (int i = 0; i < 3; i++) {
        printf("Course %d: %s\n", i + 1, student->courses[i]);
    }
}
