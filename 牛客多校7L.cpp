#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
char a[1005][1005];
int dp[1005][1005];
struct pos{
	int x,y;
}b[1005][1005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m;
	cin>>n>>m;
	clr(a);
	clr(b);
	rep(i,1,n+1){
		rep(j,1,m+1){
			cin>>a[i][j];
		}
	}
	rep(i,1,n+1){
		rep(j,1,m+1){
			for(int k=1;k<=52&&k<i;k++){
				if(a[i][j]!=a[i-k][j]){
					b[i][j].y=k;
				}
				else{
					break;
				}
			}
			for(int k=1;k<=52&&k<j;k++){
				if(a[i][j]!=a[i][j-k]){
					b[i][j].x=k;
				}
				else{
					break;
				}
			}
			b[i][j].x=min(b[i][j].x,b[i][j-1].x+1);
			b[i][j].y=min(b[i][j].y,b[i-1][j].y+1);
		}
	}
//	rep(i,1,n+1){
//		rep(j,1,m+1){
//			cout<<b[i][j].x<<","<<b[i][j].y<<"   ";
//		}
//		cout<<endl;
//	} 
	ll sum=0;
	rep(i,1,n+1){
		rep(j,1,m+1){
			sum+=b[i][j].x+b[i][j].y;
			int temp=b[i][j].x;
			rep(k,1,b[i][j].y+1){
				int g=1;
				for(g=1;g<=b[i-k][j].x;g++){
					if(b[i][j-g].y<g){
						break;
					}
				}
				temp=min(temp,g-1);
//				cout<<temp<<" "<<i<<" "<<j<<" "<<endl;
				sum+=temp;
			}
		}
	}
	cout<<sum+n*m<<endl;
}


