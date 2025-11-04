/**
* Author: Imtiaz Adar
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

bool comp1(pair<int, int> x, pair<int, int> y){
    return x.first > y.first;
}
vector<int> dijkstra_implement(vector<vector<pair<int, int>>>& adj, int source){
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, bool(*)(pair<int, int>, pair<int, int>)> pq(comp1);
    pq.push({0, source});
    while(!pq.empty()){
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(distance > dist[current]){
            continue;
        }
        for(auto item: adj[current]){
            int neighbor = item.first;
            int weight = item.second;
            if(dist[current] + weight < dist[neighbor]){
                dist[neighbor] = dist[current] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}
int main(){
    int n, e;
    cout << "Nodes and edges: " << endl;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj(n);
    int s, d, w;
    cout << "Node, neighbor, and weight: " << endl;
    for(int i = 0; i < e; i++){
        cin >> s >> d >> w;
        adj[s].push_back({d, w});
        adj[d].push_back({s, w});
    }
    int source;
    cout << "Source: " << endl;
    cin >> source;
    vector<int> result = dijkstra_implement(adj, source);
    int finSize = result.size();
    cout << "Shortest distance: " << endl;
    for(int i = 0; i < finSize; i++){
        if(result[i] == INT_MAX) cout << i << "-> INF" << endl;
        else cout << i << "-> " << result[i] << endl;
    }
    cout << endl;
    return 0;
}
