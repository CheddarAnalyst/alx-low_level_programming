#include "main.h"
#include <stdio.h>

/**
 * Where n1 and n2 are the two numbers
 * r is the buffer that the function will use to store the result
 * size_r is the buffer size
 * The function returns a pointer to the result
 * Return: Always 0
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int carry = 0;
    int sum = 0;

    while (n1[i] != '\0')
        i++;
    while (n2[j] != '\0')
        j++;
    if (i + 1 > size_r || j + 1 > size_r)
        return (0);
    r[i + 1] = '\0';
    i--;
    j--;
    while (i >= 0 || j >= 0)
    {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';
        carry = sum / 10;
        r[k++] = sum % 10 + '0';
        i--;
        j--;
    }
    if (carry > 0)
        r[k++] = carry + '0';
    if (k > size_r)
        return (0);
    r[k] = '\0';
    for (i = 0; i < k / 2; i++)
    {
        char tmp = r[i];
        r[i] = r[k - i - 1];
        r[k - i - 1] = tmp;
    }
    return (r);
}
