// 12S23022 - Placidia Santa Hillary Sitorus
// 12S23025  - Alif Aflah Suedi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

#define INITIAL_SIZE 10

int main() {
    char input[100];
    char command[50];
    int is_initial_state = 1;
    unsigned short int size_std = 0, size_dorm = 0;

    struct student_t *std = malloc(INITIAL_SIZE * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(INITIAL_SIZE * sizeof(struct dorm_t));

    if (std == NULL || dorms == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    int should_continue = 1;  // Variable to control the loop

    while (should_continue) {
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
                if (size_std >= INITIAL_SIZE) {
                    std = realloc(std, 2 * INITIAL_SIZE * sizeof(struct student_t));
                    if (std == NULL) {
                        fprintf(stderr, "Failed to reallocate memory.\n");
                        return EXIT_FAILURE;
                    }
                }
                std[size_std++] = create_student(data_id, data_name, data_year, gender_to_value(data_gender));
                is_initial_state = 0;
            } else {
                fprintf(stderr, "Invalid student-add command format.\n");
            }
        } else if (strcmp(command, "dorm-add") == 0) {
            char *dorm_name = strtok(NULL, "#");
            char *dorm_size = strtok(NULL, "#");
            char *dorm_gender = strtok(NULL, "#");

            if (dorm_name && dorm_size && dorm_gender) {
                if (size_dorm >= INITIAL_SIZE) {
                    dorms = realloc(dorms, 2 * INITIAL_SIZE * sizeof(struct dorm_t));
                    if (dorms == NULL) {
                        fprintf(stderr, "Failed to reallocate memory.\n");
                        return EXIT_FAILURE;
                    }
                }
                unsigned short int capacity = atoi(dorm_size);
                dorms[size_dorm++] = create_dorm(dorm_name, capacity, gender_to_value(dorm_gender));
            } else {
                fprintf(stderr, "Invalid dorm-add command format.\n");
            }
        } else if (strcmp(command, "assign-student") == 0) {
            
        } else if (strcmp(command, "dorm-empty") == 0) {
            
        } else if (strcmp(command, "move-student") == 0) {
            
        } else if (strcmp(command, "student-leave") == 0) {
            
        } else if (strcmp(command, "---") == 0) {
            should_continue = 0;
        } else {
            fprintf(stderr, "Unknown command: %s\n", command);
        }
    }

    free(std);
    free(dorms);

    return 0;
}
