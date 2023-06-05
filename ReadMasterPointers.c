#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Exercise 2

    //Create a structure, save to a file
    FILE *fp;

    int r, r_2;
    
    struct person {
        char *name;
        int *age; //this is a pointer and therefore stores an address
    } *base; //declaring a person-struct pointer called base

    //Allocate memory for the struct pointer
    base = (struct person *)malloc(sizeof(struct person) * 1);
    if (base == NULL)
    {
        fprintf(stderr, "Can't find the memory!");
        exit(1);
    }
    //Allocate memory for the structs member pointers
    base->name = (char *)malloc(sizeof(char) * 32);
    base->age = (int *)malloc(sizeof(int) * 1);
    if ((base->name == NULL) || (base->age == NULL))
    {
        fprintf(stderr, "Can't find the memory!");
        exit(1); 
    }

    //Save data to a file
    //Open file
    fp = fopen("updated.dat", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Can't read the file :(\n");
        exit(1);
    }
    //read to file
    r = fread(base->name, sizeof(char), 32, fp);
    r_2 = fread(base->age, sizeof(int), 1, fp);

    if(r != 32 || r_2 != 1)
    {
        fprintf(stderr, "File read error\n");
        exit(1);
    }

    //Close the file
    fclose(fp);

    //Output the results
    printf("Name: %s\n Age: %d", base->name, *(base->age));

    return 0;

}