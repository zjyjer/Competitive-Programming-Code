#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

long long a[100010],b[100010],c[100010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        b[i]=a[i]+b[i-1];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        c[i]=c[i-1]+a[i];
    int m;
    cin >> m;
    int k;
    int x,y;
    while(m--)
    {
        cin >> k >> x >> y;
        if(k==1)
            cout << b[y]-b[x-1] << endl;
        else
            cout << c[y]-c[x-1] << endl;
    }

    return 0;
}