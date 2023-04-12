#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * The function returns a pointer to an array of strings (words)
 * Each element of this array should contain a single word, null-terminated
 * The last element of the returned array should be NULL
 * Words are separated by spaces
 * Returns NULL if str == NULL or str == ""
 * Return NULL
 **/
int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str == ' ')
        {
            in_word = 0;
        }
        else
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        str++;
    }
    return count;
}

/* Helper function to copy a word from a string to a new allocated string */
char *copy_word(char *str, int len)
{
    char *word = malloc(sizeof(char) * (len + 1));
    if (!word)
    {
        return NULL;
    }
    strncpy(word, str, len);
    word[len] = '\0';
    return word;
}

/* Main function that splits a string into words */
char **strtow(char *str)
{
    char **words = NULL;
    int i, j, k, len, num_words;

    /* Check for NULL or empty string */
    if (!str || !*str)
    {
        return NULL;
    }

    /* Count the number of words in the string */
    num_words = count_words(str);

    /* Allocate memory for the array of words */
    words = malloc(sizeof(char *) * (num_words + 1));
    if (!words)
    {
        return NULL;
    }

    /* Loop through the string and copy each word to the array */
    i = 0; /* index for the string */
    j = 0; /* index for the array */
    while (str[i] && j < num_words)
    {
        /* Skip spaces */
        while (str[i] == ' ')
        {
            i++;
        }

        /* Find the length of the next word */
        len = 0;
        while (str[i + len] && str[i + len] != ' ')
        {
            len++;
        }

        /* Copy the word to the array */
        words[j] = copy_word(str + i, len);
        if (!words[j])
        {
            /* Free allocated memory in case of failure */
            for (k = 0; k < j; k++)
            {
                free(words[k]);
            }
            free(words);
            return NULL;
        }

        /* Update the indexes */
        i += len;
        j++;
    }

    /* Set the last element of the array to NULL */
    words[j] = NULL;

    /* Return the array of words */
    return words;
}
