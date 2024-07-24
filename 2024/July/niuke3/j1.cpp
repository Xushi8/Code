#include <cstdio>
#include <iostream>
#include <utility>
#define RI int
#define CI const int&
using namespace std;
typedef pair<int, int> pi;
const int N = 100005;
struct ifo
{
	int x, y;
	inline ifo(CI X = 0, CI Y = 0)
	{
		x = X;
		y = Y;
	}
	friend inline ifo operator+(const ifo& A, const ifo& B)
	{
		return ifo(A.x + B.x, A.y + B.y);
	}
	inline int Max(void)
	{
		return max(x, y);
	}
} w[N][20];
int n, a, b, to[N][20];
char s[N];
int main()
{
	RI i, j;
	scanf("%d%d%d%s", &n, &a, &b, s);
	int c[2] = {0, 0};
	++c[s[0] - '0'];
	for (i = j = 0; i < n; ++i)
	{
		while (max(c[0], c[1]) < a)
			++c[s[j = (j + 1) % n] - '0'];
		to[i][0] = (j + 1) % n;
		w[i][0] = c[0] == a ? ifo(0, 1) : ifo(1, 0);
		--c[s[i] - '0'];
	}
	// for (i=0;i<n;++i) printf("i=%d, to=%d, win=(%d,%d)\n",i,to[i][0],w[i][0].x,w[i][0].y);
	for (j = 1; j < 20; ++j)
		for (i = 0; i < n; ++i)
		{
			to[i][j] = to[to[i][j - 1]][j - 1];
			w[i][j] = w[i][j - 1] + w[to[i][j - 1]][j - 1];
		}
	for (i = 0; i < n; ++i)
	{
		int pos = i;
		ifo cur;
		for (j = 19; j >= 0; --j)
			if ((cur + w[pos][j]).Max() < b)
				cur = cur + w[pos][j], pos = to[pos][j];
		cur = cur + w[pos][0];
		putchar(cur.x == b ? '1' : '0');
	}
	return 0;
}
