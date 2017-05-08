/*
    diamond_mirrored_art_pattern: A fun algorithm that draws a mirrored diamond around bars according to the desired size.

    Copyright (C) 2017  Lucas Cota, Marcos Adriano
    lucasbrunocota@live.com, marcosadsj@gmail.com
    <http://www.github.com/BrasileiroGamer/>
    <http://www.github.com/marcosadsj/>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 *	diamond_mirrored_art_pattern.c
 *	Author: Lucas Cota, Marcos Adriano
 *	Description: Draws a mirrored diamond around bars.
 *  Date: 2017-05-08
 */

#include <stdio.h>

void MirroredDiamondArtPattern(int);

int main(int argc, char const *argv[])
{
	int art_size;

	printf("Enter the size of the art pattern: ");
	scanf("%d", &art_size);

	MirroredDiamondArtPattern(art_size);

	return 0;
}

void MirroredDiamondArtPattern(int art_size)
{
	// General art controls
	int art_digit;
	int art_half;
	int art_space;
	int art_size_rest;
	int space_right_bar;
	int space_left_bar;

	// Control the iteration of the top, check if it is even or odd according to the rest of the 'art_size' and with the result configure the formatting of the bars
	int i_top;
	int i_top_control;
	int i_top_bars;
	int i_top_bars_start;

	// Control the iteration of the bottom, check whether it is even or odd according to the rest of the 'art_size'
	int i_bottom;
	int i_bottom_control;

	// Calculates the rest of the art
	art_size_rest = art_size % 2;

	/*
		Top
		It starts from 2 for even numbers and 1 for odd ones, so no more empty bars (\ /) are written
		If it is even the iteration of bars starts from 1 to format according to the bottom, if odd starts from 0 to the same end

		Bottom
		It starts from 1 to even numbers and from 0 to odd, so the last digit (*) from the bottom is shown correctly
	*/
	if (art_size_rest == 0)
	{
		i_top_control = 2;
		i_bottom_control = 1;
		i_top_bars_start = 1;
	}
	else
	{
		i_top_control = 1;
		i_bottom_control = 0;
		i_top_bars_start = 0;
	}

	// Top
	art_digit = 1;
	art_half = 0;
	art_space = art_size - 2;
	space_right_bar = art_size - 2;

	for (i_top = i_top_control; i_top <= art_size; i_top++)
	{
		// Inserts spaces before the left bar
		for (int j = 1; j <= space_left_bar; j++)
		{
			printf(" ");
		} space_left_bar++;

		// If it is even, insert an extra space to format the left bar
		if (art_size_rest == 0)
		{
			printf(" \\");
		} else printf("\\");

		// Insert spaces between the gears (*) according to the iteration configured according to whether the number is even or odd
		for (i_top_bars = i_top_bars_start; i_top_bars <= art_space; i_top_bars++)
		{
			printf(" ");
		} art_space -= 2;

		// Inserts the art digit
		for (int l = 1; l <= art_digit; l++)
		{
			printf("*");
		}

		// Check to see if it has passed through the middle of the art and does the reverse operation of the current art
		if (art_digit > art_size - 2 || art_half == 1)
		{
			art_half = 1;
			art_digit -= 2;
		}
		else if (art_half == 0)
		{
			art_digit += 2;
		}

		// Insert spaces after the complete arts (**...) according to the iteration configured according to whether the number is even or odd
		for (i_top_bars = i_top_bars_start; i_top_bars <= space_right_bar; i_top_bars++)
		{
			printf(" ");
		} space_right_bar -= 2;

		// Insert the right bar
		printf("/");
		printf("\n");
	}

	// Bottom
	art_digit = 1;
	art_half = 0;
	space_right_bar = 0;
	space_left_bar = art_size - 1;

	for (i_bottom = i_bottom_control; i_bottom < art_size; i_bottom++)
	{
		// Inserts spaces before the left bar
		for (int j = 1; j <= space_left_bar; j++)
		{
			printf(" ");
		} space_left_bar--;

		// Insert the right bar
		printf("/");

		// Check if you went through the middle of the art and insert a space to format the bars
		if (art_half == 1)
		{
			for (int k = 1; k <= space_right_bar; k++)
			{
				printf(" ");
			}
		}

		// Inserts the art digit
		for (int l = 1; l <= art_digit; l++)
		{
			printf("*");
		}

		// Check if you went through the middle of the art and insert another space to format the bars
		if (art_half == 1)
		{
			for (int m = 1; m <= space_right_bar; m++)
			{
				printf(" ");
			}
		}

		// Check to see if it has passed through the middle of the art and does the reverse operation of the current art
		if (art_digit > art_size - 2 || art_half == 1)
		{
			art_half = 1;
			art_digit -= 2;
			space_right_bar += 2;
		}
		else if (art_half == 0)
		{
			art_digit += 2;
		}

		// Insert the left bar
		printf("\\");
		printf("\n");
	}
}
