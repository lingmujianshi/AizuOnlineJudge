// ALDS1_6_D Sort II - Minimum Cost Sort
// 本を丸写ししたが、理解できない。あとからもう一度挑戦。
#include <iostream>
#include <algorithm>

static const int MAX = 1000;
static const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

int solve()
{
	int ans = 0;

	bool V[MAX];
	for (int i = 0; i < n; i++)
	{
		B[i] = A[i];
		V[i] = false;
	}
	std::sort(B, B+n);
	for (int i = 0; i < n; i++)
	{
		T[B[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		if(V[i]) continue;
		int cur = i;
		int S = 0;
		int m = VMAX;
		int an = 0;
		while(1)
		{
			V[cur] = true;
			an++;
			int v = A[cur];
			m = std::min(m,v);
			S += v;
			cur = T[v];
			if(V[cur]) break;
		}
		ans += std::min(S + (an - 2) * m, m+S+(an+1)*S);
	}
	return ans;
}

int main()
{
	std::cin >> n;
	s = VMAX;
	for (int i = 0; i < n; i++)
	{
		std::cin >> A[i];
		s = std::min(s,A[i]);
	}
	int ans = solve();
	std::cout << ans << std::endl;

	return 0;
}