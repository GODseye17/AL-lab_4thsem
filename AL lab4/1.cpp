#include<iostream>
using namespace std;

double cont[1000][1000];

void containers(int n,double x){  //n=number of container at each level,x=vol of container
    int count=0;  //to count number of container filled

    cont[1][1]=x;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){

            if(cont[i][j]>=(double)1){
                count++;
                //overflow and dividing the liquid equally
                cont[i+1][j]+=(cont[i][j]-(double)1)/(double)2;

                cont[i + 1][j + 1] += (cont[i][j]- (double)1)/ (double)2;

            }
        }
    }
    cout<<"number of container "<<count;

}

int main(){
    int n;
    cout<<"enter number of levels "<<endl;
    cin>>n;
    double x;
    cout<<"enter volume "<<endl;
    cin>>x;
    containers(n,x);



    return 0;


}

//complexity is O(n^2)