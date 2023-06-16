#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
enum { FALSE, TRUE };
struct family {
	char name[SIZE];
	char relationship[SIZE];
	int age;
    int id;
	struct family *next;
};

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}
struct family *allocate(void) {
    struct family *a;
	a = (struct family *)malloc(sizeof(struct family) * 1);
	if (a == NULL)
	{
		fprintf(stderr, "No Memory Available");
		exit(1);
	}
    return a;

}
void fill_struct(struct family *a, int i){

    char temp[SIZE];
    a->id = i;
    printf("Name of family member:");
    strcpy(a->name, input());
    printf("Your relationship to %s:", a->name);
    strcpy(a->relationship, input());
    printf("Age of family member (%s):", a->name);
    strcpy(temp, input());
    a->age = atoi(temp);
   
}
void output(struct family *a){

    while (a != NULL){
        printf("ID: %d, Name: %s, Relationship: %s, Age: %d\n", a->id, a->name, a->relationship, a->age);
        a = a->next;
    }
    

}
void save_records(struct family *a){
    char filename[SIZE];
    FILE *fp;
    int count = 0;

    printf("Enter desired filename to save:");
    strcpy(filename, input());
    fp = fopen(filename, "w");

    if (fp == NULL){
        fprintf(stderr, "Unable to create file\n");
        exit(1);
    }

    while(a != NULL){
        fwrite(a, sizeof(struct family), 1, fp);
        a = a->next;
        count++;
    }
    fclose(fp);
    printf("Saved. Total Number of Records Saved:%d\n", count);
}

void read_records(){
    char filename[SIZE];
    FILE *fp;
    char count_str[SIZE];
    int count;
    int i;
    struct family *first, *current, *next;

    printf("Please enter desired filename to read:");
    strcpy(filename, input());
    printf("Please enter the total number of records saved:");
    strcpy(count_str,input());
    count = atoi(count_str);

    fp = fopen(filename, "r");
    if (fp == NULL){
        fprintf(stderr, "Unable to open file\n");
        exit(1);
    }
    

    for(i=0; i<count; i++){
        if(i == 0){
            first = allocate();
            fread(first, sizeof(struct family), 1, fp);
            current = first;
        }
        else{
            current->next = allocate();
            current = current->next;
            fread(current, sizeof(struct family), 1, fp);
        }
    }

    current->next = NULL;
    fclose(fp);

    printf("number of records read: %d\n", count);
    output(first);
}
void remove_record(struct family *a){
    /*Consider adding a way to delete the first record, and a way to delete records not in sequential order*/
    int i;

    printf("Type ID Number for Deleted Record:");
    i = atoi(input());

    struct family *temp;
    while (a != NULL){

        /*stopping 1 record before the record we want to delete*/
        if (a->id == (i-1)){
            printf("ID:%d, Name:%s, nextaddress:%p", a->id, a->name, a->next);
             /*storing the record we want to delete in temp*/
            temp = a->next;

            /*assigning this record to the record that comes after the record we want to delete*/
            a->next = temp->next; 

            /*free the storage for the "deleted record"*/
            free(temp);

            break;
        }
        else{
            a = a->next;
        }
    }
}

int main()
{
	struct family *first,*current;
	int done;
	char command[SIZE];
    int id;

	/* initialize first record to NULL */
	first = NULL;
    current = first;
    id = 0;

	/* main menu and input loop */
	done = FALSE;
	puts("Family Database");
	while(!done)
	{
		/* initialize the current pointer to
		   the start of the list 
		current = first;
        */

		/* output menu */
		puts("Menu:");
		puts("A - Add record");
		puts("D - Delete record");
		puts("L - List all records");
		puts("O - Open");
		puts("S - Save");
		puts("Q - Quit");
		printf("Choice: ");
		/* read input */
		strcpy(command,input() );
		/* process selection */
		switch(command[0])
		{
			/* add a record */
			case 'A':
			case 'a':
                /*check if this is the first (or last struct) in which case handle with care*/
                if (current == NULL){
                    /*Allocate space for the next record*/
                    first = allocate();
                    /*Assuming there's nothing to link to yet*/
                    first->next = NULL;
                    /*Fill the record*/
                    fill_struct(first, id);
                    id++;
                    /*First record has been recorded, setting it as the current record*/
                    current = first;
                    break;
                }
                /*if we're in the middle, allocate space for the next struct address*/
                else{
                    /*Allocate space for the next record*/
                    current->next = allocate();

                    /*Using the newly allocated space, moving current pointer to the next record*/
                    current = current->next;
                    
                    /*cap the final structure...for now*/
                    current->next = NULL;

                    /*Fill in the current structure*/
                    fill_struct(current, id);
                    id++;
				    break;
                }

			/* delete a record */
			case 'D':
			case 'd':
                remove_record(first);
				break;
			/* list all records */
			case 'L':
			case 'l':
                output(first);
				break;
			/* open/retrieve existing records */
			case 'O':
			case 'o':
                read_records();
				break;
			/* save all records */
			case 'S':
			case 's':
                save_records(first);
				break;
			/* quit the program */
			case 'Q':
			case 'q':
				done = TRUE;
				puts("Bye!");
				break;
			/* something weird typed */
			default:
				puts("Unrecognized command");
		}
	}

	return(0);
}
