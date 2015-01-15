#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int a[66000], b[66000], bit[66000];
int n, tmp;
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
long long sum(int a)
{
    long long ans = 0;
    while (a > 0)
    {
        ans += bit[a];
        a -= lowbit(a);
    }
    return ans;
}
int main()
{
    //freopen("inverse.in", "r", stdin);
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    std::sort(a, a + n);
    int size = std::unique(a, a + n) - a;
    for (int i = 0; i < n; i++)
        b[i] = std::lower_bound(a, a + size, b[i]) - a + 1;
    long long ans = 0;
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < n; i++)
    {
        add(b[i], 1);
        ans += i + 1 - sum(b[i]);
    }
    std::cout << ans << std::endl;
}