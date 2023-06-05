#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    //Exercise 1
    int a;
    int *x;

    char b;
    char *y;

    x = &a; //Pointers hold memory addresses always!
    y = &b;

    printf("Here is the address of a:%p and here is the address of b:%p\n", &a, &b);
    printf("Here is the address of a:%p and here is the address of b:%p\n", x, y);
    */

    //Exercise 2

    //Create a structure, save to a file
    FILE *fp;
    
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

    base->name = "Hello";
    *(base->age) = 39;

    //Save data to a file
    //Open file
    fp = fopen("updated.dat", "w");
    if(fp == NULL)
    {
        fprintf(stderr, "Can't create the file :(\n");
        exit(1);
    }
    //Write to file
    fwrite(base->name, sizeof(char), 32, fp);
    fwrite(base->age, sizeof(int), 1, fp);
    puts("Data written");

    //*** Note if you want to write an entire structure to file, there CANNOT be any pointer members

    //Close the file
    fclose(fp);

    return 0;

}