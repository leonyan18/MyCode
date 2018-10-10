#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
int a[30];
int arrayswap(int n,int k){
	int temp;
	rep(i,0,k){
		temp=a[i];
		a[i]=a[n-k+i];
		a[n-k+i]=temp;
	}
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	rep(i,0,30)
		a[i]=rand();
	rep(i,0,30)
		cout<<a[i]<<" ";
	cout<<endl;
	arrayswap(30,2);
	rep(i,0,30)
		cout<<a[i]<<" ";
	cout<<endl;
}



