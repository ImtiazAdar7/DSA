/**
* Minimum Coin Change
* Author: Imtiaz Adar
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int highest = INT_MAX;
int min_coin_change(vector<int>& coins, int val){
    int n = coins.size();
    vector<int> dp(val + 1, highest);
    dp[0] = 0;
    for(int i = 1; i < val + 1; i++){
        for(int c: coins){
            if(i - c >= 0 && dp[i - c] != highest){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    int newVal = (dp[val] == highest)? -1: dp[val];
    return newVal;
}
int main(){
    vector<int> coins = {1, 3, 5};
    int amount = 5;
    int coin = min_coin_change(coins, amount);
    cout << "Minimum Coins Needed As Change: " << coin << endl;
    return 0;
}
