#include <stdio.h>
#include <stdlib.h>
#include "../Header/Header.h"

student students[QUEUE_SIZE];
int add_index = 0;

boolean IsFull(void)
{
    int counter = 0;
    int calc = 0;
    if (add_index == QUEUE_SIZE)
    {
        printf(" Data Base Is Full! ");
        return TRUE;
    }
    else
    {
        for (int i = 0; i <= add_index; i++)
        {
            counter = i;
        }
        calc = (QUEUE_SIZE - 1) - counter;
        printf("\n%d Pleases Remains\n", calc);
        return FALSE;
    }
}

int GetUsedSize()
{
    if (add_index == 0 && add_index <= QUEUE_SIZE)
    {
        return add_index;
    }
}

boolean AddEntry(int id, int year, int *subjects, int *grades)
{
    students[add_index].student_ID = id;
    students[add_index].student_year = year;
    for (int i = 0; i < COURSES_NUM; i++)
    {
        students[add_index].courses[i].course_ID = subjects[i];
        if (grades[i] == 0 || grades[i] <= 100)
        {
            students[add_index].courses[i].course_grade = grades[i];
        }
    }
    add_index += 1;
    return TRUE;
}

void DeleteEntry()
{
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        add_index -= 1;
    }
}

boolean ReadEntry(int id)
{
    int ID = 0;
    int Grade = 0;
    boolean check = FALSE;
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        for (int i = 0; i < add_index; i++)
        {
            if (id == students[i].student_ID)
            {
                check = TRUE;
                printf("\n-----------------------------------------\n");
                printf("Student Year : %d\n", students[i].student_year);
                printf("--Student Subjects Are--\n");
                for (int j = 0; j < COURSES_NUM; j++)
                {
                    ID = students[i].courses[j].course_ID;
                    printf("Subject %d \t", ID);
                }
                printf("\n--Student Grades Are--\n");
                for (int x = 0; x < COURSES_NUM; x++)
                {
                    Grade = students[i].courses[x].course_grade;
                    printf("Subject %d Grade is : %d \t", x + 1, Grade);
                }
                printf("\n-----------------------------------------\n");
            }
        }
    }
    if (check == FALSE)
    {
        printf("Student ID Does Not Exist");
    }
}

void GetIdList()
{
    int ID = 0;
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        printf("\n-----------------------------------------\n");
        printf("[\t");
        for (int i = 0; i < add_index; i++)
        {
            ID = students[i].student_ID;
            printf("%d,\t", ID);
        }
        printf("]");
        printf("\n-----------------------------------------\n");
    }
}

boolean IsIdExist(int id)
{
    for (int i = 0; i < add_index; i++)
    {
        if (id == students[i].student_ID)
        {
            printf("ID Exists");
            return TRUE;
        }
        else
        {
            printf("ID Doesn't Exist");
            return FALSE;
        }
    }
}
