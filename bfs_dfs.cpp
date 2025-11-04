/**
* Author: Imtiaz Adar
*/
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int start){
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbors: adj[node]){
            if(!visited[neighbors]){
                visited[neighbors] = true;
                q.push(neighbors);
            }
        }
    }
    cout << endl;
}
void dfsUtil(vector<vector<int>>& adj, vector<bool>& visited, int source){
    visited[source] = true;
    cout << source << " ";
    for(int neighbor: adj[source]){
        if(!visited[neighbor]){
            dfsUtil(adj, visited, neighbor);
        }
    }
}
void dfs(vector<vector<int>>& adj, int source){
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsUtil(adj, visited, source);
    cout << endl;
}

int32_t main(){
    int n, e;
    cout << "Number of nodes and edges: " << endl;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    int s, d;
    cout << "Insert edges:" << endl;
    for(int i = 0; i < e; i++){
        cout << "Source: " << endl;
        cin >> s;
        cout << "Destination: " << endl;
        cin >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    int source;
    cout << "Enter source node: " << endl;
    cin >> source;
    cout << "BFS" << endl;
    bfs(adj, source);
    cout << "DFS" << endl;
    dfs(adj, source);
    return 0;
}
