#include "dorm.h"
#include "string.h"



// Function
void print_dorm_detail (struct dorm_t *dorms, unsigned short int size_dorm){
    for(int i = 0; i< size_dorm; i++){
        printf("%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, gender_to_text (dorms[i].gender), dorms[i].residents_num);
    }
}


void print_all_dorm (struct dorm_t *dorms, unsigned short int size_dorm){
    for(int i = 0; i< size_dorm; i++){

        printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, gender_to_text (dorms[i].gender));
    }
}

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t dorm_;
    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = _gender;
    dorm_.residents_num = 0;
    return dorm_;
}


unsigned short int get_index_dorm (struct dorm_t *_dorm, unsigned short int size_drm, char *_name){
    unsigned short int counter_drm, i;

    for (i = 0; i < size_drm; i++){
                if(strcmp(_dorm[i].name, _name) == 0)
                {
                    counter_drm = i;
                    break;
                }
    }
    return counter_drm;
    
}


