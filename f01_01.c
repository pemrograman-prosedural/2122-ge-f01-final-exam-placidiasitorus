#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input[101];
    char *kata;
    int student_size = 0;
    int dorm_size = 0;
    int stdIndex = 0;
    int drmIndex = 0;
    struct student_t *students = NULL;
    struct dorm_t *dorms = NULL;
    students = malloc(student_size * sizeof(struct student_t));
    dorms = malloc(dorm_size * sizeof(struct dorm_t));
    char id[10];
    char nama[25];
    char year[5];
    char dormName[15];
    int capacity = 0;
    int xDorm = -1;
    int xStd = -1;
    

    while (14)
    {
        input[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        }

        if (strcmp(kata, "---") == 0)
        {
            break;
        }
        else if (strcmp(kata, "student-add") == 0)
        {
            student_size++;
            students = realloc(students, student_size * sizeof(struct student_t));
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(nama, kata);
            kata = strtok(NULL, "#");
            strcpy(year, kata);
            kata = strtok(NULL, "#");
            if (strcmp(kata, "male") == 0)
            {
                students[stdIndex] = create_student(id, nama, year, GENDER_MALE);
            }
            else if (strcmp(kata, "female") == 0)
            {
                students[stdIndex] = create_student(id, nama, year, GENDER_FEMALE);
            }
            stdIndex++;
        }
        else if (strcmp(kata, "student-print-all") == 0)
        {
            void (*ptf)(struct student_t * _student, int count) = NULL;
            ptf = print_student;
            ptf(students, stdIndex);
        }
        else if (strcmp(kata, "student-print-all-detail") == 0)
        {
            print_student_detail(students, stdIndex);
        }
        else if (strcmp(kata, "assign-student") == 0)
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata); 
            kata = strtok(NULL, "#");   
            strcpy(dormName, kata);
            for (int i = 0; i < stdIndex; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    xStd = i;
                    break;
                }
            }

            for (int i = 0; i < stdIndex; i++)
            {
                if (strcmp(dorms[i].name, dormName) == 0)
                {
                    xDorm = i;
                    break;
                }
            }

            if (xDorm != -1 && xStd != -1)
            {
                void (*pf)(struct student_t * _student, struct dorm_t * _dorm, char *id, char *dorm_name) = NULL;
                pf = assign_student;
                pf(&students[xStd], &dorms[xDorm], id, dormName);
            }
        }
        else if (strcmp(kata, "dorm-add") == 0)
        {
            dorm_size++;
            dorms = realloc(dorms, dorm_size * sizeof(struct dorm_t));
            kata = strtok(NULL, "#");
            strcpy(dormName, kata);
            kata = strtok(NULL, "#");
            capacity = atoi(kata);
            kata = strtok(NULL, "#");
            if (strcmp(kata, "male") == 0)
            {
                dorms[drmIndex] = create_dorm(dormName, capacity, GENDER_MALE);
            }
            else if (strcmp(kata, "female") == 0)
            {
                dorms[drmIndex] = create_dorm(dormName, capacity, GENDER_FEMALE);
            }
            drmIndex++;
        }
        else if (strcmp(input, "dorm-print-all") == 0)
        {
            print_dorm(dorms, drmIndex);
        }
        else if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            print_dorm_detail(dorms, drmIndex);
        }
        else if (strcmp(kata, "student-leave") == 0)
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            for (int i = 0; i < stdIndex; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    xStd = i;
                    break;
                }
            }

            for (int i = 0; i < stdIndex; i++)
            {
                if (strcmp(dorms[i].name, dormName) == 0)
                {
                    xDorm = i;
                    break;
                }
            }

            if (xDorm != -1 && xStd != -1)
            {
                void (*pf)(struct student_t * _student, struct dorm_t * _dorm) = NULL;
                pf = student_left;
                pf(&students[xStd], &dorms[xDorm]);
            }
        }
    }
    free(students);
    free(dorms);
    return 0;
}