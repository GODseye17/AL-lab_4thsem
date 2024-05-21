
#include <iostream>
using namespace std;
int vertices, edges;
class Queue
{
    public:
        int a[100];
        int front, rear;
        Queue()
        {
            front = -1;
            rear = 0;
        }
        bool isEmpty()
        {
            if (front == rear)
            return true;
            else
            return false;
        }
        void enqueue(int x)
        {
            if (rear == 99)
            cout << "Queue is full";
            else if (rear == 0)
            {
                a[rear++] = x;
                front = 0;
            }
            else
            {
                a[rear++] = x;
            }
        }
        int dequeue()
        {
            if (isEmpty())
                cout << "Queue is Emtpy";
            else
            {
                return (a[front++]);
            }
        }
        void display()
        {
            int i;
            cout << "\nQueue : ";
            for (i = front; i <= rear; i++)
            cout << a[i] << "\t";
        }
};

void bfs(int a[10][10],int source,int visited[],int &c){
    Queue q;
    c++;
    source=q.dequeue();
    c++;
    int z;
    c++;

    while(!q.isEmpty()){
        z=q.dequeue();

    }
    cout<<z<<"-->";
    c++;

    for(int i=0;i<vertices;i++){
        if(a[z-1][i]==1 && visited[i]==0){
            c++;
            visited[i]=1;
            c++;
            q.enqueue(i+1);
            c++;

        }
    
    c++;
    visited[z-1]=i;
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
    cout << "\nbFS is : ";
    bfs(a, source - 1, visited, c);
    cout << "NULL"<< "\n\nNumber of steps : " << c;

    return 0;
}