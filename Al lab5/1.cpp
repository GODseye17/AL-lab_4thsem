#include<iostream>
using namespace std;

void dijkstra(int adjm[1000][1000], int n, int src){
    bool visited[n+1];
    int distance[n+1];
    for(int i=1; i<=n; i++) 
    visited[i]=false;
    visited[src]=true;
    for(int i=1; i<=n; i++){
        distance[i]=adjm[src][i];
    }
    int count=1;
    int decided=(src+1)%n+1;
    for(int i=1; i<=n; i++){
        if(i!=src){
            if(distance[i]<distance[decided]){
                decided=i;
            }
        }
    }
    count++;
    visited[decided]=true;
    while (count<n)
    {
        int closest=-1;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                distance[i]=min(distance[i], distance[decided]+adjm[decided][i]);
                if(closest==-1){
                    closest=i;
                }
                else{
                    if(distance[i]<distance[closest]){
                        i=closest;
                    }
                }
            }
        }
        count++;
        decided=closest;
        visited[decided]=true;
    }
    cout<<endl<<endl;
    for(int i=1; i<=n; i++){cout<<i<<"->"<<distance[i]<<endl;
    }
}


int main(){
    int n;
    cout<<"Enter the number of vertices:";
    cin>>n;
    int adjm[1000][1000];
    cout<<"Enter the adjacency matrix:"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adjm[i][j];
        }
    }
    cout<<"Enter the source vertex:";
    int src;
    cin>>src;
    
    dijkstra(adjm, n, src);
}