#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/shortest-path-in-binary-matrix/ */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int,unordered_set<int>> m;
        m[0].insert(0);
        queue<pair<int,int>> q;
        queue<int> l;
        if(grid[0][0] == 0){
            q.push({0,0});
            l.push(1);
        }
        int ans = INT_MAX;
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            int t = l.front();
            if(i == grid.size()-1 && j == grid[0].size()-1){
                ans = min(ans,t);
            }
            q.pop();
            l.pop();

            if(i-1>=0){
                if(grid[i-1][j] == 0 && (m.find(i-1) == m.end() || m[i-1].find(j) == m[i-1].end())){
                    m[i-1].insert(j);
                    q.push({i-1,j});
                    l.push(t+1);
                }
                if(j-1>=0 && grid[i-1][j-1] == 0 && (m.find(i-1) == m.end() || m[i-1].find(j-1) == m[i-1].end()) ){
                    m[i-1].insert(j-1);
                    q.push({i-1,j-1});
                    l.push(t+1);
                }
                if(j+1<grid[0].size() && grid[i-1][j+1] == 0 && (m.find(i-1) == m.end() || m[i-1].find(j+1) == m[i-1].end()) ){
                    m[i-1].insert(j+1);
                    q.push({i-1,j+1});
                    l.push(t+1);
                }
            }
            if(i+1<grid.size()){
                if(grid[i+1][j] == 0 && (m.find(i+1) == m.end() || m[i+1].find(j) == m[i+1].end())){
                    m[i+1].insert(j);
                    q.push({i+1,j});
                    l.push(t+1);
                }
                if(j-1>=0 && grid[i+1][j-1] == 0 && (m.find(i+1) == m.end() || m[i+1].find(j-1) == m[i+1].end()) ){
                    m[i+1].insert(j-1);
                    q.push({i+1,j-1});
                    l.push(t+1);
                }
                if(j+1<grid[0].size() && grid[i+1][j+1] == 0 && (m.find(i+1) == m.end() || m[i+1].find(j+1) == m[i+1].end()) ){
                    m[i+1].insert(j+1);
                    q.push({i+1,j+1});
                    l.push(t+1);
                }
            }
            if(j-1>=0 && grid[i][j-1] == 0 && (m.find(i) == m.end() || m[i].find(j-1) == m[i].end()) ){
                    m[i].insert(j-1);
                    q.push({i,j-1});
                    l.push(t+1);
            }
            if(j+1<grid[0].size() && grid[i][j+1] == 0 && (m.find(i) == m.end() || m[i].find(j+1) == m[i].end()) ){
                    m[i].insert(j+1);
                    q.push({i,j+1});
                    l.push(t+1);
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};