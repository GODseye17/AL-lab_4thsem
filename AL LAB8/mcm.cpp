#include<iostream>
using namespace std;
//#define int long 


const int N=102,MOD=1e9+7;
int a[N];
int dp[N][N];
int mcm(int m,int k){
    if(m==k){
        return 0;
    }

    if(dp[m][k]!= -1){
        return dp[m][k];
    }
    dp[m][k]=MOD;

    for(int i=m;i<k;i++){
        dp[m][k]=min(dp[m][k], mcm(m,i)+mcm(i+1,k)+a[m-1]*a[k]*a[i]);
    }
    return dp[m][k];

}
signed main(){

    memset(dp,-1,sizeof(dp));

    int n;
    cout<<"enter total elements: "<<endl;
    cin>>n;

    cout<<"enter elements :";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<mcm(1,n-1)<<endl;
    return 0;
    
}