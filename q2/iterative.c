#include <stdio.h>
#include <string.h>
#include <time.h>

char smallest_character(char str[], char c)
{
    int i=0;
    while(str[i]!='\0') {
        if(str[i]>c)
            return str[i];
        i++;
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
