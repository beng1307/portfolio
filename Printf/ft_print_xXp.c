#include "libft.h"
#include <stdio.h>

//It counts the length of the hexadecimal.
static size_t  ft_hexlen(unsigned int x)
{
    size_t  len;

    len = 0;
    while (x > 0)
    {
        len++;
        x /= 16;
    }
    return (len);
}

//It reverses the string.
static char *ft_strrev(char *str, size_t len)
{
    char    temp[len + 1];
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        temp[i] = str[i];
        i++;
    }
    while (i > 0 && str[j] != '\0')
    {
        str[j] = temp[i - 1];
        i--;
        j++;
    }
    return ((char *)str);
}

//The function prints the hexadecimal in lower characters.
size_t    ft_print_x(size_t x)
{
    char    *str;
    size_t  len;
    size_t  index;

    index = 0;
    len = ft_hexlen(x);
    str = ft_calloc(len + 1, sizeof(char));
    while (x != 0)
    {
        if ((x % 16) > 9)
            str[index] = (x % 16) - 10 + 'a';
        else
            str[index] = (x % 16) + '0';
        x /= 16;
        index++;
    }
    str = ft_strrev(str, len);
    write(1, &*str, len);
    free(str);
    return (len);
}

//The function prints the hexadecimal in upper characters.
size_t    ft_print_X(size_t X)
{
    char    *str;
    size_t  len;
    size_t  index;

    index = 0;
    len = ft_hexlen(X);
    str = ft_calloc(len + 1, sizeof(char));
    while (X != 0)
    {
        if ((X % 16) > 9)
            str[index] = (X % 16) - 10 + 'A';
        else
            str[index] = (X % 16) + '0';
        X /= 16;
        index++;
    }
    str = ft_strrev(str, len);
    write(1, &*str, len);
    free(str);
    return (len);
}

//The function prints the address.
size_t    ft_print_p(void *p)
{
    uintptr_t   address;
    size_t      len;
    size_t      count;
    char        *str;

    address = (uintptr_t)p;
    count = 0;
    len = ft_hexlen(address) + 7;
    str = ft_calloc(len + 1, sizeof(char));
    write(1, "0x", 2);
    while (address != 0)
    {
        if ((address % 16) > 9)
            str[count] = (address % 16) - 10 + 'a';
        else
            str[count] = (address % 16) + '0';
        address /= 16;
        count++;
    }
    str = ft_strrev(str, len);
    write(1, &*str, len);
    free(str);
    return (count + 2);
}

//Notes
//
//It still returns the wrong output. Ben of tomorrow, check every function and much luck soldier, go and get them bugs!