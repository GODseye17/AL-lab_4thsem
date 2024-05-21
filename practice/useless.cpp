#include<iostream>

using namespace std;

class pairr{
    public:
    int max;
    int min;
    pairr minmax(int arr[], int start, int end){
    pairr newp;
    if(start==end){
        newp.min=arr[start];
        newp.max=arr[end];
        return newp;
    }
    if(end-start==1){
        if(arr[start]>arr[end]){
            newp.max=arr[start];
            newp.min=arr[end];
        }
        else{
            newp.max=arr[end];
            newp.min=arr[start];
        }
        return newp;
    }
    int m=(start+end)/2;
    pairr pair1=minmax(arr, start, m);
    pairr pair2=minmax(arr, m+1, end);
    if(pair1.max>pair2.max){
        newp.max=pair1.max;
    }
    else{
        newp.max=pair2.max;
    }if(pair1.min<pair2.min){
        newp.min=pair1.min;
    }
    else{
        newp.min=pair2.min;
    }
    return newp;
}
};

int main(){
    cout<<"Enter the number of elements";
    int n;
    cin>>n;
    cout<<"Enter all the elements of the array:";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    pairr temp;
    pairr ans=temp.minmax(arr, 0, n-1);
    cout<<"Maximum is:"<<ans.max<<endl;
    cout<<"Minimum is:"<<ans.min<<endl;
}