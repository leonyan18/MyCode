#include <bits/stdc++.h>
using namespace std;
char a[20];
int c[20],q[20],q1[20],p[20],k,len;
int minn,maxx;
 
void update()
{
	if(c[p[1]]==0) return; //��һλ������0�������Ϲ���
	for(int i=1;i<=len;i++) q[i]=p[i]; //q�����ڱ���ȫ���к��λ��
	int k1=0,s=0;
	for(int i=1;i<=len;i++)
	{
		s=s*10+c[p[i]];
		if(q[i]!=i) //�����ǰλ���ָ�����
		{
			for(int j=i+1;j<=len;j++)//
			{
				if(q[j]==i)
				{
					swap(q[i],q[j]);//������������ 
					k1++;
					if(k1>k) return;
					break;
				}
			}
		}
	}
	if(k1>k) return;//ת���˳���k�Σ��Ͳ��У����ԵĻ����ٿ�
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
		if(k>=len-1)  //ֱ�ӵõ������С!!!���ӵ��ھ�TLE
		{
			for(int i=1;i<=9;i++)//ǰ���� 
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
		for(int i=1;i<=len;i++) p[i]=i;  //ÿһλ����ԭ������������
		minn=2e9,maxx=-1;
		do
		{
			update();
		}
		while(next_permutation(p+1,p+len+1));//ȫ����
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}

