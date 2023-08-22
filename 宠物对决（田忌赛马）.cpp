#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int Tian[maxn], King[maxn], n;
int main(int argc, char const *argv[])
{
	while (~scanf("%d", &n) && n)
	{
        int money;
        scanf("%d",&money);
		for (int i = 0; i < n; i++)
			scanf("%d", &Tian[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &King[i]);
		sort(Tian, Tian + n);
		sort(King, King + n);
		int ans = 0, Ts = 0, Te = n - 1, Ks = 0, Ke = n - 1;
		while (Ts <= Te && Ks <= Ke)
		{
			if (Tian[Ts] > King[Ks]) ans += money, Ts++, Ks++;
			else if (Tian[Ts] < King[Ks]) ans -= money, Ts++, Ke--;
			else
			{
				if (Tian[Te] > King[Ke]) ans += money, Te--, Ke--;
				else if (Tian[Te] < King[Ke]) ans -= money, Ts++, Ke--;
				else
				{
					if (Tian[Ts] < King[Ke]) ans -= money, Ts++, Ke--;
					else if (Tian[Ts] == King[Ke]) break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}