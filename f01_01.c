// 12S23022 - Placidia Santa Hillary Sitorus
// 12S23025  - Alif Aflah Suedi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input[100];
    char command[50];
    int is_initial_state = 1;
    unsigned short int size_std = 0, size_dorm = 0;

    struct student_t *std = malloc(20 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));

    if (std == NULL || dorms == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    int should_continue = 1;  // Variable to control the loop

    do {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "Failed to read input.\n");
            continue;
        }
        input[strcspn(input, "\r\n")] = 0;

        strcpy(command, strtok(input, "#"));
        if (strcmp(command, "student-print-all-detail") == 0) {
            student_print_detail(std, size_std, is_initial_state);
        } else if (strcmp(command, "dorm-print-all-detail") == 0) {
            print_dorm_detail(dorms, size_dorm);
        } else if (strcmp(command, "student-print-all") == 0) {
            student_print_all(std, size_std);
        } else if (strcmp(command, "dorm-print-all") == 0) {
            print_all_dorm(dorms, size_dorm);
        } else if (strcmp(command, "student-add") == 0) {
            char *data_id = strtok(NULL, "#");
            char *data_name = strtok(NULL, "#");
            char *data_year = strtok(NULL, "#");
            char *data_gender = strtok(NULL, "#");

            if (data_id && data_name && data_year && data_gender) {
                std[size_std] = create_student(data_id, data_name, data_year, gender_to_value(data_gender));
                size_std++;
                is_initial_state = 0;
            } else {
                fprintf(stderr, "Invalid student-add command format.\n");
            }
        } else if (strcmp(command, "dorm-add") == 0) {
            char *dorm_name = strtok(NULL, "#");
            char *dorm_size = strtok(NULL, "#");
            char *dorm_gender = strtok(NULL, "#");

            if (dorm_name && dorm_size && dorm_gender) {
                unsigned short int capacity = atoi(dorm_size);
                dorms[size_dorm] = create_dorm(dorm_name, capacity, gender_to_value(dorm_gender));
                size_dorm++;
            } else {
                fprintf(stderr, "Invalid dorm-add command format.\n");
            }
        } else if (strcmp(command, "assign-student") == 0) {
            char *data_id = strtok(NULL, "#");
            char *data_name = strtok(NULL, "#");

            if (data_id && data_name) {
                unsigned short int poin_std = 0;
                unsigned short int poin_drm = 0;
                int found = 0;

                poin_std = get_index_student(std, size_std, data_id, &found);
                if (found == 0) continue;

                poin_drm = get_index_dorm(dorms, size_dorm, data_name);

                assign_student(std, dorms, poin_std, poin_drm);
            } else {
                fprintf(stderr, "Invalid assign-student command format.\n");
            }
        } else if (strcmp(command, "dorm-empty") == 0) {
            char *data_name = strtok(NULL, "#");

            if (data_name) {
                unsigned short int poin_drm = 0;

                poin_drm = get_index_dorm(dorms, size_dorm, data_name);

                dorm_empty(std, dorms, poin_drm, size_std);
            } else {
                fprintf(stderr, "Invalid dorm-empty command format.\n");
            }
        } else if (strcmp(command, "move-student") == 0) {
            char *data_id = strtok(NULL, "#");
            char *data_name = strtok(NULL, "#");

            if (data_id && data_name) {
                unsigned short int poin_std = 0;
                unsigned short int poin_drm = 0;
                int found = 0;

                poin_std = get_index_student(std, size_std, data_id, &found);
                if (found == 0) continue;
                poin_drm = get_index_dorm(dorms, size_dorm, data_name);

                move_student(std, dorms, &dorms[poin_drm], poin_std, poin_drm);
            } else {
                fprintf(stderr, "Invalid move-student command format.\n");
            }
        } else if (strcmp(command, "student-leave") == 0) {
            char *data_id = strtok(NULL, "#");

            if (data_id) {
                unsigned short int poin_std = 0;
                int found = 0;

                poin_std = get_index_student(std, size_std, data_id, &found);
                if (found == 0) continue;

                student_leave(std, dorms, poin_std);
            } else {
                fprintf(stderr, "Invalid student-leave command format.\n");
            }
        } else if (strcmp(command, "---") == 0) {
            should_continue = 0;
        } else {
            fprintf(stderr, "Unknown command: %s\n", command);
        }
    } while (should_continue);

    free(std);
    free(dorms);
 
    return 0;
}