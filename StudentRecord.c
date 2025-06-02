#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int midterm;
    int final;
    float average;
    struct student* next;
};

typedef struct student student;
student* head;

void AddNewRecord();
student* FillInfo();
void List();
void FindByName(char* name);
void FindById(int target);
void ClassAverage();
void DeleteRecord(int id);
void BestStudent();
void UpdateRecord(int id);

int main() {
    int menu;
    menu = 1;
    while (menu) {
        printf("\n0-Exit Program");
        printf("\n1-Add New Record");
        printf("\n2-List Records");
        printf("\n3-Calculate Class Average");
        printf("\n4-Delete Record");
        printf("\n5-Show Best Student");
        printf("\n6-Update Record");
        printf("\nYour Choice: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            printf("\nExiting Program...");
            return 1;
        case 1:
            AddNewRecord();
            break;
        case 2:
            printf("\n0-Return to Previous Menu");
            printf("\n1-List All Records");
            printf("\n2-Search by Name");
            printf("\n3-Search by Student ID\n");
            int subMenu = 1;
            while (subMenu) {
                printf("\nYour Choice: ");
                scanf("%d", &subMenu);
                switch (subMenu)
                {
                case 0:
                    subMenu = 0;
                    break;
                case 1:
                    List();
                    printf("\n0-Return to Previous Menu");
                    printf("\n1-List All Records");
                    printf("\n2-Search by Name");
                    printf("\n3-Search by Student ID\n");
                    break;
                case 2:
                    printf("\nEnter the Student's Name: ");
                    char search[50];
                    scanf("%s", search);
                    FindByName(search);
                    subMenu = 0;
                    break;
                case 3:
                    printf("\nEnter the Student ID: ");
                    int number;
                    scanf("%d", &number);
                    FindById(number);
                    subMenu = 0;
                    break;
                default:
                    printf("Invalid Input");
                    subMenu = 0;
                    break;
                }
            }
            break;
        case 3:
            ClassAverage();
            break;
        case 4:
            printf("Enter the Student ID to Delete\n");
            int id_to_delete;
            scanf("%d", &id_to_delete);
            DeleteRecord(id_to_delete);
            break;
        case 5:
            BestStudent();
            break;
        case 6:
            printf("\nEnter the Student ID to Update: ");
            int id;
            scanf("%d", &id);
            UpdateRecord(id);
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }
    return 0;
}

student* FillInfo() {
    student* newNode = (student*)malloc(sizeof(student));
    if (newNode == NULL) {
        printf("\nMemory allocation failed");
        return 0;
    }
    printf("\nStudent ID: ");
    scanf("%d", &newNode->id);
    printf("\nStudent Name: ");
    scanf("%s", &newNode->name);
    printf("\nMidterm Grade: ");
    scanf("%d", &newNode->midterm);
    printf("\nFinal Grade: ");
    scanf("%d", &newNode->final);
    newNode->average = (newNode->midterm) * 0.4 + (newNode->final) * 0.6;
    newNode->next = NULL;
    return newNode;
}

void AddNewRecord() {
    if (head == NULL) {
        head = FillInfo();
        return;
    }
    student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = FillInfo();
}

void List() {
    student* temp = head;
    if (temp == NULL) {
        printf("No Records Found.\n");
        return;
    }
    while (temp != NULL) {
        printf("\n-------------------------");
        printf("\nStudent ID: %d", temp->id);
        printf("\nStudent Name: %s", temp->name);
        printf("\nMidterm Grade: %d", temp->midterm);
        printf("\nFinal Grade: %d", temp->final);
        printf("\nAverage: %.2f", temp->average);
        printf("\n-------------------------");
        temp = temp->next;
    }
    return;
}

void FindByName(char* name) {
    student* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (strcmp(temp->name, name)) {
        if (temp->next == NULL) {
            printf("\nRecord Not Found");
            return;
        }
        temp = temp->next;
    }
    printf("\n-------------------------");
    printf("\nStudent ID: %d", temp->id);
    printf("\nStudent Name: %s", temp->name);
    printf("\nMidterm Grade: %d", temp->midterm);
    printf("\nFinal Grade: %d", temp->final);
    printf("\nAverage: %f", temp->average);
    printf("\n-------------------------");
}

void FindById(int target) {
    student* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->id != target) {
        if (temp->next == NULL) {
            printf("Record Not Found");
            return;
        }
        temp = temp->next;
    }
    printf("\n-------------------------");
    printf("\nStudent ID: %d", temp->id);
    printf("\nStudent Name: %s", temp->name);
    printf("\nMidterm Grade: %d", temp->midterm);
    printf("\nFinal Grade: %d", temp->final);
    printf("\nAverage: %f", temp->average);
    printf("\n-------------------------");
}

void ClassAverage() {
    student* temp = head;
    int sum = 0, i = 0;
    int totalAverage = 0;
    while (temp->next != NULL) {
        sum += temp->average;
        i++;
        temp = temp->next;
    }
    sum += temp->average;
    i++;
    totalAverage = sum / i;
    printf("\nClass Average: %d", totalAverage);
}

void DeleteRecord(int targetId) {
    student* temp1 = head;
    student* temp2;
    if (temp1->id == targetId) {
        head = head->next;
        free(temp1);
        printf("\nRecord Deleted Successfully");
        return;
    }
    while (temp1->next->id != targetId) {
        temp1 = temp1->next;
    }
    if (temp1->next->next == NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp1);
        temp2->next = NULL;
        printf("\nRecord Deleted Successfully");
        return;
    }
    temp2 = temp1;
    temp1 = temp1->next;
    temp2->next = temp1->next;
    free(temp1);
    printf("\nRecord Deleted Successfully");
}

void BestStudent() {
    student* temp1 = head;
    student* temp2;
    int top = 0;
    while (temp1->next != NULL) {
        if ((temp1->average) > top) {
            top = temp1->average;
            temp2 = temp1;
        }
        temp1 = temp1->next;
    }
    if ((temp1->average) > top) {
        top = temp1->average;
        temp2 = temp1;
    }
    printf("\n-------------------------");
    printf("\nStudent ID: %d", temp2->id);
    printf("\nStudent Name: %s", temp2->name);
    printf("\nMidterm Grade: %d", temp2->midterm);
    printf("\nFinal Grade: %d", temp2->final);
    printf("\nAverage: %.2f", temp2->average);
    printf("\n-------------------------");
}

void UpdateRecord(int id) {
    student* temp = head;
    while (temp->id != id) {
        if (temp->next == NULL) {
            printf("\nRecord Not Found");
            return;
        }
        temp = temp->next;
    }
    char newName[50];
    int newMidterm, newFinal;
    printf("\n-------------------------");
    printf("\nStudent ID: %d", temp->id);
    printf("\nStudent Name: %s", temp->name);
    printf("\nMidterm Grade: %d", temp->midterm);
    printf("\nFinal Grade: %d", temp->final);
    printf("\nAverage: %f", temp->average);
    printf("\n-------------------------");
    printf("\nNew Name: ");
    scanf("%s", &newName);
    strcpy(temp->name, newName);
    printf("\nNew Midterm Grade: ");
    scanf("%d", &newMidterm);
    temp->midterm = newMidterm;
    printf("\nNew Final Grade: ");
    scanf("%d", &newFinal);
    temp->final = newFinal;
    temp->average = (temp->midterm) * 0.4 + (temp->final) * 0.6;
    printf("\nRecord Updated Successfully");
}
