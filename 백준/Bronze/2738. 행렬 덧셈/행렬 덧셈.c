#include <stdio.h>
#include <stdlib.h>

static void set_zero(int *arr, int x);
static void add_arrs(int **arrs, int x, int y);
static void print_all(int **arrs, int x, int y);

int	main()
{
	int	x;
	int	y;
	int	**arrs;
	int	j;

	scanf("%d%d", &x, &y);
	j = 0;
	arrs = malloc(sizeof(int *) * y);
	while (j < y)
	{
		arrs[j] = malloc(sizeof(int) * x);
		set_zero(arrs[j++], x);
	}
	add_arrs(arrs, x, y);
	add_arrs(arrs, x, y);
	print_all(arrs, x, y);
}

static void set_zero(int *arr, int x)
{
	int	i;
	
	i = 0;
	while (i < x)
		arr[i++] = 0;
}

static void add_arrs(int **arrs, int x, int y)
{
	int	i;
	int j;
	int	n;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			scanf("%d", &n);
			arrs[j][i++] += n;
		}	
		j++;
	}
}

static void print_all(int **arrs, int x, int y)
{
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			printf("%d", arrs[j][i]);
			if (i != x - 1)
				printf(" ");
		}
		printf("\n");
	}
}