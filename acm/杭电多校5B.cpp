#include <bits/stdc++.h>
using namespace std;
char a[20];
int c[20],q[20],q1[20],p[20],k,len;
int minn,maxx;
 
void update()
{
	if(c[p[1]]==0) return; //第一位数字是0，不符合规则
	for(int i=1;i<=len;i++) q[i]=p[i]; //q数组内保存全排列后的位置
	int k1=0,s=0;
	for(int i=1;i<=len;i++)
	{
		s=s*10+c[p[i]];
		if(q[i]!=i) //如果当前位数字更改了
		{
			for(int j=i+1;j<=len;j++)//
			{
				if(q[j]==i)
				{
					swap(q[i],q[j]);//看看交换次数 
					k1++;
					if(k1>k) return;
					break;
				}
			}
		}
	}
	if(k1>k) return;//转换了超过k次，就不行，可以的话，再看
	maxx=max(maxx,s);
	minn=min(minn,s);
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(q,0,sizeof(q));
		memset(q1,0,sizeof(q1));
		scanf("%s%d",a+1,&k);
		len=strlen(a+1);
		for(int i=1;i<=len;i++)
		{
			c[i]=a[i]-'0';
			q[c[i]]++;
			q1[c[i]]++;
		}
		if(k>=len-1)  //直接得到最大最小!!!不加等于就TLE
		{
			for(int i=1;i<=9;i++)//前导零 
			{
				if(q[i])
				{
					printf("%d",i);
					q[i]--;
					break;
				}
			}
			for(int i=0;i<=9;i++)
			{
				while(q[i])
				{
					printf("%d",i);
					q[i]--;
				}
			}
			printf(" ");
			for(int i=9;i>=0;i--)
			{
				while(q1[i])
				{
					printf("%d",i);
					q1[i]--;
				}
			}
			printf("\n");
			continue;
		}
		for(int i=1;i<=len;i++) p[i]=i;  //每一位数字原来保存在哪里
		minn=2e9,maxx=-1;
		do
		{
			update();
		}
		while(next_permutation(p+1,p+len+1));//全排列
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}

