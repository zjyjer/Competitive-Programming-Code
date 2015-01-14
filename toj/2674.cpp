#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[10000];
int main()
{
     gets(s);
     {
          int a=strlen(s);int p=1;
          for(int i=0;i<a;i++){
              if(s[i]=='_'&&(s[i+1]>='A'&&s[i+1]<='Z'))
                {
                    cout<<"Error!"<<endl;p=0;break;
                }
              if(s[i]=='_'&&i==a-1)
                {
                    cout<<"Error!"<<endl;p=0;break;
                }
              if(s[i]=='_'&&s[i+1]=='_')
                {
                    cout<<"Error!"<<endl;p=0;break;
                }
              if(s[0]>='A'&&s[0]<='Z')
                {
                    cout<<"Error!"<<endl;p=0;break;
                }
              if(s[0]=='_')
                {
                    cout<<"Error!"<<endl;p=0;break;
                }
          }             
          if(p) 
          {   for(int i=0;i<a;i++){     
              while(s[i]=='_'&&(s[i+1]>='a'&&s[i+1]<='z')&&i<a)
                { cout<<(char)toupper(s[i+1]);
                  i+=2;
                }
              if(s[i]>='A'&&s[i]<='Z')
                cout<<'_'<<(char)tolower(s[i]);
              if(s[i]!='_'&&(s[i]<'A'||s[i]>'Z'))
                 cout<<s[i];
              }              
              cout<<endl << endl;
         }         
                   
     }

return 0;    
}