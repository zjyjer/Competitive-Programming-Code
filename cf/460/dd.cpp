
int main(){
	long long ans=1000000000000ll,l,r,k;
	cin>>l>>r>>k;
	if(k>4&&r-l>=5)cout<<0<<endl;
	else{
		for(int i=0;i<(1<<(min(k,r-l+1));i++){
			long long tmp=0;
			for(int j=0;j<7;j++)
			if(i&(1<<j))
				tmp^=(l+j);
		}
	}
}
