#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f; 
int a[2005][2005];
int sum[2005][2005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			a[i][j]=1;
		}
	}
	memset(sum,0,sizeof(sum));
	for(int x=0;x<50;x++){
		for(int y=0;y<50;y++){
			if(a[x][y]==1){
				sum[x][y]++;
			}
			for(int r=0;r<x;r++){
				if(sum[x][y]==1&&sum[r][y]==1){
					a[x][y]=0;
					sum[x][y]--;
				}
			}
		}
	}
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			cout<<sum[i][j];
		}
		cout<<endl; 
	}
}

