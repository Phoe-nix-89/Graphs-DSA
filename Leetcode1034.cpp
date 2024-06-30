#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/coloring-a-border/ */

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int,int>> q;
        unordered_map<int,unordered_set<int>> m;
        vector<vector<int>> v;
        v = grid;

        int minr = INT_MAX;
        int maxr = 0;
        int minc = INT_MAX;
        int maxc = 0;

        q.push({row,col});
        m[row].insert(col);
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x-1>=0 && grid[x-1][y] == grid[x][y] && (m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end()) ){
                q.push({x-1,y});
                m[x-1].insert(y);
            }
            if(x+1<grid.size() && grid[x+1][y] == grid[x][y] && (m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end()) ){
                q.push({x+1,y});
                m[x+1].insert(y);
            }
            if(y-1>=0 && grid[x][y-1] == grid[x][y] && (m.find(x) == m.end() || m[x].find(y-1) == m[x].end()) ){
                q.push({x,y-1});
                m[x].insert(y-1);
            }
            if(y+1<grid[0].size() && grid[x][y+1] == grid[x][y] && (m.find(x) == m.end() || m[x].find(y+1) == m[x].end()) ){
                q.push({x,y+1});
                m[x].insert(y+1);
            }

            minr = min(minr,x);
            maxr = max(maxr,x);
            minc = min(minc,y);
            maxc = max(maxc,y);
        }

        for(auto x : m){
            int i = x.first;
            for(int j : x.second){
                if( ((i == minr || i == maxr) || (j == maxc || j == minc)) || ( (i-1>=0 && grid[i-1][j] != grid[i][j]) || (i+1<grid.size() && grid[i+1][j] != grid[i][j]) || (j-1>=0 && grid[i][j-1] != grid[i][j]) || (j+1<grid[0].size() && grid[i][j+1] != grid[i][j]) ) ){
                    v[i][j] = color;
                }
            }
        }

        return v;
    }
};