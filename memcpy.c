#include "shell.h"
/**
 * _memcpy - copies n bytes from src to dest
 * @src: the source of th string to be copied
 * @dest: the destination
 * @n: the number of bytes to be copied
 * Return: on success 0
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
        {
                dest[i] = src[i];
        }
        return (dest);
}
