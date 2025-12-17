#include "student.h"

Student *createStudentNode()
{
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (newNode == NULL)
    {
        printf("\n[Error] Memory allocation failed!\n");
        return NULL;
    }

    printf("\n--- New Record Info ---\n");
    printf("Student ID: ");
    scanf("%d", &newNode->id);

    printf("Student Name: ");
    // Limiting input to 49 chars to prevent buffer overflow
    scanf("%49s", newNode->name);
    do
    {
        printf("Midterm Grade (0-100): ");
        scanf("%d", &newNode->midterm);

        if (newNode->midterm < 0 || newNode->midterm > 100)
        {
            printf("[Warning] Invalid grade! Please enter a value between 0 and 100.\n");
        }
    } while (newNode->midterm < 0 || newNode->midterm > 100);
    do
    {
        printf("Final Grade (0-100): ");
        scanf("%d", &newNode->final);

        if (newNode->final < 0 || newNode->final > 100)
        {
            printf("[Warning] Invalid grade! Please enter a value between 0 and 100.\n");
        }
    } while (newNode->final < 0 || newNode->final > 100);
    newNode->average = (newNode->midterm * 0.4) + (newNode->final * 0.6);
    newNode->next = NULL;

    return newNode;
}

Student *addRecord(Student *head)
{
    Student *newNode = createStudentNode();
    if (newNode == NULL)
        return head;

    // Case 1: List is empty
    if (head == NULL)
    {
        return newNode;
    }

    // Case 2: Traverse to the end and link
    Student *temp = head;
    while (temp->next != NULL)
    {
        if (temp->id == newNode->id)
        {
            free(newNode);
            printf("\n[Error] Student with ID %d ALREADY EXISTS! Operation cancelled.\n", temp->id);
            return head;
        }
        temp = temp->next;
    }
    if (temp->id == newNode->id)
    {
        free(newNode);
        printf("\n[Error] Student with ID %d ALREADY EXISTS! Operation cancelled.\n", temp->id);
        return head;
    }
    temp->next = newNode;

    printf("Record added successfully.\n");
    return head;
}

void listRecords(Student *head)
{
    if (head == NULL)
    {
        printf("\n[Info] No records found. The list is empty.\n");
        return;
    }

    Student *temp = head;
    printf("\n%-10s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Midterm", "Final", "Average");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-10d %-20s %-10d %-10d %-10.2f\n",
               temp->id, temp->name, temp->midterm, temp->final, temp->average);
        temp = temp->next;
    }
    printf("-------------------------------------------------------------\n");
}

void findByName(Student *head, char *name)
{
    Student *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\n[Found] ID: %d, Name: %s, Average: %.2f\n", temp->id, temp->name, temp->average);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("\n[Info] Student named '%s' not found.\n", name);
}

void findById(Student *head, int id)
{
    Student *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\n[Found] ID: %d, Name: %s, Average: %.2f\n", temp->id, temp->name, temp->average);
            return;
        }
        temp = temp->next;
    }
    printf("\n[Info] Student with ID %d not found.\n", id);
}

void calculateClassAverage(Student *head)
{
    if (head == NULL)
    {
        printf("\n[Info] List is empty. Cannot calculate average.\n");
        return;
    }

    Student *temp = head;
    float sum = 0.0;
    int count = 0;

    while (temp != NULL)
    {
        sum += temp->average;
        count++;
        temp = temp->next;
    }

    printf("\n[Statistics] Class Average: %.2f (Total Students: %d)\n", (sum / count), count);
}

Student *deleteRecord(Student *head, int id)
{
    if (head == NULL)
    {
        printf("\n[Info] List is empty. Nothing to delete.\n");
        return NULL;
    }

    Student *temp = head;
    Student *prev = NULL;

    // Case 1: The node to be deleted is the Head node
    if (temp != NULL && temp->id == id)
    {
        head = temp->next; // Move head to the next node
        free(temp);        // Free memory
        printf("\n[Success] Record %d deleted.\n", id);
        return head;
    }

    // Case 2: Search for the node in the rest of the list
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: ID was not present in the list
    if (temp == NULL)
    {
        printf("\n[Info] Record with ID %d not found.\n", id);
        return head;
    }

    // Case 4: Node found, unlink it
    prev->next = temp->next;
    free(temp);
    printf("\n[Success] Record %d deleted.\n", id);

    return head;
}

void showBestStudent(Student *head)
{
    if (head == NULL)
    {
        printf("\n[Info] List is empty.\n");
        return;
    }

    Student *temp = head;
    Student *best = head;

    while (temp != NULL)
    {
        if (temp->average > best->average)
        {
            best = temp;
        }
        temp = temp->next;
    }

    printf("\n--- Best Student ---\n");
    printf("Name: %s\nID: %d\nAverage: %.2f\n", best->name, best->id, best->average);
}

void updateRecord(Student *head, int id)
{
    Student *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\n[Update] Updating record for ID: %d\n", id);

            printf("New Name: ");
            scanf("%49s", temp->name);
            printf("New Midterm: ");
            scanf("%d", &temp->midterm);
            printf("New Final: ");
            scanf("%d", &temp->final);

            temp->average = (temp->midterm * 0.4) + (temp->final * 0.6);
            printf("[Success] Record updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("\n[Info] Record with ID %d not found.\n", id);
}

void freeList(Student *head)
{
    Student *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n[System] Memory cleaned up successfully.\n");
}