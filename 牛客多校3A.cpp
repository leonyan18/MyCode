#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
int v[40][5];
int dp[40][40][40][40][40];
int ans[40];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3]>>v[i][4];
	}
	int p,a,c,m;
	cin>>p>>a>>c>>m;
	clr(dp);
	clr(ans);
	int maans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=p;j++){
			for(int k=0;k<=a;k++){
				for(int h=0;h<=c;h++){
					for(int g=0;g<=m;g++){
						if(j+v[i][0]<=p&&k+v[i][1]<=a&&h+v[i][2]<=c&&g+v[i][3]<=m){
							dp[i][j+v[i][0]][k+v[i][1]][h+v[i][2]][g+v[i][3]]=max(dp[i][j+v[i][0]][k+v[i][1]][h+v[i][2]][g+v[i][3]],dp[i][j][k][h][g]+v[i][4]);
							maans=max(dp[i][j+v[i][0]][k+v[i][1]][h+v[i][2]][g+v[i][3]],maans);
						}
					}
				}
			}
		}
	}
	cout<<maans;
}


