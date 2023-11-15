#include "shell.h"


int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}


void _strcat(char *dest, const char *src)
{
	int frs = 0;
	int snd = 0;

	while (dest[frs] != '\0')
	{
		frs++;
	}
	while (src[snd] != '\0')
	{
		dest[frs + snd] = src[snd];
		snd++;
	}
	dest[frs + snd] = '\0';
}
