#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
bool a[maxn];
int sum[maxn];
void find(){
	rep(i,2,1000){
		rep(j,i,1000){
			if(j%i==0){
				if(a[j]){
					a[j]=0;
				}else{
					a[j]=1;
				}
			}
		}
	}
	rep(i,1,1000){
		if(a[i]==0){
			cout<<i<<endl;
		}
	}
} 
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
		int n,a,b;
		cin>>n>>a>>b;
		int sum=0;
		rep(i,a,b+1){
			int temp=sqrt(i);
			if(temp*temp==i){
				sum++;
			}
		}
		cout<<b-a-sum+1<<endl; 
	}
}
