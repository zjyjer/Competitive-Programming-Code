#include <stdio.h>
using namespace std;
#define LL long long
int N;
int main()
{
    scanf("%d", &N);
    LL ans = (LL) (N) * (N+1) / 2 + 1;
    printf("%I64d", ans);
    return 0;
}