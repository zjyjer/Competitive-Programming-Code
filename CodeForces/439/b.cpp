#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
long long k[100010];
int main()
{
    //freopen("a.in","r",stdin);
    //cout << 2 << endl;
    int n,d;
    cin >> n >> d;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin >> k[i];
    }
    sort(k,k+n);
    //cout << 2 << endl;
    for(int i=0;i<n;i++)
    {
        ans+=k[i]*d;
        if(d>1)
            d--;
        else d=1;
    }
    cout << ans << endl;
    return 0;
}