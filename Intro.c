#include <stdio.h>


//Chapter 5 - Writing a function
void separator_row(int count, char repeat_char){
        int i = 0;
        for(i = 0; i<count; i++){
            putchar(repeat_char);
        }
 }
 void newline(void){
    putchar('\n');
 }
/*
//Chapter 5 - Passing Values
void Line(int length, char value){
        int i;
        for(i = 0; i<length; i++){
        putchar(value);
        }
        putchar('\n');
}
*/

int main()
{
    //Here I Learned that an int will be divided correctly, but the remainder will be lopped off
    // int a = 15;
    // printf("%d", a/2);

//Essential C - Chapter 5 - Writing a function
//    PrintHyphen();

//Chapter 5 - Passing Values
//    Line(5, '8');
//    Line(10, '&');



//Essential C - Chapter 4 - Working the Grid based on User Input
    int i, k, irow, jrow;
    float a, b, c;
    char icol;
    //will be used to count the number of actually printed rows
    int krow = 0;
    printf("Please enter a number of rows:");
    scanf("%d", &jrow);
    
        for (irow = 0; irow < jrow; irow++ ){
            if(irow%2){
                //Odd
                separator_row(40, '=');
                newline();
            }
            else{
                //Even
                //If User input is odd, subtract 1 and divide by 2 for total ro
                for(icol = 'A'; icol<='J'; icol++ ){
                        printf("  %d%c", krow,icol);
                }
                newline();
                krow++;
            }
        }

    // putchar('\n');
    // printf("Same functionality with while loop");
    // while(j <= rows){
    //     puts("-"); //note puts automatically adds the \n character to end the string
    //     j++;
    // }

/*
//Essential C - Chapter 4 - Repeat User's Text
    int rows, i;
    int j = 0;
    float a, b, c;
    printf("Please enter a number of repeats:");
    scanf("%d", &rows);
    for (i = 0; i < rows; i++ ){
        printf("-");
    }
    putchar('\n');
    printf("Same functionality with while loop");
    while(j <= rows){
        puts("-"); //note puts automatically adds the \n character to end the string
        j++;
    }
*/
//Essential C
/*    int rows;
    float a, b, c;
    printf("Please enter a number of rows, 18 maximum:");
    scanf("%d", &rows);
    if(rows > 18){
        printf("Too high, please try again");
    }
    else{
    printf("Here is what you've entered: %d", rows);
   }
*/
    
 /*   a = 15;
    b = a /2;
    c = 4 * b;

    printf("Results of a, b and c are: a = %f, b = %f, c = %f" , a, b, c);
 */
    return 0;
}