#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

struct student_t {
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

void student_print_detail(struct student_t *_student, unsigned short int _size, int is_initial_state);
void student_print_all(struct student_t *_student, unsigned short int _size);
struct student_t create_student(char *std_id, char *std_name, char *std_year, enum gender_t std_gender);
void assign_student(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std, unsigned short int idx_drm);
unsigned short int get_index_student (struct student_t *_student, unsigned short int size_std, char *_idstd, int *found);
void dorm_empty(struct student_t *_student, struct dorm_t *_dorm, unsigned short int poin, unsigned short int size_std);
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *new_dorm, unsigned short int idx_std, unsigned short int idx_drm);
void student_leave(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std);
#endif