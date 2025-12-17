# Student Management System (C Project)

A robust, console-based **Student Management System** developed in C using **Singly Linked Lists**. This project demonstrates professional coding standards including modular architecture, dynamic memory management, and input validation.

## 🚀 Key Features

* **Modular Architecture:** Code is split into `student.h`, `student.c`, and `main.c` for maintainability.
* **Dynamic Data Structure:** Uses Linked Lists to store an unlimited number of records.
* **🛡️ Robust Input Validation:**
    * **Grade Check:** Ensures Midterm and Final grades are strictly between 0 and 100.
    * **Buffer Safety:** Prevents string overflow during name input.
* **🔍 Duplicate ID Prevention:** Automatically checks and prevents adding a student with an existing ID.
* **Memory Management:** Includes a garbage collection function (`freeList`) to prevent memory leaks upon exit.

## 📂 Project Structure

* `student.h`: API definitions and Struct design.
* `student.c`: Core logic (CRUD operations, validations).
* `main.c`: User interface and menu handling.

## 🛠️ How to Compile & Run

You can compile this project using any standard C compiler (like GCC).

### 1. Open Terminal
Navigate to the project directory.

### 2. Compile
Run the following command to link and compile the source files:

```bash
gcc main.c student.c -o sms_app
