#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/01-matrix/ */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(),vector<int> (mat[0].size(),-1));

        unordered_map<int,unordered_set<int>> m;

        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                    q.push( {{i,j},0} );
                    m[i].insert(j);
                }
            }
        }

        while(q.size()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(i-1>=0){
                if((m.find(i-1) == m.end() || m[i-1].find(j) == m[i-1].end())){
                    m[i-1].insert(j);
                    q.push({{i-1,j},d+1});
                    dp[i-1][j] = d+1;
                }
                else{
                    if(d+1 < dp[i-1][j]){
                        dp[i-1][j] = d+1;
                    }
                }
            }
            if(j-1>=0){
                if((m.find(i) == m.end() || m[i].find(j-1) == m[i].end())){
                    m[i].insert(j-1);
                    q.push({{i,j-1},d+1});
                    dp[i][j-1] = d+1;
                }
                else{
                    if(d+1 < dp[i][j-1]){
                        dp[i][j-1] = d+1;
                    }
                }
            }
            if(i+1<mat.size()){
                
                if((m.find(i+1) == m.end() || m[i+1].find(j) == m[i+1].end())){
                    m[i+1].insert(j);
                    q.push({{i+1,j},d+1});
                    dp[i+1][j] = d+1;
                }
                else{
                    if(d+1 < dp[i+1][j]){
                        dp[i+1][j] = d+1;
                    }
                }
            }
            if(j+1<mat[0].size()){
                
                if((m.find(i) == m.end() || m[i].find(j+1) == m[i].end())){
                    m[i].insert(j+1);
                    q.push({{i,j+1},d+1});
                    dp[i][j+1] = d+1;
                }
                else{
                    if(d+1 < dp[i][j+1]){
                        dp[i][j+1] = d+1;
                    }
                }
            }            
        }

        return dp;
    }
};