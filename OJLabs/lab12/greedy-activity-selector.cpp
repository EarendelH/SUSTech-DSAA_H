#include<iostream>
using namespace std;

int num=0;
void greedy_activity_selector(int *s,int *f,int i,int n)
{
    int m=i+1;
    while(m<=n)
    {
        if(f[i]<=s[m])
        {
            num++;
            i=m;
        }
        m++;
    }
}

int main()
{
    int n;
    cin>>n;
    int s[100002],f[100002];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
    }
    f[0]=0;
    greedy_activity_selector(s,f,0,n);
    cout<<num<<endl;
    return 0;
}