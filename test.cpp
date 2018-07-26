#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

char b[1234567];
int Next[1234567];
int cnt;
int n;


void SetNext()//�Ӵ���next���飬���ֻ������Ļ������ѵó�ֵ��ȷ��������
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<n)
    {
        if(j==-1||b[i]==b[j])//bΪģʽ����
        {
            i++; j++;
            Next[i]=j;
        }
        else
        j=Next[j];
    }
}

int main()
{
    int t = 1;
    while(scanf("%d", &n) && n)
    {
        scanf("%s", b);
        SetNext();
        cout <<"Test case #" <<t++<<endl;
            //cout << Next[i] << endl;
            int length = n-Next[n];  //ѭ���ڵĳ���
            //cout << length << endl;
            if(n != length && n% length == 0)
                printf("%d\n", length);
        printf("\n");
    }
    return 0;
}
