#include <stdio.h>

void num_grade_to_letter() {
    unsigned int grade;
    printf("Enter numberical grade: ");
    scanf("%d", &grade);
    char letter_grade;
    if (grade <= 59) {
        letter_grade = 'F';
    }
    else if (grade >= 60 && grade <= 69) {
        letter_grade = 'D';
    }
    else if (grade >= 70 && grade <= 79) {
        letter_grade = 'C';
    }

    else if (grade >= 80 && grade <= 89) {
        letter_grade = 'B';
    }
    else if (grade >= 90 && grade <= 100) {
        letter_grade = 'A';
    }
    else {
        letter_grade = 'Z';
    }
    printf("Letter grade: %c\n", letter_grade);
}


