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
	srand(time(NULL));
    freopen("out2-8.txt","w",stdout);
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



