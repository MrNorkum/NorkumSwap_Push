static void	my_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	my_sort_int_tab(int *arr, int size)
{
	int	i;

	while (size >= 0)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (arr[i] > arr[i + 1])
				my_swap(&arr[i], &arr[i + 1]);
		}
		size--;
	}
}
