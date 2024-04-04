# Mini-School-Database-System
Mini School Database System
This Mini School Database System is designed to manage information about teachers and students. It includes functionalities for creating, modifying, and searching for teacher and student records. The system also incorporates an authentication mechanism for admin access.

Classes and Structs:
Person Class:

Attributes:
Name
Age
CNIC
Contact Number
Constructors: Default Constructor, Parameterized Constructor, Copy Constructor, Destructor
Teacher Class (Derived from Person):

Additional Attributes:
Emp Id
Course
Salary
Constructors: Default Constructor, Parameterized Constructor, Copy Constructor, Destructor
Student Class (Derived from Person):

Additional Attributes:
CGPA
Degree
Constructors: Default Constructor, Parameterized Constructor, Copy Constructor, Destructor
Login Struct:

Attributes:
ID
Password
Admin Functions:
Create (Teacher or Student): Allows the admin to create new teacher or student records by providing necessary details.
Modify (Teacher or Student): Enables the admin to modify existing teacher or student records.
Search (Teacher or Student): Provides various search options for finding teacher or student records based on different criteria.
Search Functions:
Search Student by name: Searches for a student by their name and prints the student's information.
Search Student by roll no.: Searches for a student by their roll number and prints the student's information.
Search all students of specific age: Finds all students of a specific age and prints their information.
Search all students of CGPA more than given by admin: Retrieves all students with a CGPA greater than the specified value and prints their details.
Search all students of CGPA less than given by admin: Retrieves all students with a CGPA less than the specified value and prints their details.
Implementation:
The system utilizes classes and structs to organize and manage data efficiently.
Proper constructors, destructors, and copy constructors are implemented to ensure memory management and object copying are handled correctly.
Functions are provided to perform CRUD (Create, Read, Update, Delete) operations on teacher and student records.
Search functions are implemented to retrieve specific information based on user-defined criteria.
