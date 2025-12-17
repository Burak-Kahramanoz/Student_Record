#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Structure representing a student node in the linked list.
 */
typedef struct Student
{
    int id;
    char name[50];
    int midterm;
    int final;
    float average;
    struct Student *next;
} Student;

/* --- Function Prototypes --- */

/**
 * Creates a new student node by asking user for input.
 * @return Pointer to the newly created node.
 */
Student *createStudentNode();

/**
 * Adds a new student record to the end of the list.
 * @param head The head of the list.
 * @return The (possibly updated) head of the list.
 */
Student *addRecord(Student *head);

/**
 * Lists all student records in the console.
 * @param head The head of the list.
 */
void listRecords(Student *head);

/**
 * Searches for a student by name.
 * @param head The head of the list.
 * @param name The name to search for.
 */
void findByName(Student *head, char *name);

/**
 * Searches for a student by ID.
 * @param head The head of the list.
 * @param id The ID to search for.
 */
void findById(Student *head, int id);

/**
 * Calculates and prints the class average.
 * @param head The head of the list.
 */
void calculateClassAverage(Student *head);

/**
 * Deletes a student record by ID.
 *
 * @param head The head of the list.
 * @param id The ID of the student to delete.
 * @return The updated head of the list.
 */
Student *deleteRecord(Student *head, int id);

/**
 * Finds and prints the student with the highest average.
 * @param head The head of the list.
 */
void showBestStudent(Student *head);

/**
 * Updates the information of an existing student.
 * @param head The head of the list.
 * @param id The ID of the student to update.
 */
void updateRecord(Student *head, int id);

/**
 * Frees all memory allocated for the list (Prevents memory leaks).
 * @param head The head of the list.
 */
void freeList(Student *head);

#endif