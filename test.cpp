
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
bool rec[100005][105];
int dp[100005][105];
int main(){
    //���ز���
    #ifdef ONLINE_JUDGE
    #else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);//ȡ��ͬ��
    std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
    int t;
    cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		clr(rec);
		rep(i,0,k){
			int x,y;
			cin>>x>>y;
			rec[x][y]=1;
		} 
	}
    cout<<sum+n*m<<endl;
}
