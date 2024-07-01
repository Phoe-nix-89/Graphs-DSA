#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-islands/ */

class Solution {
public:
    vector<vector<char>> v;
    unordered_map<int,unordered_set<int>> m;
    void DFS(int i,int j){
        m[i].insert(j);

        if(i-1>=0 && v[i-1][j] == '1' && (m.find(i-1) == m.end() || m[i-1].find(j) == m[i-1].end())){
            DFS(i-1,j);
        }
        if(i+1<v.size() && v[i+1][j] == '1' && (m.find(i+1) == m.end() || m[i+1].find(j) == m[i+1].end())){
            DFS(i+1,j);
        }
        if(j-1>=0 && v[i][j-1] == '1' && (m.find(i) == m.end() || m[i].find(j-1) == m[i].end())){
            DFS(i,j-1);
        }
        if(j+1<v[0].size() && v[i][j+1] == '1' && (m.find(i) == m.end() || m[i].find(j+1) == m[i].end())){
            DFS(i,j+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        v = grid;
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && (m.find(i) == m.end() || m[i].find(j) == m[i].end())){
                    ans++;
                    DFS(i,j);
                }
            }
        }

        return ans;
    }
};