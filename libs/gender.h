#ifndef GENDER_H
#define GENDER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum gender_t
{
    GENDER_MALE,
    GENDER_FEMALE
};

char* gender_to_text (enum gender_t mhs_gender);
unsigned short int gender_to_value (char *_gender);

#endif
