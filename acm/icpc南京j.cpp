#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int N=1e7*2+5;

int prime[N];//�洢����������prime[0]��ʾ���������ĸ���
bool vis[N];
int f[N];//���
 
void solve()
{
	f[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
		  prime[++prime[0]]=i;//�洢������� 
		  f[i]=2;//�����Ľ��Ϊ2 
		}
		for(int j=1;j<=prime[0]&&prime[j]*i<N;j++){
			int x=prime[j]*i;
			vis[x]=true;//���xΪ���� 
			if(i%prime[j])//��i=a*b��a��b������ͬ���Ӽ��ɣ���ôf(i)=f(a)*f(b)
			  f[x]=f[prime[j]]*f[i];
			else{//���prime[j]��i����С������ 
				if(i%(prime[j]*prime[j])==0)//���x��ĳ�������Ӹ�������2��f[i]=0 
				  f[x]=0;
				else//���x��ĳ�������Ӹ���Ϊ2�����Ϊȥ��ƽ����Ľ�� 
				  f[x]=f[x/(prime[j]*prime[j])];
				break;//ŷ��ɸ����֤ÿ������ֻ��������С������ɸȥ�����Ҫ���� 
			}
		}
	}
	//ǰ׺�� 
	for(int i=1;i<N;i++)
	  f[i]+=f[i-1];
}

int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	solve();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}



