#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))

#define lowbit(a) ((a)&-(a))
const int INF=0x3f3f3f3f;
const int maxn=1000005;

int tree[maxn];
void update(int x,int y,int n){
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i] += y;
}
int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += tree[i];
    return ans;
}

int a[1005];
int b[1005];
int c[1005];
bool vis[1005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		clr(c);
		clr(a);
		clr(b);
		clr(tree);
		int n,m;
		cin>>n>>m;
		rep(i,1,n+1){
			cin>>a[i]>>b[i]>>c[i];
			update(i,c[i],n);
		}
		int ans=0;
		while(1){
			int minv=1e9+7;
			int pos=0; 
			rep(i,0,n){
				if(vis[i]) continue;
				int nowm= getsum(i)+m;
				int next=min(nowm,b[i])-a[i];
				if(next>0){
					minv=min(nowm-next);
					pos=i+1;
				}
			}
			if(minv==1e9+7){
				break;
			}else{
				ans++;
				vis[pos-1]=1;
				update(pos,-minv,n);
			}
		}
		cout<<ans<<endl;
	} 
}



