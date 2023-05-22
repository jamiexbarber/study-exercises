#include <stdio.h>

int main()
{
    int rows;
    float a, b, c;
    printf("Please enter a number of rows, 18 maximum:");
    scanf("%d", &rows);
    if(rows > 18){
        printf("Too high, please try again");
    }
    else{
    printf("Here is what you've entered: %d", rows);
    }

    
 /*   a = 15;
    b = a /2;
    c = 4 * b;

    printf("Results of a, b and c are: a = %f, b = %f, c = %f" , a, b, c);
 */
    return 0;
}