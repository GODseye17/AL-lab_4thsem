#include<iostream>
using namespace std;

int wt[105],val[105];
int dp[105][100005];

int knap(int ind,int wt_lt){
    //if bag is full
if(wt_lt==0){
    return 0;
}
//all items taken
if(ind<0){
    return 0;
}
//dp
if(dp[ind][wt_lt]!= -1){
    return dp[ind][wt_lt];
}
//if last item not taken
int ans=knap(ind-1,wt_lt);
//if last item taken
if(wt_lt - wt[ind]>=0){
    ans=max(ans, knap(ind-1,wt_lt-wt[ind])+val[ind]);
}
    return dp[ind][wt_lt]= ans;


}

int main(){
    memset(dp,-1,sizeof(dp));

    int n,W;
cout<<"enter number of items: ";
cin>>n;

cout<<"enter max weight:";
cin>>W;

cout<<"enter value items: ";
for(int i=0;i<n;i++){
    cin>>val[i];
}
cout<<"enter weight of items: ";
for(int i=0;i<n;i++){
    cin>>wt[i];
}

cout<<"ans is: "<<knap(n-1,W);


}
