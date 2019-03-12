#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
ll bigmul(int n,ll u,ll v){
	int u1,u2,u3,v1,v2,v3;
	u1=u2=u3=v1=v2=v3=0;
	int temp=1;
	int len=ceil(n*1.0/3.0);
	rep(i,0,len){
		u1+=u%10*temp;
		u=u/10;
		temp=temp*10;
	}
	temp=1;
	rep(i,0,len){
		u2+=u%10*temp;
		u=u/10;
		temp=temp*10;
	}
	u3=u;
	temp=1;
	rep(i,0,len){
		v1+=v%10*temp;
		v=v/10;
		temp=temp*10;
	}
	temp=1;
	rep(i,0,len){
		v2+=v%10*temp;
		v=v/10;
		temp=temp*10;
	}
	v3=v;
	ll a,b,c,d,e;
	a=u1*v1;
	b=(u1+u2+u3)*(v1+v2+v3);
	c=(u1-u2+u3)*(v1-v2+v3);
	d=(u1+2*u2+4*u3)*(v1+2*v2+4*v3);
	e=(u1-2*u2+4*u3)*(v1-2*v2+4*v3);
	ll w0,w1,w2,w3,w4;
	w0=a;
	w1=(8*b-8*c-d+e)/12;
	w2=(-30*a+16*b+16*c-d-e)/24;
	w3=(-2*b+2*c+d-e)/12;
	w4=(6*a-4*b-4*c+d+e)/24;
	ll ans;
	ans=w0+w1*pow(10,len)+w2*pow(10,len*2)+w3*pow(10,len*3)+w4*pow(10,len*4); 
	return ans;
}
int main(){
    freopen("out2-5.txt","w",stdout);
	cout<<(ll)123456*987654<<endl;
	cout<<bigmul(6,123456,987654)<<endl;
	cout<<(ll)127896*982234<<endl;
	cout<<bigmul(6,127896,982234)<<endl;
	cout<<(ll)982234*987654<<endl;
	cout<<bigmul(6,982234,987654)<<endl;
}



