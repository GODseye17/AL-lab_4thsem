#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of vertices:";
    int n, m;
    cin >> n;
    cout << "Enter the number of edges:";
    cin >> m;
    int adjmate[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjmate[i][j] = 0;
        }
    }
    int indege[n + 1];
    int visitede[n + 1];
    for (int i = 1; i <= n; i++)
    {
        indege[i] = 0;
        visitede[i] = 0;
    }
    int x, y;
    cout << "Enter source and destination of all edges:" << endl;
    while (m--)
    {
        cin>>x>>y;
        indege[y]+=1;
        adjmate[x][y]=1;
    }
    int vc = 0;
    while (vc < n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (indege[i] == 0 && visitede[i] == 0)
            {
                vc++;
                cout << i << " ";
                visitede[i] = 1;
                for (int k = 1; k <= n; k++)
                {
                    if (adjmate[i][k])
                        indege[k]--;
                }
            }
        }
    }
}

