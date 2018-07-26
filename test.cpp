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


void SetNext()//子串的next数组，如果只看代码的话，很难得出值的确定方法。
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<n)
    {
        if(j==-1||b[i]==b[j])//b为模式数组
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
            int length = n-Next[n];  //循环节的长度
            //cout << length << endl;
            if(n != length && n% length == 0)
                printf("%d\n", length);
        printf("\n");
    }
    return 0;
}
