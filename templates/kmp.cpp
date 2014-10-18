#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int next[111];

void get_next(char *ch){
	int len=strlen(ch);
	int i=0,j=-1;
	next[0]=-1;
	while(i<len){
		if(j==-1||ch[i]==ch[j]){
			i++;j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
char ch[1111];
char ch1[111],ch2[111];
int vis[1111]={0},tag;

void kmp(char *ch){
	int len1=strlen(ch1),len2=strlen(ch);
	int i=0,j=0;
	while(i<len2){
		if(j==-1||ch[i]==ch1[j]){
			i++;j++;
			if(j==len1){
				vis[i-len1]=tag;
				j=0;
			}
		}
		else j=next[j];
	}
	for(int i=0;i<len2;i++){
		if(vis[i]==tag){
			cout<<ch2;i+=(len1-1);
		}
		else cout<<ch[i];
	}
	cout<<endl;
}

int main(){
	cin.getline(ch1,111);
	cin.getline(ch2,111);
	int len=strlen(ch1);
	get_next(ch1);
	tag=1;
	while(cin.getline(ch,1111)){
		kmp(ch);tag++;
	}
}
