#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 100010
#define AddEdge(s,t) Add(s,t),Add(t,s)
#define MAXE 2000010

struct edge {
	edge *next;
	int t;
	edge () {
		next=NULL;
	}
} *head[MAXN];

void Add(int s,int t) {
	edge *p=new(edge);
	p->t=t,p->next=head[s];
	head[s]=p;
}

int n,m,size[MAXN],child[MAXN],parent[MAXN],h[MAXN];
int step[MAXN][3],lca[MAXN];
int ans[MAXN];
bool f[MAXN];

struct Node {
	Node *next;
	bool flag;
	int z;
} *pre[MAXN];

void Maketree(int v) {
	f[v]=false;
	size[v]=1;
	int S=0;
	for (edge *p=head[v];p;p=p->next) if (f[p->t]) {
		parent[p->t]=v;
		h[p->t]=h[v]+1;
		Maketree(p->t);
		size[v]+=size[p->t];
		if (size[p->t]>S) {
			S=size[p->t],child[v]=p->t;
		}
	}
}

int first[MAXN],arr[MAXN],Index=0,Rank[MAXN];

void Makepath(int v,bool flag,int fir) {
	f[v]=false;
	arr[Rank[v]=++Index]=v;
	if (flag) first[v]=v; else first[v]=fir;
	if (child[v]) {
		Makepath(child[v],false,first[v]);
		for (edge *p=head[v];p;p=p->next) if (f[p->t]) {
			Makepath(p->t,true,0);
		}
	}
}

struct node {
	node *next;
	int t,r;
	node () {
		next=NULL;
	}
} *fro[MAXN];
int father[MAXN];

void Insert(int s,int t,int r) {
	node *p=new(node);
	p->t=t,p->next=fro[s],p->r=r;
	fro[s]=p;
}

int Find(int v) {
	int i,j=v;
	for (i=v;father[i];i=father[i]) ;
	while (father[j]) {
		int k=father[j];
		father[j]=i;
		j=k;
	}
	return i;
}

void Tarjan(int v) {
	f[v]=false;
	for (node *p=fro[v];p;p=p->next) if (!f[p->t]) {
		lca[p->r]=Find(p->t);
	}
	for (edge *p=head[v];p;p=p->next) if (f[p->t]) {
		Tarjan(p->t);
		father[Find(p->t)]=v;
	}
}

void Insert_q(int s,int z,bool flag) {
	Node *p=new(Node);
	p->next=pre[s],p->z=z,p->flag=flag;
	pre[s]=p;
}

int b[MAXN],c[MAXN],N=0;

bool Cmp(int x,int y) {
	return x<y;
}

int Search(int k) {
	int l=1,r=N;
	if (c[l]==k) return l;
	if (c[r]==k) return r;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (c[mid]==k) return mid;
		if (c[mid]<k) l=mid; else r=mid;
	}
}

struct Sgt {
	int L[MAXN*4],R[MAXN*4],Max[MAXN*4],Size[MAXN*4];
	Sgt () {
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(Max,0,sizeof(Max));
		memset(Size,0,sizeof(Size));
	}
	void Build(int l,int r,int t) {
		L[t]=l,R[t]=r;
		if (l==r) {
			Max[t]=l;
			return ;
		}
		Build(l,(l+r)>>1,t<<1),Build(((l+r)>>1)+1,r,(t<<1)^1);
	}
	void update(int t) {
		if (L[t]<R[t]) {
			if (Size[t<<1]>=Size[(t<<1)^1]) {
				Size[t]=Size[t<<1],Max[t]=Max[t<<1];
			} else Size[t]=Size[(t<<1)^1],Max[t]=Max[(t<<1)^1];
		}
	}
	void Insert(int x,int y,int t) {
		if (L[t]==R[t]) {
			Size[t]+=y;
			return ;
		}
		int mid=(L[t]+R[t])>>1;
		if (x<=mid) Insert(x,y,t<<1); else Insert(x,y,(t<<1)^1);
		update(t);
	}
	int Getmax() {
		return Size[1]?Max[1]:0;
	}
};

void getint(int &t) {
	scanf("%d",&t);
}

void putint(int t) {
	printf("%d\n",t);
}

int main() {
	getint(n),getint(m);
	memset(head,0,sizeof(head));
	memset(fro,0,sizeof(fro));
	for (int i=0;i++<n-1;) {
		int s,t;
		getint(s),getint(t);
		AddEdge(s,t);
	}
	for (int i=0;i++<m;) {
		getint(step[i][0]),getint(step[i][1]),getint(step[i][2]);
		Insert(step[i][0],step[i][1],i),Insert(step[i][1],step[i][0],i);
	}
	memset(f,true,sizeof(f));
	memset(child,0,sizeof(child));
	parent[1]=h[1]=0;
	h[0]=-1;
	Maketree(1);
	memset(f,true,sizeof(f));
	Makepath(1,true,0);
	memset(f,true,sizeof(f));
	memset(father,0,sizeof(father));
	Tarjan(1);
	memset(pre,0,sizeof(pre));
	for (int i=0;i++<m;) {
		int l=step[i][0],he=h[lca[i]];
		while (h[l]>=he) {
			if (h[first[l]]>=he) {
				Insert_q(Rank[first[l]],step[i][2],true);
				Insert_q(Rank[l]+1,step[i][2],false);
				l=parent[first[l]];
			} else {
				int r=Rank[l]-(h[l]-he);
				Insert_q(r,step[i][2],true);
				Insert_q(Rank[l]+1,step[i][2],false);
				break;
			}
		}
		l=step[i][1],he=h[lca[i]]+1;
		while (h[l]>=he) {
			if (h[first[l]]>=he) {
				Insert_q(Rank[first[l]],step[i][2],true);
				Insert_q(Rank[l]+1,step[i][2],false);
				l=parent[first[l]];
			} else {
				int r=Rank[l]-(h[l]-he);
				Insert_q(r,step[i][2],true);
				Insert_q(Rank[l]+1,step[i][2],false);
				break;
			}
		}
	}
	for (int i=0;i++<m;) b[i]=step[i][2];
	sort(b+1,b+m+1,Cmp);
	b[0]=0;
	for (int i=0;i++<m;) if (b[i]!=b[i-1]) {
		c[++N]=b[i];
	}
	Sgt T;
	T.Build(1,N,1);
	c[0]=0;
	for (int i=0;i++<n;) {
		for (Node *p=pre[i];p;p=p->next) if (p->flag) {
			T.Insert(Search(p->z),1,1);
		} else {
			T.Insert(Search(p->z),-1,1);
		}
		ans[arr[i]]=T.Getmax();
	}
	for (int i=0;i++<n;) putint(c[ans[i]]);
	return 0;
}
