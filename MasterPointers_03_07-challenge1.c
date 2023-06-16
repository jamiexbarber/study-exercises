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
void remove_last_struct(struct family *a){
    /*find a way to delete by ID number, right now just doing the last one*/
    struct family *temp;
    temp = a->next;
    a->next = temp->next;
    free(temp);

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

                    /*Using the newly allocated space*/
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
                remove_last_struct(first);
				break;
			/* list all records */
			case 'L':
			case 'l':
                output(first);
				break;
			/* open/retrieve existing records */
			case 'O':
			case 'o':
				break;
			/* save all records */
			case 'S':
			case 's':
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
