#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

//convert a grade to its grade point
double getGradePoint(string grade){
if (grade == "A")
  return 4.0;
else if (grade == "B+")   
  return 3.5;
else if (grade == "B")
  return 3.0;
else if (grade == "C+")
  return 2.5;
else if (grade == "C")
  return 2.0;
else if (grade == "D+")
  return 1.5;
else if (grade == "D")
  return 1.0;
else if (grade == "E")
  return 0.0;

return -1;

}

// Check whether the grade is valid
bool isValidGrade(string grade){
    return grade == "A" || 
           grade == "B+" ||
           grade == "B" ||
           grade == "C+" ||
           grade == "C" ||
           grade == "D+" ||
           grade == "D" ||
           grade == "E";

}

int main(){

int numberofSemesters;

cout << "================================\n";
cout << "        CGPA CALCULATOR        \n";
cout << "================================\n";

// Get number of semesters
cout << "Enter number of semesters: ";
cin >> numberofSemesters;

while (numberofSemesters <= 0){
    cout << "Invalid number. Enter a positive  number: ";
    cin >> numberofSemesters;
}

// Overall totals used for CGPA
double overallCredits = 0;
double overallGradePoints = 0;

// Semester loop
for (int semester = 0; semester < numberofSemesters; semester++){
    int numberofCourses;

    cout << "\n========== SEMESTER " << semester + 1 << " ==========\n";
    cout << "Enter number of courses: ";
    cin >> numberofCourses;

    while (numberofCourses < 1 || numberofCourses > 10){
        cout << "Enter a number between 1 and 10: ";
        cin >> numberofCourses;
    }

    // Arrays for courses in this semester
    string courseNames[10];
    string grades[10];
    int creditHours[10];
    double coursePoints[10];

    double semestersCredits = 0;
    double semestersGradePoints = 0;

    // Course loop
    for (int i = 0; i < numberofCourses; i++){
        double gradePoint;
        cout << " \nCourse " << i + 1 << endl;

        // Clear input buffer before getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter course name: ";

        getline(cin, courseNames[i]);
        cout << "Enter grade: ";
        cin >> grades[i];

        // Validate grade
        while(!isValidGrade(grades[i])){
            cout << "Invalid grade. Enter again: ";
            cin >> grades[i];
        }
        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        // Validate credit hours
        while(creditHours[i] <= 0){
            cout << "Invalid credit hours. Enter again: ";
            cin >> creditHours[i];
        }

        // Convert grade to grade point
        gradePoint = getGradePoint(grades[i]);

        // Calculate weighted grade points
        coursePoints[i] = gradePoint * creditHours[i];

        // Add to semester totals 
        semestersCredits += creditHours[i];
        semestersGradePoints += coursePoints[i];

        // Add to overall totals
        overallCredits += creditHours[i];
        overallGradePoints += coursePoints[i];
    }
    // Calculate semester GPA
    double semesterGPA = semestersGradePoints/semestersCredits;

    // Display semester courses
    cout << "\n---------- COURSE SUMMARY ---------\n";
    cout << left << setw(25) << "Course"
                 << setw(10) << "Grade"
                 << setw(15) << "Credits"
                 << setw(15) << "Points" << endl;
    cout << "-----------------------------------------------------------------\n";
    
    for (int i = 0; i < numberofCourses; i++){
        cout << left << setw(25) << courseNames[i]
                     << setw(10) << grades[i]
                     << setw(15) << creditHours[i]
                     << setw(15) << fixed << setprecision(2) << coursePoints[i]
                     << endl;
    }
    cout << "\nSemester Credits: " << semestersCredits << endl;
    cout << "Semester GPA: " << fixed << setprecision(2) << semesterGPA << endl;

    
}
// Calculate overall CGPA
double CGPA = overallGradePoints / overallCredits;

cout << "\n================================================\n";
cout << "                     FINAL RESULT                  \n";
cout << "====================================================\n";
cout << "Total Credit Hours: " << overallCredits << endl;
cout << "Total Grade Points: " << fixed << setprecision(2) << overallGradePoints << endl;
cout << "Overall CGPA: " << fixed << setprecision(2) << CGPA << endl;
cout << "======================================================\n";
return 0;

}

