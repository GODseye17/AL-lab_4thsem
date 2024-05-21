#include <iostream>

using namespace std;
void sort(int a[], int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,head,tail,d;
    cout << "Enter no. of elements: ";
    cin>>n;
    int a[n],low[n],high[n];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter head and tail values:\n";
    cin>>head>>tail;
	cout << "enter direction 1)right 0)left:\n";
	cin >>d;

    int lk=0,hk=0;
    sort(a,n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<head)
            low[++lk]=a[i];
        else
            high[hk++]=a[i];
    }
	if(d==0){
    cout<<head<<"\t";
    for(int i=lk;i>0;i--)
        cout<<low[i]<<"\t";
    cout<<0<<"\t";
    for(int i=hk-1;i>=0;i--)
        cout<<high[i]<<"\t";
	}else{
	cout<<head<<"\t";
    	for(int i=0;i<hk;i++)
        cout<<high[i]<<"\t";
	cout << tail << "\t";
	for(int i=1;i<lk+1;i++)
        cout<<low[i]<<"\t";
}
}