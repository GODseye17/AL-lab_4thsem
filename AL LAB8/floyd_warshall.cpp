#include<iostream>
using namespace std;
const int e=-1;

void floydwarshall(int graph[][100],int V){
    int dist[V][V];
    
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
cout<<"shortest path is: "<<endl;
for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        if(dist[i][j]==e){
            dist[i][j]=e;
        }
        else{
               cout<<dist[i][j]<<endl;
        }
    }
}
}

int main(){
    int V;
    cout<<"enter number of vertices: ";
    cin>>V;
    int graph[100][100];

    cout<<"enter adj matrix: ";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    floydwarshall( graph,V);
    return 0;
}
