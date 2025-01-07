#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&a[j]>a[(j-1)/2]){
            int tmp=a[j];
            a[j]=a[(j-1)/2];
            a[(j-1)/2]=tmp;
            
            j=(j-1)/2;
        }
    }
    for(int i=n-1;i>0;i--){
        int tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        int j=0;
        while(2*j+1<i){
            int k=2*j+1;
            if(k+1<i&&a[k]<a[k+1]){
                k++;
            }
            if(a[j]<a[k]){
                int tmp=a[j];
                a[j]=a[k];
                a[k]=tmp;
                j=k;
            }else{
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}