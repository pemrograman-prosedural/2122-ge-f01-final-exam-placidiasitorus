#include "student.h"

void student_print_detail(struct student_t *_student, unsigned short int _size, int is_initial_state) {
    for (int i = 0; i < _size; i++) {
        char dorm_name[15];
        if (_student[i].dorm == NULL && is_initial_state) {
            strcpy(dorm_name, "unassigned");
        } else if (_student[i].dorm == NULL) {
            strcpy(dorm_name, "unassigned");
        } else {
            strcpy(dorm_name, _student[i].dorm->name);
        }

        printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text(_student[i].gender), dorm_name);
    }
}


void student_print_all(struct student_t *_student, unsigned short int _size){
    for(int i = 0 ; i < _size; i++){
    printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text(_student[i].gender));
    }
}

struct student_t create_student(char *std_id, char *std_name, char *std_year, enum gender_t std_gender){
    struct student_t std;
    strcpy(std.id, std_id);
    strcpy (std.name, std_name);
    strcpy (std.year, std_year);
    std.gender = std_gender;
    std.dorm = NULL;
    return std;
}


unsigned short int get_index_student (struct student_t *_student, unsigned short int size_std, char *_idstd, int *found){

    unsigned short int counter_std, i;

    for (i = 0; i < size_std; i++){
                if(strcmp(_student[i].id, _idstd) == 0)
                {
                    counter_std = i;
                    (*found) = 1;
                    break;
                }
    }
    return counter_std;
    
}


void assign_student(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std, unsigned short int idx_drm)
{       
        if (_dorm[idx_drm].capacity > _dorm[idx_drm].residents_num){

            if (_dorm[idx_drm].gender == _student[idx_std].gender){
            _student[idx_std].dorm = &_dorm[idx_drm];
            _dorm[idx_drm].residents_num++;
            }
        }
}


void dorm_empty(struct student_t *_student, struct dorm_t *_dorm, unsigned short int poin, unsigned short int size_std) {
    if (_dorm == NULL || _student == NULL) {
        return;
    }
    _dorm[poin].residents_num = 0;
    for (int i = 0; i < size_std; i++) {
        if (_student[i].dorm != NULL && strcmp(_student[i].dorm->name, _dorm[poin].name) == 0) {
            _student[i].dorm = NULL;
        }
    }
}


void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *new_dorm, unsigned short int idx_std, unsigned short int idx_drm) {
    if (new_dorm->capacity <= new_dorm->residents_num) {
        return;
    }

    if (_student[idx_std].dorm != NULL) {
        _student[idx_std].dorm->residents_num--;
        _student[idx_std].dorm = new_dorm;
        new_dorm->residents_num++;
    }else {
        _student[idx_std].dorm = new_dorm;
        new_dorm->residents_num++;
    }
}

void student_leave(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std) {
    if (_student[idx_std].dorm != NULL) {
        _student[idx_std].dorm->residents_num--;
        _student[idx_std].dorm = NULL;
    }
}