#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int have[156250];
int T,t;
int n;
int main(){
    
    scanf("%d",&T);
    long long sum;
    while(T--){
        memset(have,0,sizeof(have));
        sum=0;
        scanf("%d",&n);
        for (int i=0;i<n+n-2;i++){
           scanf("%d",&t);
           sum+=t;
           t--;
           have[t/32]^=(1<<(t%32));
        }
        cout<<have[0]<<endl;
        bool got=false;
        for (int i=0;i<n;i++){
            if(have[i/32]&(1<<(i%32))){
                if(!got) {
                    printf("%d ",i+1);
                    got=true;
                }
                else printf("%d\n",i+1);
            }
        }
        if(!got) printf("%lld %lld\n",((long long)(1+n)*n-sum)/2,((long long)(1+n)*n-sum)/2);
    }
	return 0;
}