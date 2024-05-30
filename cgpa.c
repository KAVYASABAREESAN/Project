#include <stdio.h>

float calculateCGPA(float grades[], int creditHours[], int numCourses) {
    float totalCreditHours = 0;
    float totalGradePoints = 0;
    
    for (int i = 0; i < numCourses; i++) {
        float gradePoints;
        if (grades[i] == 'A') {
            gradePoints = 4.0;
        } else if (grades[i] == 'B') {
            gradePoints = 3.0;
        } else if (grades[i] == 'C') {
            gradePoints = 2.0;
        } else if (grades[i] == 'D') {
            gradePoints = 1.0;
        } else {
            gradePoints = 0.0;
        }
        
        totalCreditHours += creditHours[i];
        totalGradePoints += gradePoints * creditHours[i];
    }
    
    float cgpa = totalGradePoints / totalCreditHours;
    return cgpa;
}

int main() {
    int numCourses;
    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);
    
    float grades[numCourses];
    int creditHours[numCourses];
    
    for (int i = 0; i < numCourses; i++) {
        printf("Enter grade for course %d (A/B/C/D): ", i+1);
        scanf(" %c", &grades[i]);
        printf("Enter credit hours for course %d: ", i+1);
        scanf("%d", &creditHours[i]);
    }
    
    float cgpa = calculateCGPA(grades, creditHours, numCourses);
    printf("Your CGPA is: %.2f\n", cgpa);
    
    return 0;
}
