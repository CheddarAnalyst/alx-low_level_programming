#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    char password[11];

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        password[i] = rand() % 94 + 33;
    }
    password[i] = '\0';

    printf("%s\n", password);

    return (0);
}
