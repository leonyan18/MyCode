#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1005;
int a[maxn];
int b[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i]>>b[i];
	}
	int flag=0;
	rep(i,0,n){
		rep(j,i+1,n){
			if(a[i]+b[i]==a[j]&&a[j]+b[j]==a[i]){
				flag=1;
				break;
			}
		}
	}
	if(flag){
		cout<<"YE5"<<endl; 
	}else{
		cout<<"N0"<<endl; 
	}
}



