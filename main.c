#include "student.h"

void printMenu()
{
    printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
    printf("1. Add New Record\n");
    printf("2. List All Records\n");
    printf("3. Calculate Class Average\n");
    printf("4. Delete Record\n");
    printf("5. Show Best Student\n");
    printf("6. Update Record\n");
    printf("7. Search (Submenu)\n");
    printf("0. Exit\n");
    printf("Your Choice: ");
}

int main()
{
    Student *root = NULL; // No global variables! Head is defined here.
    int choice;
    int subChoice;
    int idInput;
    char nameInput[50];

    while (1)
    {
        printMenu();
        if (scanf("%d", &choice) != 1)
        { // Input validation
            while (getchar() != '\n')
                ; // Clear buffer
            continue;
        }

        switch (choice)
        {
        case 0:
            printf("\nExiting Program...\n");
            freeList(root); // Prevent memory leak before exit
            return 0;

        case 1:
            root = addRecord(root);
            break;

        case 2:
            listRecords(root);
            break;

        case 3:
            calculateClassAverage(root);
            break;

        case 4:
            printf("\nEnter ID to delete: ");
            scanf("%d", &idInput);
            root = deleteRecord(root, idInput);
            break;

        case 5:
            showBestStudent(root);
            break;

        case 6:
            printf("\nEnter ID to update: ");
            scanf("%d", &idInput);
            updateRecord(root, idInput);
            break;

        case 7:
            printf("\n--- Search Menu ---\n");
            printf("1. Search by Name\n");
            printf("2. Search by ID\n");
            printf("Choice: ");
            scanf("%d", &subChoice);

            if (subChoice == 1)
            {
                printf("Enter Name: ");
                scanf("%49s", nameInput);
                findByName(root, nameInput);
            }
            else if (subChoice == 2)
            {
                printf("Enter ID: ");
                scanf("%d", &idInput);
                findById(root, idInput);
            }
            else
            {
                printf("Invalid selection.\n");
            }
            break;

        default:
            printf("\n[Error] Invalid choice! Please try again.\n");
        }
    }
    return 0;
}