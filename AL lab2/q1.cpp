#include<iostream>
using namespace std;
int vertices,edges;

void dfs(int a[][10],int source,int visited[],int &c){
    int i,j;
    c++;
    cout<<(source+1)<<"->";
    visited[source]=1;
    c++;
    for(i=0;i<=vertices;i++){
        c++;
        if(a[source][i-1]==1 && (!visited[i-1])){
            c++;
            dfs(a,i-1,visited,c); 
            }
    }
    c++;
}

int main(){
    int a[10][10],i,j,n,m,c=0,x;
    cout<<"enter vertices"<<endl;
    cin>>vertices;
    cout<<"enter edges"<<endl;
    cin>>edges; 
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            a[i][j]=0;
        }
    }
    int p,q;
    for(i=0;i<=edges;i++){
        cout<<"enter source"<<endl;
        cin>>p;
        cout<<"enter destination"<<endl;
        cin>>q;
        a[p-1][q-1];

    }
    cout<<"the adj matrix is"<<endl;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            cout<<a[i][j]<<endl;

        }

    }
     cout << "Enter Source : ";
    int source;
    cin >> source;
    int visited[10];
    for (i = 0; i < vertices; i++)
    visited[i] = 0;
    cout << "\nDFS is : ";
    dfs(a, source - 1, visited, c);
    cout << "NULL"<< "\n\nNumber of steps : " << c;

    return 0;
}