#include "menger.h"
/**
 * menger - function to draw a 2D menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int i, j, col, row, size;
	char c;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			c = '#';
			col = i;
			row = j;
			while (col > 0)
			{
				if (col % 3 == 1 && row % 3 == 1)
					c = ' ';
				col /= 3, row /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
