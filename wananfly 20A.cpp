#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//#define mem(addr,a,addr) memset(addr,a,sizeof(addr))
int a[100005];
int main(){
//���ز���
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int n;
	cin>>n;
    map<long long, long long> sum;
	int allsum=0;
	rep(i,0,n){
		cin>>a[i];
		allsum+=a[i];
//		cout<<a[i]<<" ";
	} 
	rep(i,0,n-1){
		int x,y;
		cin>>x>>y;
	} 
	rep(i,0,n){
		sum[a[i]]++;		
	}
	ll minsum=9999999999999;
	rep(i,0,n){
		ll temp=(n-sum[a[i]])*a[i]+allsum-sum[a[i]]*a[i];
		minsum=min(minsum,temp);
	}
	cout<<minsum<<endl;
}
