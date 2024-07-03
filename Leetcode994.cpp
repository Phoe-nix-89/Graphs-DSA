#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/rotting-oranges/ */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int c = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2) q.push({i,j});

                if(grid[i][j] == 1) c++;
            }
        }

        int ans = 0;
        int count = 0;
        vector<pair<int,int>> temp;
        while(q.size()){
            int flag = 0;
            while(q.size()){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();
                
                if(x-1>=0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    temp.push_back({x-1,y});
                    flag++;
                }
                if(x+1<grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    temp.push_back({x+1,y});
                    flag++;
                }
                if(y-1>=0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    temp.push_back({x,y-1});
                    flag++;
                }
                if(y+1<grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    temp.push_back({x,y+1});
                    flag++;
                }
            }

            for(auto x : temp){
                q.push(x);
            }

            temp.clear();

            if(flag > 0) ans++;
            count += flag;
        }

        if(c == count) return ans;
        return -1;
    }
};