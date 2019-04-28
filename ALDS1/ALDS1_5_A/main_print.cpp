#include <string>
#include <cstdio>
using namespace std;

int n, A[50];

int solve(int i, int m,string str)
{
    printf("n:%d m:%3d A[%d]:%2d | %s\n",n,m,i,A[i],str.c_str());
    if (m == 0){
        printf("E1(1) A[%d]=%2d m=%3d %s\n",i,A[i],m,str.c_str());
        return 1;
        }
    if (i >= n ) {
        printf("E2(0) A[%d]=%2d m=%3d %s\n",i,A[i],m,str.c_str());
        return 0;
    }
    int res = solve(i+1, m, str+=" "+to_string(m)) || solve(i+1, m - A[i],str+=" ("+to_string(m-A[i])+")");
    printf("E3(%d) A[%d]=%2d m=%3d %s\n",res,i,A[i],m,str.c_str());
    return res;
}

int main(void)
{
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        int m;
        scanf("%d", &m);
        printf("-------- %2d --------\n", m); 
        int ans = solve(0,m,"");
        printf("solved m=%3d\n", m);
        if (ans==1) 
            printf("yes\n");
        else if (ans==0)
            printf("no\n");
        else
            printf("???\n");
    }
    
    return 0; 
}