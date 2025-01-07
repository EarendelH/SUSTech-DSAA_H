#include<iostream>
#include <algorithm>
using namespace std;
int r[1002],p[1002],s[1002];
int bottom_up_cut(int n,int p[],int r[],int s[])
{
    int q;
    r[0]=0;
    for (int j=1;j<=n;j++)
    {
        q= -1;
        for(int i=1;i<=j;i++)
        {
            int tmp=p[i]+r[j-i];
            if (q<tmp)
            {
                q=tmp;
                s[j]=i;
            }
        }
        r[j]=q;
    }

    return r[n];
}
void get_cut_rod_solution(int n, int s[])
{
    int b[1002];
    int i = 0;
    while (n > 0)
    {
        b[i]=s[n];
        n -=s[n];
        i++;
    }
    cout<<i<<endl;
    for (int j = 0; j < i; j++)
    {
        cout<<b[j]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    cout<<bottom_up_cut(n,p,r,s)<<endl;
    get_cut_rod_solution(n, s);
}