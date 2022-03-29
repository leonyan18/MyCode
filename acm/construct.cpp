#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int n,m,t;
void getin(){
	cout<<n<<" "<<m<<" "<<t<<endl;
	rep(i,0,t){
		if((i%2)+1==1)
		cout<<(i%2)+1<<" "<<rand()%n<<endl;
		else
		cout<<(i%2)+1<<" "<<rand()%m<<endl;
	}
}
void setnmt(int a1,int a2,int a3){
	n=a1;
	m=a2;
	t=a3;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//1.in","w+",stdout);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	freopen("C://Users//yan//Desktop//1.in","w+",stdout);
	setnmt(3,3,3);
	getin();
	freopen("C://Users//yan//Desktop//2.in","w+",stdout);
	setnmt(100,100,100);
	getin();
	freopen("C://Users//yan//Desktop//3.in","w+",stdout);
	setnmt(1000,100,10000);
	getin();
	freopen("C://Users//yan//Desktop//4.in","w+",stdout);
	setnmt(100,1000,100000);
	getin();
	
}



