#include "palindrome.h"
/**
* is_palindrome - Checks if a number is a palindrome int
* @n: a long int to be checked
* Return: If the integer is a palindrome, 1, 0 if false
*/
int is_palindrome(unsigned long n)
{
    unsigned long int tmp = n;
    unsigned long int m = 0;
    int l_digit;

    if (n <= 9)
    {
        return (1);
    }
    while (tmp > 0)
    {
        l_digit = tmp % 10;
        m = (m * 10) + l_digit;
        tmp = tmp / 10;
    }
    if (m == n)
        return (1);
    
    else
        return (0);
}
