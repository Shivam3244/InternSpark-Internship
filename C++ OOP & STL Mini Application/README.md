# Task 4 - C++ OOP & STL Mini Application

## Project: Student Grade Management System

### Features

- C++ classes and objects
- Inheritance
- `vector` for student storage
- `map` for subject/grade storage
- Add student
- Add/update grade
- Search student
- Display all students
- Calculate average
- Assign letter grade
- Save data to a file
- Makefile

## Compile

Using Make:

```bash
make
```

Run:

```bash
make run
```

Manual compilation:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o student_manager
./student_manager
```

Windows:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o student_manager.exe
student_manager.exe
```

## Grade Rules

| Average | Grade |
|---:|:---:|
| 90-100 | A |
| 80-89 | B |
| 70-79 | C |
| 60-69 | D |
| Below 60 | F |

## Sample

```text
Enter choice: 1
Enter student ID: 101
Enter student name: Rahul
Student added successfully.

Enter choice: 2
Enter student ID: 101
Enter subject: Mathematics
Enter grade: 85
Grade added successfully.

Enter choice: 3
Enter student ID: 101
Average: 85.00
Grade: B
```
