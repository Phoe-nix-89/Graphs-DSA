#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/ */

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        unordered_map<int,unordered_set<int>> m;
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] > 0 && (m.find(i) == m.end() || m[i].find(j) == m[i].end())){
                    q.push({i,j});
                    m[i].insert(j);
                    int c = grid[i][j];
                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(x-1>=0 && grid[x-1][y] > 0 && (m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end())){
                            q.push({x-1,y});
                            m[x-1].insert(y);
                            c += grid[x-1][y];
                        }
                        if(x+1<grid.size() && grid[x+1][y] > 0 && (m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end())){
                            q.push({x+1,y});
                            m[x+1].insert(y);
                            c+=grid[x+1][y];
                        }
                        if(y-1>=0 && grid[x][y-1] > 0 && (m.find(x) == m.end() || m[x].find(y-1) == m[x].end())){
                            q.push({x,y-1});
                            m[x].insert(y-1);
                            c+=grid[x][y-1];
                        }
                        if(y+1<grid[0].size() && grid[x][y+1] > 0 && (m.find(x) == m.end() || m[x].find(y+1) == m[x].end())){
                            q.push({x,y+1});
                            m[x].insert(y+1);
                            c+=grid[x][y+1];
                        }
                    }

                    ans = max(ans,c);
                }
            }
        }

        return ans;
    }
};