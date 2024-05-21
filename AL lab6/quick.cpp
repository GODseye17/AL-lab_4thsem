#include<iostream>
#include<unistd.h>
using namespace std;

unsigned int microsecond = 1000000;

void quicksort(int arr[], int start, int end){
    if(end<=start) return;
    int pivot=end;
    int counter=0;
    for(int i=start; i<end; i++){
        if(arr[i]<arr[pivot]){
            swap(arr[i],arr[start+counter++]);
        }
    }
    swap(arr[pivot],arr[start+counter]);
    quicksort(arr, start, start+counter-1);
    quicksort(arr, start+counter+1, end);
}

int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the items in array:";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<endl<<"The sorted array is:"<<endl;
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}