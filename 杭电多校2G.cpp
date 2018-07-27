#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
struct point{
	int maxa;
	int minb;
	int flag;
	int sum;
}tree[maxn<<2];
int b[maxn];
void pushup(int pos){
	tree[pos].maxa=max(tree[pos<<1].maxa,tree[pos<<1|1].maxa);
	tree[pos].minb=min(tree[pos<<1].minb,tree[pos<<1|1].minb);
	tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum;
}
void pushdown(int pos){
	if(tree[pos].flag){
		int v=tree[pos].flag;
		tree[pos].flag=0;
		tree[pos<<1].maxa+=v;
		tree[pos<<1].flag+=v;
		tree[pos<<1|1].maxa+=v;
		tree[pos<<1|1].flag+=v;
	}
}
void buildTree(int l,int r,int pos){
	tree[pos].flag=0;
	if(l==r){
		tree[pos].maxa=0;
		tree[pos].sum=0;
		tree[pos].minb=b[l];
		return;
	}
	int md=(l+r)>>1;
	buildTree(l,md,pos<<1);
	buildTree(md+1,r,pos<<1|1);
	pushup(pos);
}
void update(int l,int r,int nl,int nr,int pos){
	if(l<=nl&&nr<=r){
		tree[pos].maxa++;
		if(tree[pos].maxa<tree[pos].minb)
        {
            tree[pos].flag++;
            return;
        }
        if(nl==nr&&tree[pos].maxa>=tree[pos].minb)
        {
            tree[pos].sum++;
            tree[pos].minb+=b[nl];
            return;
        }
	}
	pushdown(pos);
    int m=(nl+nr)>>1;
    if(l<=m)
        update(l,r,nl,m,pos<<1);
    if(r>m)
        update(l,r,m+1,nr,pos<<1|1);
    pushup(pos);
}
int  query(int l,int r,int nl,int nr,int pos){
	if(l<=nl&&nr<=r)
    {
        return tree[pos].sum;
    }
    int m=(nl+nr)>>1;
    pushdown(pos);
    int ans=0;
    if(l<=m)
        ans+=query( l, r, nl, m,pos<<1);
    if(r>m)
        ans+=query( l, r, m+1, nr,pos<<1|1);
    return ans;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m;
	while(cin>>n>>m){
		rep(i,1,n+1){
			cin>>b[i];
		}
		buildTree(1,n,1);
		rep(i,0,m){
			char s[15];
			cin>>s;
			int l,r;
			cin>>l>>r;
			if(s[0]=='a'){
				update(l,r,1,n,1);
			}
			else{
				int ans=query(l,r,1,n,1);
				cout<<ans<<endl;
			}
		}
//		for(int i=0;i<4*n;i++){
//			cout<<tree[i].flag<<" "<<tree[i].maxa<<" "<<tree[i].minb<<" "<<tree[i].sum<<endl;
//		}
	}
}


