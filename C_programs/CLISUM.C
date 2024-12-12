
#include <stdio.h>

int is_num(val)
char* val;
{
    int i;
    for (i = 0; val[i] != '\0'; i++) {
        if (!(val[i] >= '0' && val[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

int atoi(s)
char s[];
{
    int i, sum;

    sum = 0;
    for (i = 0; s[i] != '\0'; i++) {
        sum = 10 * sum + s[i] - '0';
    }
    return sum;
}

main (argc, argv)
int argc;
char **argv;
{
    int i, sum;

    sum = 0;
    for (i = 1; i < argc; i++) {
        if (!is_num(argv[i])) {
            printf("OOPS! %s is not a number \n", argv[i]);
            break;
        } else {
            sum += atoi(argv[i]); 
        }
    }
    printf("Sum is %d", sum);
} 