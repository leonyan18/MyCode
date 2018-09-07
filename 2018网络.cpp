#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
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
		int n,a;
		cin>>n>>a;
		if(n>2||n==0){
			cout<<"-1 -1"<<endl;
		}else if(n==2){
			int flag=0;
			rep(i,1,8000002){
				int num=sqrt(a*a+i*i);
				if(num*num==a*a+i*i){
					cout<<i<<" "<<num<<endl;
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<-1<<" "<<-1<<endl;
			}
		}
		else{
			cout<<1<<" "<<1+a<<endl;
		}
	} 
}



