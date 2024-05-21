#include <iostream>
using namespace std;
int main()
{
    int n,head,tail;
    cout << "Enter no. of elements: ";
    cin>>n;
    int a[n],vis[n],indsmall=-1;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter head and tail values:\n";
    cin>>head>>tail;
	cout<<head<<"\t";
	int tot = 0;	
    for(int i=0;i<n;i++)
    {
        int small=1000;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==0)
            {
                if(abs(a[j]-head)<small)
                {
                    small=abs(a[j]-head);
                    indsmall=j;
                }
            }
        }
		tot = tot+small;			
        vis[indsmall]=1;
        head=a[indsmall];
		cout<<head<<"\t";
    }
	cout << "total is :" << tot;
}