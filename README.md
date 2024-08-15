# TA Management System

## Overview
Project Repport .[here](https://github.com/Silent0Wings/TA-Management-System/blob/bf029accb56ef2e5cec511388ebec640274ea775/Github.pdf).

The TA Management System is a C++ project designed to manage records of Teaching Assistants (TAs) within a department. The system ensures that only eligible TAs—those who are currently registered students—are maintained in the records. The project involves filtering out records of TAs who have graduated and updating the TA file accordingly.

## Features
- **File Filtering:** The system reads a file containing TA records and removes any records where the TA is classified as an "Alum".
- **TA Class:** The project includes a `TA` class that encapsulates TA data and provides methods to identify alumni and generate formatted output for TA records.

## Class Implementation

### TA Class
The `TA` class is the core of the system and is responsible for managing the data associated with each TA. The class includes the following members and methods:

- **Private Members:**
  - `int Student_Id`: The ID of the student.
  - `std::string First_Name`: The first name of the TA.
  - `std::string Status`: The status of the TA (e.g., Grad, UGrad, Alum).
  - `int Working_Hours`: The number of hours the TA works per week.
  - `int Year_Hired`: The year the TA was hired.

- **Constructors:**
  - `TA()`: A default constructor that initializes all members with default values.
  - `TA(int si, std::string fn, std::string s, int wh, int yh)`: A parameterized constructor that initializes the TA's attributes with the provided values.

- **Methods:**
  - `bool Is_Alum()`: Returns `true` if the TA is classified as an alumnus, based on the `Status` attribute.
  - `std::string print()`: Returns a formatted string containing the TA's details, or an empty string if the TA is an alumnus.


## How to Run
1. **Compile the Project:**
   - Use a C++ compiler to compile the source files, e.g., `g++ main.cpp -o TA_Management_System`.
   
2. **Run the Executable:**
   - Execute the compiled file in your terminal or command prompt, e.g., `./TA_Management_System`.

3. **Input File:**
   - Ensure the `TAs.txt` file is in the same directory as the executable. The file should be formatted as described in the example workflow.

4. **Output:**
   - The system will process the `TAs.txt` file and update it by removing records of TAs classified as "Alum".

## Conclusion
The TA Management System is a simple yet effective tool for managing TA records within an academic department. It ensures that only eligible TAs are retained in the records, providing a streamlined and accurate data management solution.

## License
This project is open-source and available under the MIT License.
