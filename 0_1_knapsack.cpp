/**
* Author: Imtiaz Adar
*/
#include<bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>>& dp, int row, int col){
    cout << "Printing the dp table: " << endl;
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int knapsack_(vector<int>& items, vector<int>& weights, int W){
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));
    for(int i = 1; i < n + 1; i++){
        for(int w = 0; w < W + 1; w++){
            if(weights[i - 1] <= w){
                dp[i][w] = max(items[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printDP(dp, n, W);
    return dp[n][W];
}
int32_t main(){
    int n;
    cout << "Number of items: " << endl;
    cin >> n;
    vector<int> items(n);
    cout << "Item values: " << endl;
    for(int k = 0; k < n; k++){
        cin >> items[k];
    }
    vector<int> weights(n);
    cout << "Weights: " << endl;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    int maxWeight;
    cout << "Maximum weight: " << endl;
    cin >> maxWeight;
    int highestVal = knapsack_(items, weights, maxWeight);
    cout << "Highest value: " << highestVal << endl;
    return 0;
}
