#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> temp;
    int DFS(int i,int j){
        //if(dp[i][j] != 0) return dp[i][j];
        int ans = 0;
        int t = 1;

        ans = max(ans,t);

        if(i-1>=0 && temp[i-1][j] > temp[i][j]){
            if(dp[i-1][j] == 0){
                int r = t + DFS(i-1,j);
                ans = max(r,ans);
            }
            else ans = max(ans,1+dp[i-1][j]);
        }

        if(i+1<temp.size() && temp[i+1][j] > temp[i][j]){
            if(dp[i+1][j] == 0){
                int r = t + DFS(i+1,j);
                ans = max(r,ans);
            }
            else{
                ans = max(ans,1+dp[i+1][j]);
            }
        }

        if(j-1>=0 && temp[i][j-1] > temp[i][j]){
            if(dp[i][j-1] == 0){
                int r = t + DFS(i,j-1);
                ans = max(r,ans);
            }
            else ans = max(ans,1+dp[i][j-1]);
        }

        if(j+1<temp[0].size() && temp[i][j+1] > temp[i][j]){
            if(dp[i][j+1] == 0){
                int r = t + DFS(i,j+1);
                ans = max(r,ans);
            }
            else ans = max(ans,1+dp[i][j+1]);
        }

        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int> (matrix[0].size(),0));
        temp = matrix;
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dp[i][j] == 0){
                    ans = max(ans,DFS(i,j));
                }
                else{
                    ans = max(ans,dp[i][j]);
                }

                //cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};