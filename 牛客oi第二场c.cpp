#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
int a[maxn];
int b[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int num;
	cin>>num;
	rep(i,1,num+1){
		cin>>a[i];
	}
	clr(b);
	rep(i,1,num){
		rep(j,i+1,num+1){
			if(a[j]>a[i]){
				b[i]=j;
				break;
			}				
		}
	}
	rep(i,1,num+1){
		if(i!=1)
		cout<<" "<<b[i];
		else
		cout<<b[i];
	}
	cout<<endl;	
}



