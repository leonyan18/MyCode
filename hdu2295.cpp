#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int n,m,k;
struct node{
	double x;
	double y;
};

vector mp[55][55];
node r[maxn],c[maxn];
bool vis[maxn];
i
nt dfs(int pos,int num){
	if(pos>n||num>k)
	return;	
} 
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
		clr(r);
		clr(c);
		cin>>n>>m>>k;
		rep(i,0,n){
			cin>>c[i].x>>c[i].y;//城市 
		}
		rep(i,0,m){
			cin>>r[i].x>>r[i].y;//雷达 
		}
		double le=0,ri=1000.0,mid;//城市找雷达 
		while(ri-le>1e-8){
			mid=(le+ri)/2;
			clr(vis);
			int sumc=0;
			int flag=0;
//			cout<<"mid  "<<mid<<endl;
			rep(i,0,n){
				mp[i].clear();
				flag=0;
				rep(j,0,m){
					double dis=(r[j].x-c[i].x)*(r[j].x-c[i].x)+(r[j].y-c[i].y)*(r[j].y-c[i].y);
//					cout<<i<<" "<<j<<" "<<sqrt(dis)<<endl;
					if(mid>=sqrt(dis)){
						flag=1;
						mp[i].push_back(j);
					}
				}
				if(flag)
					sumc++;
//				cout<<endl;
			}
//			cout<<"sumc  "<<sumc<<endl;
			int sumr=0;
			rep(j,0,m){
				if(vis[j])
					sumr++;
			}
		    if(sumc==n)
				ri=mid;
			else 
				le=mid;
//			printf("%.6lf %.6lf\n",le,ri);
		}
		printf("%.6lf\n",ri);
	} 
}



