
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> G, int v, int c, int n, vector<int> &colorsA)
{
    for (int i = 0; i < n; i++)
    {
        if (G[v][i] == 1 && colorsA[i] == c)
        {
            return false;
        }
    }

    return true;
}

bool solve(int n, int m, int v, vector<vector<int>> G, vector<int> &colorsA)
{
    if (v == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(G, v, i, n, colorsA))
        {
            colorsA[v] = i;
            if (solve(n, m, v + 1, G, colorsA))
            {
                return true;
            }
            colorsA[v] = -1;
        }
    }

    return false;
}

void GC(int m, int n, int e, vector<vector<int>> G)
{
    vector<int> colorsA(n, -1);
    if (solve(n, m, 0, G, colorsA))
    {
        cout << "Answer : ";
        for (int i : colorsA)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not Possible\n";
    }
}

int main()
{
    int n, e;

    cout << "Enter number of node in graph : ";
    cin >> n;
    cout << "Enter number of edges in graph : ";
    cin >> e;

    // int G[n][n];
    vector<vector<int>> G(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cout << "Enter edge : ";
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    int m;
    cout << "Enter number of colors : ";
    cin >> m;

    GC(m, n, e, G);
}