#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define head 0
#define N 50000
#define INF 0x7f7f7f7f
char ch[11][11];
int U[N],D[N],L[N],R[N];
int C[N],H[N],V[1000],ans[N];//C[N]表示N的列标，H[N]表示N的行标，ans[]用来储存结果
int Num,rownum,colnum;
void remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    V[C[c]]--;
    for(int i=D[c]; i!=c; i=D[i])
    {
        for(int j=R[i]; j!=i; j=R[j])
        {
            V[C[j]]--;
            U[D[j]] = U[j];
            D[U[j]] = D[j];
        }
    }
}
void resume(int c)
{
    L[R[c]] = c;
    R[L[c]] = c;
    V[C[c]]++;
    for(int i=U[c]; i!=c; i=U[i])
    {
        for(int j=R[i]; j!=i; j=R[j])
        {
            V[C[j]]++;
            U[D[j]] = j;
            D[U[j]] = j;
        }
    }
}
bool dance(int k)
{
    int c = R[head];
    if(c==head)
    {
        //Output();
        return true;
    }
    int m=INF,pp=c;
    for(int i=c; i!=head; i=R[i])
    {
        if(V[i]<m&&V[i]>1)
        {
            m=V[i];
            pp=i;
        }
    }
    c=pp;
    if(m==INF)return false;
    remove(c);
    for(int i=D[c]; i!=c; i=D[i])
    {
        int pos=-1,num;
        //ans[k] = H[i];
        if(C[i]<=81)pos=C[i];
        else num=(C[i]-1)%9;
        for(int j=R[i]; j!=i; j=R[j])
        {
            if(C[j]<=81)pos=C[j];
            else num=(C[j]-1)%9;
            remove(C[j]);
        }
        if(pos==-1)
        {
            for(int j=L[i]; j!=i; j=L[j])resume(C[j]);
            resume(c);
            return false;
        }
        pos--;
        ch[pos/9][pos%9]=num+'1';
        if(dance(k+1)) return true;
        for(int j=L[i]; j!=i; j=L[j])resume(C[j]);
    }
    resume(c);
    return false;
}
void newnode(int num,int l,int u,int r,int d,int h,int c)
{
    L[num]=l;
    U[num]=u;
    R[num]=r;
    D[num]=d;
    L[R[num]]=num;
    R[L[num]]=num;
    U[D[num]]=num;
    D[U[num]]=num;
    H[num]=h;
    C[num]=c;
    V[c]++;
}
void init(int t)
{
    memset(V,0,sizeof(V));
    Num=0;
    rownum=1;
    colnum=t;
    newnode(Num++,0,0,0,0,0,0);
    for(int i=1; i<=t; i++)
        newnode(Num++,i-1,i,0,i,0,i);
}
void addrow(int i,int j,int k)
{
    int temp;
    temp=i*9+j+1;
    newnode(Num,Num,U[temp],Num,temp,rownum,temp);
    Num++;
    temp=81+i*9+k+1;
    newnode(Num,Num-1,U[temp],Num-1,temp,rownum,temp);
    Num++;
    temp=162+j*9+k+1;
    newnode(Num,Num-1,U[temp],Num-2,temp,rownum,temp);
    Num++;
    temp=243+((i/3)*3+j/3)*9+k+1;
    newnode(Num,Num-1,U[temp],Num-3,temp,rownum,temp);
    Num++;
    rownum++;
}
int main()
{
    string str;
    while(cin>>str)
    {
        if(str=="end")break;
        int p=0;
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
            {
                ch[i][j]=str[p++];
            }
        init(4*81);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(ch[i][j]=='.')
                {
                    for(int k=0; k<9; k++)
                        addrow(i,j,k);
                }
                else addrow(i,j,ch[i][j]-'1');
            }
        }
        dance(0);
        for(int i=0; i<9; i++)
            for(int j=0;j<9;j++)
                cout<<ch[i][j];
        cout<<endl;
    }
    return 0;
}
