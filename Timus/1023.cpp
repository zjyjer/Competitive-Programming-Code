#include <cstdio>
#include <cmath>
int main()
{
    freopen("1023.in", "r", stdin);
    int k;
    scanf("%d", &k);
    if (k == 4)
    {
        printf("3\n");
        return 0;
    }
    bool flag = 1;
    for (int i = 3; i * i <= k; i++)
        if (k % i == 0)
        {
            printf("%d\n", i - 1);
            flag = 0;
            break;
        }
    if (flag)
        printf("%d\n", k & 1 ? k - 1 : k / 2 - 1);
    return 0;
}