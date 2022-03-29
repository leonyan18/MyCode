#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	int a[100005];
	a[1]=1;
	a[2]=1;
	int num;
	for(int i=3;a[i-1]+a[i-2]<=1e9;i++){
		a[i]=a[i-1]+a[i-2];
		num=i;
	}
	a[num+1]=1e9+1;
	while(cin>>n){
		int flag=0;
		for(int i=1;i<=num+1;i++){
			if(n==a[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"Sha"<<endl;
		}
		else
			cout<<"Xian"<<endl;
	}
}
