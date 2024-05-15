// 12S23022 - Placidia Santa Hillary Sitorus
// 12S23025  - Alif Aflah Suedi

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
    char id[10];
    char nama[25];
    char year[5];
    char dormName[15];
    int capacity = 0;
    int xDorm = -1;
    int xStd = -1;

    while (1)
    {
        memset(input, 0, sizeof(input));
        int c = 0;
        while (1)
        {
            int x = getchar();
            if (x == EOF || x == '\n')
            {
                break;
            }
            if (x == '\r')
            {
                continue;
            }
            input[c++] = x;
        }

        kata = strtok(input, " ");
        if (kata == NULL)
        {
            continue;
        }

        // Rest of the code...
    }

    free(students);
    free(dorms);
    return 0;
}