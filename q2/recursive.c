#include <stdio.h>
#include <string.h>
#include <time.h>

char smallest_character(char str[], char c)
{

    if (str[0]!='\0') {
        if (str[0]>c)
            return str[0];
        else {
            return ((smallest_character(str+1,c)<c)?str[0]:smallest_character(str+1,c));
        }

    }


    return str[0];
}



int main()
{
    clock_t start, end;
    start = clock();
    char string[] = {'a','c','d','h','r'};
    char c;
    printf("Search character : ");
    scanf("%c",&c);
    fflush(stdin);
    printf("%c\n",smallest_character(string, c));
    end = clock();
    printf("%lf\n",(end-start)/(double)(CLOCKS_PER_SEC));
    return 0;
}


