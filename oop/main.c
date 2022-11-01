#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define Class struct

/*
 * primitive object orientation exercise from https://youtu.be/Gp2m8ZuXoPg
 * (Fábio Akita)
 */

typedef Class Person {
    char name[10];
    short age;
    short height;
    int(*show)(Class Person *);
} Person;

int person_print(Person *self) {

    printf("name: %s, age: %d, height: %d\n", self->name, self->age, self->height);

    return (errno);
}

Person *new_person(char name[], 
        short age, 
        short height) {

    Person *self = (Person *) malloc(sizeof(Person));
    strcpy(self->name, name);
    self->age = age;
    self->height = height;
    self->show = &person_print;

    return(self);
}

int main() {

    Person *person = (Person *) new_person("Gabriel G. de Brito", 17, 173);

    return(errno);
}
