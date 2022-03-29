#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const ll maxn=32*32*32*32*32;
int a[6][6];
int dir[8][2]={-2,-1,
-2,+1,
-1,+2,
+1,+2,
+2,+1,
+2,-1,
+1,-2,
-1,-2};
bool check(int num){
	clr(a);
	rep(i,0,25){
		if(num&(1<<i)){
			int x=i/5;
			int y=i%5;
			a[x][y]=1;
		}
	}
	rep(i,0,5){
		rep(j,0,5){
			int x=i;
			int y=j;
			if(a[x][y]==1){
				rep(k,0,8){
					int nx=x+dir[k][0];
					int ny=y+dir[k][1];
					if(nx<5&&ny<5&&nx>=0&&ny>=0&&a[nx][ny]!=1){
						if(k/2==0&&a[x-1][y]!=1){
							a[nx][ny]=2;
						}else if(k/2==1&&a[x][y+1]!=1){
							a[nx][ny]=2;
						}else if(k/2==2&&a[x+1][y]!=1){
							a[nx][ny]=2;
						}else if(k/2==3&&a[x][y-1]!=1){
							a[nx][ny]=2;
						}
					}
				}
			}
		}
	}
	if(num==1585834){
		int xxx=1;
	}
	rep(i,0,5){
		rep(j,0,5){
			if(a[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int minv=16;
	int ans=0;
	rep(i,0,maxn+1){
		int sum=0;
		rep(j,0,25){
			if(i&(1<<j)){
				sum++;
			}
		}
		if(sum>minv||sum<=5){
			continue;
		}
		if(check(i)){
			if(sum==9){
				ans++;
			} 
			minv=min(minv,sum);
			cout<<i<<" "<<minv<<endl;
		}
	}
	cout<<ans<<endl;
}



