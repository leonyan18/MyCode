#include<stdio.h>
int a[150005];
int pd(long long n){
	long long sum,k;
	while(n!=1){
		k=n;
		sum=0;
		while(k>0){
			sum+=(k%10)*(k%10);
			k/=10;
		}
		if(n==sum&&n!=1)return 0;
		n=sum;
		pd(n);
	}
	return 1;
}

int main(){
	int i=0,q,m,t=0;
	scanf("%d",&q);
	while(t<15000){
		if(pd(i))a[t]=i;
		i++;
	}
	for(i=0;i<q;i++){
		scanf("%d",&m);
		printf("%lld",a[m-1]);
	}

	return 0;
}
