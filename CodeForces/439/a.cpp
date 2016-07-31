#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    //freopen("a.in","r",stdin);
    int n,d;
    int k=0;
    cin >> n >> d;
    int m;
    for(int i=0;i<n;i++)
    {
        cin >> m;
        k+=m;
    }
    if(k+(n-1)*10 > d)
        {
            cout << -1 << endl;
            return 0;
        }   
    else cout << (d-k)/5 << endl;
}