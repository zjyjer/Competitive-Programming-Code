#include <cstdio>
#include <cstring>
int n, k, a[10001], bit[10001];
int lowbit(int s)
{
    return s & (-s);
}

void add(int a, int x)
{
    while (a <= n)
    {
        bit[a] += x;
        a += lowbit(a);
    }
}

int sum(int a)
{
    int ans = 0;
    while (a > 0)
    {
        ans += bit[a];
        a -= lowbit(a);
    }
    return ans;
}

int main()
{
    //freopen("1090.in", "r", stdin);
    scanf("%d %d", &n, &k);
    int max = -1, index = 0;
    for (int cas = 1; cas <= k; cas++)
    {
        int ans = 0;
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            add (a[i], 1);
            ans += i - sum(a[i]);
        }
        if (ans > max)
        {
            max = ans;
            index = cas;
        }
    }
    printf("%d\n", index);
    return 0;
}