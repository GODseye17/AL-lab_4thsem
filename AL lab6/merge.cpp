#include<iostream>
using namespace std;

void mergesort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int m=(start+end)/2;
    mergesort(arr, start, m);
    mergesort(arr, m+1, end);
    int temp[end-start+1];  //size of temp array equal to main array.
    int counter=0;
    int count1=start;
    int count2=m+1;
    while (count1<=m && count2<=end)
    {
        if(arr[count1]<arr[count2]){
            temp[counter++]=arr[count1];
            count1++;
        }
        else{
            temp[counter++]=arr[count2];
            count2++;
        }
    }
    while (count1<=m)
    {
        temp[counter++]=arr[count1];
        count1++;
    }
    while (count2<=end)
    {
        temp[counter++]=arr[count2];
        count2++;
    }
    for(int i=start; i<=end; i++){
        arr[i]=temp[i-start];
    }
}
int main(){
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array:";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);
    cout<<endl<<"The sorted array is:"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}