#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/max-area-of-island/ */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        unordered_map<int,unordered_set<int>> m;
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1 && (m.find(i) == m.end() || m[i].find(j) == m[i].end())){
                    q.push({i,j});
                    m[i].insert(j);
                    int c = 0;

                    while(q.size()){
                        auto f = q.front();
                        int x = f.first;
                        int y = f.second;
                        q.pop();
                        

                        if(x-1>=0 && grid[x-1][y] == 1 && (m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end())){
                            q.push({x-1,y});
                            m[x-1].insert(y);
                        }
                        
                        if(x+1<grid.size() && grid[x+1][y] == 1 && (m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end())){
                            q.push({x+1,y});
                            m[x+1].insert(y);
                        }
                        
                        if(y-1>=0 && grid[x][y-1] == 1 && (m.find(x) == m.end() || m[x].find(y-1) == m[x].end())){
                            q.push({x,y-1});
                            m[x].insert(y-1);
                        }
                        
                        if(y+1<grid[i].size() && grid[x][y+1] == 1 && (m.find(x) == m.end() || m[x].find(y+1) == m[x].end())){
                            q.push({x,y+1});
                            m[x].insert(y+1);
                        }
                        c++;
                        
                    }

                    ans = max(ans,c);

                }
            }
        }

        return ans;
    }
};