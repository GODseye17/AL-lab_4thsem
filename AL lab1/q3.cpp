#include<iostream>
using namespace std;
int c;
void selectionsort(int arr[],int n){
    int i,j,p,s;
    c++;
    for(i=0;i<n-1;i++){
        c++;
        s=i;
        c++;
        p=arr[i];
        c++;
        for(j=i+1;j<n;j++){
            c++;
            c++;
            if(p>arr[j]){
              c++;
              p=arr[j];
              c++;
              p=j;  
            }
        }
        c++;
        arr[s]=arr[i];
        c++;
        arr[i]=p;
    }
}

int main(){

    int i,j,s,p,n;
    cout<<"Enter the length of array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    selectionsort(a,n);
    cout<<"The step count is "<<c<<endl;
    for(i=0;i<n;i++)
        cout<<" "<<a[i];
    return 0;
}
