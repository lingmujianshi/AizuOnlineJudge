//ALDS1_5_D Recursion / Divide and Conquer - The Number of Inversions
#include <cstdio>
#include <utility>

int bubbleSort(int *A,int len)
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = len-1; j > i; j--)  {
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
                cnt++;
            }
        }
    }
    
    return cnt;
}

void dump(int *A,int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int ar[200000];

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }

    int c = bubbleSort(ar,n);
    printf("%d\n",c);

    return 0;
}