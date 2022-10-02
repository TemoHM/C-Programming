#ifndef STACK_H_INCLUED
#define STACK_H_INCLUED
#define QUEUE_SIZE (10)
#define COURSES_NUM (3)
typedef enum boolean
{
    TRUE = 1,
    FALSE = 0
} boolean;

typedef struct Course
{
    int course_ID;
    int course_grade;
} Course;

typedef struct student
{
    int student_ID;
    int student_year;
    Course courses[COURSES_NUM];
} student;

boolean IsFull();

int GetUsedSize();

boolean AddEntry(int id, int year, int *subjects, int *grades);

void DeleteEntry();

boolean ReadEntry(int id);

void GetIdList();

boolean IsIdExist(int id);

#endif