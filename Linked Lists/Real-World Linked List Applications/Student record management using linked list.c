#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student Node
struct STUDENT {
    int roll;
    char name[50];
    float marks;
    struct STUDENT *next;
};

struct STUDENT *head = NULL;

// Insert student
void insertStudent() {

    struct STUDENT *newNode =
        (struct STUDENT*)malloc(sizeof(struct STUDENT));

    printf("Enter Roll No: ");
    scanf("%d", &newNode->roll);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct STUDENT *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display students
void displayStudents() {

    if (head == NULL) {
        printf("No records found\n");
        return;
    }

    struct STUDENT *temp = head;

    printf("\nRoll\tName\tMarks\n");

    while (temp != NULL) {
        printf("%d\t%s\t%.2f\n",
               temp->roll,
               temp->name,
               temp->marks);
        temp = temp->next;
    }
}

// Search student
void searchStudent() {

    int roll;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    struct STUDENT *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Record Found: %d %s %.2f\n",
                   temp->roll,
                   temp->name,
                   temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found\n");
}

// Delete student
void deleteStudent() {

    int roll;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    struct STUDENT *temp = head, *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Record deleted successfully\n");
}

// Main
int main() {

    int choice;

    while (1) {

        printf("\n--- Student Record Menu ---\n");
        printf("1. Insert Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: insertStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
