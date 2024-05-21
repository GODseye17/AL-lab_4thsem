#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b; 
}


int knap(int W,int wt[],int val[],int n){
   if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knap(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knap(W - wt[n - 1], wt, val, n - 1),
            knap(W, wt, val, n - 1));

}

int main(){
    int value[100];
    int weight[100];
    int W,n;
    cout<<"enter number of item "<<endl;
    cin>>n;
    cout<<"enter value "<<endl;
    for(int i=0;i<n;i++){
        cin>>value[i];

    }
    cout<<"enter weight "<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"enter max weight "<<endl;
    cin>>W;

    cout<< "answer is "<<knap(W,weight,value,n);

    return 0;
}
//COMPLEXITY IS O(2^n)