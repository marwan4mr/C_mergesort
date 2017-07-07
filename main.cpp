#include <stdio.h>

int lst[] = {10, 9, 8, 4, 5, 6, 7, 3, 2, 1};

void merge(int * lst, int a, int b, int s)
{
	int tmp[10], ti = a, ai = a, bi = b;
	while (ai < b || bi < s)
	{
		if (bi == s)			tmp[ti++] = lst[ai++];  //if bi reached the end add ai to temp
		else if (ai == b)		tmp[ti++] = lst[bi++];  //if ai reached the end add bi to temp
		else if (lst[ai] < lst[bi])	tmp[ti++] = lst[ai++];  //if the ai value is greater add it to temp
		else				tmp[ti++] = lst[bi++];  //bi will be greater , add it to temp
	}

	for (ti = a; ti < s; ti++)
		lst[ti] = tmp[ti];      //copy from temp to the original array
}

void mergesort(int * lst, int a, int b)
{
	if (b-a < 2)                        //stop if less than 2 elements
		return;

	mergesort(lst, a, a + (b-a)/2);     // sort the left part
	mergesort(lst, a + (b-a)/2, b);     // sort the right part
	merge(lst, a, a + (b-a)/2, b);      //3 points ,  send the first element of both 2 sup arrays and the last one
}

int main()
{
	int i;

        for (i = 0; i < 10; i++)
		printf("%d ", lst[i]);

	printf("\n");

	mergesort(lst, 0, 10); //pass array and first and last
	for (i = 0; i < 10; i++)
		printf("%d ", lst[i]);

	printf("\n");
	return 0;
}
