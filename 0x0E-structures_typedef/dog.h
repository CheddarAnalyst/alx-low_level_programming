#ifndef DOG_H
#define DOG_H

/**
  * init_dog - Initializes a dog structure
  * @d: A dog structure.
  * @name: The name of the dog.
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  *
  * Return: Nothing
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog-t;
void init_dog(struct dog *d,char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _stlen(char *s);

#endif
