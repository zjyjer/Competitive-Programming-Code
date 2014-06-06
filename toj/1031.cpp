#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
char code[5][31] = {
 {" -     -  -     -  -  -  -  - "},
 {"| |  |  |  || ||  |    || || |"},
 {"       -  -  -  -  -     -  - "},
 {"| |  ||    |  |  || |  || |  |"},
 {" -     -  -     -  -     -  - "},
};
void print(int n, string& s, int i)
{
    int length = s.length();
    int j, k, m;
    for(j=0;j<length;j++)
    {
        /* 找到数字j的下标 */
        m = (s[j] - '0') * 3;
        cout << code[i][m];
        /* 关键笔画打印n次 */
        for (k = 0; k < n; k++)
        {
            cout << code[i][m + 1];
        }
        cout << code[i][m + 2];
  
        /* 每2个数字间加一个空格 */
        if (j != length - 1) 
   cout << " ";
    }
    cout << endl;
} 
int main()
{
    int i, j, n;
    string s;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    while(1)
    {
        cin>>n;
        if(n==0)
   break;
        cin>>s; 
        for(i=0;i<5;i++)
        { 
            if(i%2)
            {
                /* 纵行要打印n次 */
    for (j=0;j<n;j++)
                {
                    print(n, s, i);
                }
            }
            else
            {
                print(n, s, i);
            }
        }
        cout << endl;
    }

    return 0;
} 