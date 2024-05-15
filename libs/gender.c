#include "gender.h"


/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */


// Convert the enum gender to text
char* gender_to_text (enum gender_t mhs_gender){
    if(mhs_gender == 0) return "male";
    else if(mhs_gender == 1) return "female";
    else return "unknown";
}

// Convert the text to enum gender
unsigned short int gender_to_value (char *_gender){
    unsigned short int _value;
    if(strcmp(_gender, "male") == 0) _value = 0;
    else if(strcmp(_gender, "female") == 0) _value = 1;
    return _value;
}