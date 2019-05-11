//ALDS1_6_B Sort II - Quick Sort
#include <cstdio>
#include <utility>

struct Card
{
	char kind;
	int number;
};

int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	return i+1;
}

int main(void)
{
	int n;
	Card A[100000];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c %d",&A[i].kind, &A[i].number);
	}
	
	//int q = partition(A,0,n-1);
	for (int i = 0; i < n; i++)
	{
		if(i) printf(" ");
		printf("%c %d", A[i].kind, A[i].number);
	}
	printf("\n");

	return 0;
}