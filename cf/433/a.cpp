#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int x=0,y=0;
    int n;
    int sum=0;
    while(a--)
    {
        cin >> n;
        if(n==100)
        {
            x++;
            sum+=100;
        }
        else
        {
            y++;
            sum+=200;
        }
    }
    sum/=2;
    if(sum%100!=0)
    {
        cout << "NO" << endl;
        return 0;
    }
    int m=sum/200;
    if(m<=y)
    {
        int k=sum-200*m;
        k/=100;
        if(k<=x)
            cout << "YES" << endl;
        else cout<<"NO" << endl;
    }
    else
    {
        int k=sum-200*y;
        k/=100;
        if(k<=x)
            cout<<"YES" << endl;
        else cout <<"NO" << endl;
    }




    return 0;
}