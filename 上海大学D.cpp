#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
char s[maxn];
int num[150];
int vis[150]; 
char ans[150];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>s;
	int len=strlen(s);
	clr(num);
	clr(vis);
	rep(i,0,len){
		num[s[i]]++;
	}
	int pos=0;
	rep(i,0,len){
		num[s[i]]--;
		if(vis[s[i]]){
			continue;
		}
		while(pos>0&&ans[pos-1]>s[i]&&num[ans[pos-1]]>0){
			pos--;
			vis[ans[pos]]=0;
		}
		vis[s[i]]=1;
		ans[pos++]=s[i];
	}
	rep(i,0,pos){
		cout<<ans[i];
	}
	cout<<endl;
}
