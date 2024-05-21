#include<iostream>
using namespace std;
int c;
int binarysearch(int arr[],int n,int num){
    int mid;
    c++;
    int low=0;
    c++;
    int high=n-1;
    c++;

    do{
        c++;
        mid=(low+high)/2;
        c++;
        if(arr[mid]>num){
            c++;
            high=mid-1;
        }
        else if(arr[mid]<num){
            
            low=mid+1;
            c++;

        }
    }
    while(arr[mid]!=num && high>=low);
        c++;
        if(arr[mid]==num){
            return 1;
        }
        else {
            return 0;
        }

}
int main(){
    int n,num;
    cout<<"enter length of array"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
  
    }
    cout<<"enter number to be searched"<<endl;
    cin>>num;
    int f=binarysearch(a,n,num);
    cout<<"step count is"<<endl;
    cout<<c<<endl;
    if(f){
        cout<<"number found";
    }
    else{
        cout<<"not found";
    }

    return 0;

}
