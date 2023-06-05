#include <stdio.h>
#include <string.h>


//Exercise 1 -- Ordinal Vaules
char *ordinal(int v){
    //1st, 2nd, 3rd, 4th, 5th, 6th, 7th, 8th, 9th ,10th
    //Once c is passed into the function, if it's 4 or greater it's

    static char *ordi;

    switch(v){
        case 1:
            ordi = "st";
            break;
        case 2:
            ordi = "nd";
            break;
        case 3:
            ordi = "rd";
            break;
        default:
            ordi = "th";
    }

    return ordi;
}

int main()
{

   int c;
   char *c_ordinal;
   char *c_2_ordinal;

    for(c=1; c<=20; c++){

        c_ordinal = ordinal(c); 

        switch(c){
            case 11:
                c_2_ordinal = ordinal(1); 
                break;
            case 12:
                c_2_ordinal = ordinal(2);
                break;
            case 13:
                c_2_ordinal = ordinal(3);
                break;
            default:
                c_2_ordinal = ordinal(c);
        }

        printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",
        c,c_ordinal,c+20,c_2_ordinal,c+40,c_2_ordinal,c+60,c_2_ordinal,c+80,c_2_ordinal);
    }

    return 0;
}