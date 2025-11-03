/**
* Longest Increasing Subsequence
* Author: Imtiaz Adar
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int find_longest_increasing_subsequence(vector<int>& vec){
    int n = vec.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(vec[i] > vec[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main(){
    vector<int> nums = {5, 7, 9 , 11, 1, 2, 3, 15, 18, 19, 21, 24, 16, 29};
    int len = find_longest_increasing_subsequence(nums);
    cout << "Longest Increasing Subsequence: " << len << endl;
    return 0;
}
