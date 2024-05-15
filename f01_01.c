// 12S23022 - Placidia Santa Hillary Sitorus
// 12S23025  - Alif Aflah Suedi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv)
{
    char input[100];
    char command[50];
    int is_initial_state = 1;
    unsigned short int size_std = 0, size_dorm = 0;

    struct student_t *students = malloc(20 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));

    while (1) {
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = 0;

        strcpy(command, strtok(input, "#"));
        if (strcmp(command, "student-print-all-detail") == 0) {
            student_print_detail(students, size_std, is_initial_state);
        } else if (strcmp(command, "dorm-print-all-detail") == 0) {
            print_dorm_detail(dorms, size_dorm);
        } else if (strcmp(command, "student-print-all") == 0) {
            student_print_all(students, size_std);
        } else if (strcmp(command, "dorm-print-all") == 0) {
            print_all_dorm(dorms, size_dorm);
        } else if (strcmp(command, "student-add") == 0) {
            char id[10], name[50], year[10], gender[10];

            strcpy(id, strtok(NULL, "#"));
            strcpy(name, strtok(NULL, "#"));
            strcpy(year, strtok(NULL, "#"));
            strcpy(gender, strtok(NULL, "#"));

            students[size_std] = create_student(id, name, year, gender_to_value(gender));
            size_std++;
            is_initial_state = 0;

        } else if (strcmp(command, "dorm-add") == 0) {
            char name[10], size_str[5], gender[10];
            unsigned short int capacity = 0;

            strcpy(name, strtok(NULL, "#"));
            strcpy(size_str, strtok(NULL, "#"));
            capacity = atoi(size_str);
            strcpy(gender, strtok(NULL, "#"));

            dorms[size_dorm] = create_dorm(name, capacity, gender_to_value(gender));
            size_dorm++;

        } else if (strcmp(command, "assign-student") == 0) {
            char id[10], dorm_name[30];
            strcpy(id, strtok(NULL, "#"));
            strcpy(dorm_name, strtok(NULL, "#"));

            unsigned short int student_idx = 0;
            unsigned short int dorm_idx = 0;
            int found = 0;

            student_idx = get_index_student(students, size_std, id, &found);
            if (found == 0) continue;

            dorm_idx = get_index_dorm(dorms, size_dorm, dorm_name);

            assign_student(students, dorms, student_idx, dorm_idx);

        } else if (strcmp(command, "dorm-empty") == 0) {
            char dorm_name[30];
            strcpy(dorm_name, strtok(NULL, "#"));

            unsigned short int dorm_idx = get_index_dorm(dorms, size_dorm, dorm_name);

            dorm_empty(students, dorms, dorm_idx, size_std);

        } else if (strcmp(command, "move-student") == 0) {
            char id[10], new_dorm_name[30];
            strcpy(id, strtok(NULL, "#"));
            strcpy(new_dorm_name, strtok(NULL, "#"));

            unsigned short int student_idx = 0;
            unsigned short int new_dorm_idx = 0;
            int found = 0;

            student_idx = get_index_student(students, size_std, id, &found);
            if (found == 0) continue;
            new_dorm_idx = get_index_dorm(dorms, size_dorm, new_dorm_name);

            move_student(students, dorms, &dorms[new_dorm_idx], student_idx, new_dorm_idx);

        } else if (strcmp(command, "student-leave") == 0) {
            char id[10];
            strcpy(id, strtok(NULL, "#"));

            unsigned short int student_idx = 0;
            int found = 0;

            student_idx = get_index_student(students, size_std, id, &found);
            if (found == 0) continue;

            student_leave(students, dorms, student_idx);
        }
         else if (strcmp(command, "---") == 0) {
            break;
        }
    }

    free(students);
    free(dorms);

    return 0;
}