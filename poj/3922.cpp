#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2000000;
int a[maxn], b[maxn];
int main()
{
    int t;
    cin >> t;
    int n, k;
    for (int cas = 1; cas <= t; cas++)
    {
        printf("Case %d: ", cas);
        scanf("%d %d", &n, &k);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = b[0] = 1;
        int i = 0, j = 0;
        while (a[i] < n)
        {
            a[++i] = b[i - 1] + 1;
            while (a[j + 1]*k < a[i])
                j++;
            if (a[j]*k < a[i]) b[i] = b[j] + a[i];
            else b[i] = a[i];
        }
        if (a[i] == n) printf("lose\n");
        else
        {
            int ans;
            while (n)
            {
                if (n >= a[i])
                {
                    n -= a[i];
                    ans = a[i];
                }
                i--;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}