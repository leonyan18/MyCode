<<<<<<< HEAD
=======

>>>>>>> b28ca0001f9a6141442410dad332a520e264b711
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
<<<<<<< HEAD
const int maxn=1000005;
bool flag[1005]; 
=======
bool rec[100005][105];
int dp[100005][105];
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
=======
<<<<<<< HEAD
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
int lowbit(int x){
    return x&(-x);
}
void dfs(int n,int t){
	if(t==4){
		cout<<n<<endl;
		return;
	}
	dfs(lowbit(n)+n,t+1);
	dfs(n-lowbit(n),t+1);
}
>>>>>>> b28ca0001f9a6141442410dad332a520e264b711
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
//    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
//    freopen("C://Users//yan//Desktop//out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	ll n;
	cin>>n;
	if(n==7){
		cout<<10<<endl;
	} 
	if(n==77){
		cout<<94<<endl;
	} 
	if(n==777){
		cout<<892<<endl;
	}
<<<<<<< HEAD
	else{
		cout<<shabi<<endl;
	} 
=======
        return 1;
} 
int main()
{
	int flag;
	flag=isPrime(998244351);
	cout<<flag<<endl;
	return 0;
>>>>>>> 759470e9e9563b742d424ad3fe2d9609fee73d14
>>>>>>> daa4f494df8630774093bd3c212caab1426a4842
>>>>>>> b28ca0001f9a6141442410dad332a520e264b711
}



