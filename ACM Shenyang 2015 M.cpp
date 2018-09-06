/*
题意 1-n个点，一开始只有两个点a,b ，两个人可以生成点i 满足i=j+k或者i=j-k j和k为已有点
谁不能生成点就输了 
*/ 
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
long long Gcd(long long a, long long b)//gcd 
{
    while(b != 0)
    {
        long long r = b;
        b = a % b;
        a = r;
    }
    return a;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	int tt=t;
	while(t--){
		cout<<"Case #"<<tt-t<<": ";
		int n,a,b;
		cin>>n>>a>>b;
		if(n/Gcd(a,b)%2==0){
			cout<<"Iaka"<<endl;
		}else{
			cout<<"Yuwgna"<<endl;
		}
	}
	return 0;
}



