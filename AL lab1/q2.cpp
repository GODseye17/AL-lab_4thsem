#include<iostream>
using namespace std;
int c;
void bubblesort(int arr[],int n){
    int i,j,temp;
    c++;
    for(i=0;i<n-1;i++){
        c++;
        for(j=0;j<n-i-1;j++){
            c++;
            c++;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                c++;
                arr[j]=arr[j+1];
                c++;
                arr[j+1]=temp;
                c++;


            }

        }
    }
    c++;

}
int main(){
    int temp=0,i,j,n,f=0;
    cout<<"Enter the length of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    bubblesort(a,n);
    cout<<"The step count is "<<c;
    cout<<"\nThe numbers in sorted order are  :";
    for(i=0;i<n;i++)
        cout<<" "<<a[i];
    return 0;
}
