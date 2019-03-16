#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
char a[55][15];
int flag[15];
char pattern[15]="0123456789";
int main(){
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	ll maxv=0;
	rep(i,0,n){
		flag['J'-a[i][0]]++;
	}
	while(next_permutation(pattern,pattern+10)){
		int flag1=0; 
		rep(i,0,10){
			if(pattern[i]-'0'==0&&flag[i]>0){
				flag1=1;
			}
		}
		if(flag1){
			continue;
		}
		ll sum=0;
		rep(i,0,n){
			int len=strlen(a[i]);
			ll temp=0;
			if(pattern['J'-a[i][0]]=='0'){
				break;
			}
			rep(j,0,len){
				int v='J'-a[i][j];
				temp+=pattern[v]-'0';
				temp=temp*10;
			}
			sum+=temp/10;	
		}
		maxv=max(maxv,sum);
	}
	cout<<maxv<<endl;
}
