#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/shortest-bridge/ */

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        unordered_map<int,unordered_set<int>> m;
        int flag = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    m[i].insert(j);
                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(x-1>=0 && grid[x-1][y] == 1 && (m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end()) ){
                            q.push({x-1,y});
                            m[x-1].insert(y);
                        }
                        if(x+1<grid.size() && grid[x+1][y] == 1 && (m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end()) ){
                            q.push({x+1,y});
                            m[x+1].insert(y);
                        }
                        if(y-1>=0 && grid[x][y-1] == 1 && (m.find(x) == m.end() || m[x].find(y-1) == m[x].end()) ){
                            q.push({x,y-1});
                            m[x].insert(y-1);
                        }
                        if(y+1<grid[0].size() && grid[x][y+1] == 1 && (m.find(x) == m.end() || m[x].find(y+1) == m[x].end()) ){
                            q.push({x,y+1});
                            m[x].insert(y+1);
                        }
                    }

                    flag = 1;
                }

                if(flag == 1) break;
            }

            if(flag == 1) break;
        }

        unordered_map<int,unordered_set<int>> m1;
        flag = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1 && (m.find(i) == m.end() || m[i].find(j) == m[i].end() ) ){
                    q.push({i,j});
                    m1[i].insert(j);
                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(x-1>=0 && grid[x-1][y] == 1 && (m1.find(x-1) == m1.end() || m1[x-1].find(y) == m1[x-1].end()) ){
                            q.push({x-1,y});
                            m1[x-1].insert(y);
                        }
                        if(x+1<grid.size() && grid[x+1][y] == 1 && (m1.find(x+1) == m1.end() || m1[x+1].find(y) == m1[x+1].end()) ){
                            q.push({x+1,y});
                            m1[x+1].insert(y);
                        }
                        if(y-1>=0 && grid[x][y-1] == 1 && (m1.find(x) == m1.end() || m1[x].find(y-1) == m1[x].end()) ){
                            q.push({x,y-1});
                            m1[x].insert(y-1);
                        }
                        if(y+1<grid[0].size() && grid[x][y+1] == 1 && (m1.find(x) == m1.end() || m1[x].find(y+1) == m1[x].end()) ){
                            q.push({x,y+1});
                            m1[x].insert(y+1);
                        }
                    }

                    flag = 0;
                }

                if(flag == 1) break;
            }

            if(flag == 1) break;
        }

        queue<pair<pair<int,int>,int>> q1;
        unordered_map<int,unordered_set<int>> m2;

        for(auto x : m){
            for(int y : x.second){
                q1.push({{x.first,y} , 0});
                m2[x.first].insert(y);
                //cout<<x.first<<" "<<y<<endl;
            }
        }

        int ans = INT_MAX;
        while(q1.size()){
            auto t = q1.front();
            q1.pop();
            int x = t.first.first;
            int y = t.first.second;
            int c = t.second;

            if(m1.find(x) != m1.end() && m1[x].find(y) != m1[x].end()){
                ans = min(ans,c);
            }

            if(x-1>=0 && (m2.find(x-1) == m2.end() || m2[x-1].find(y) == m2[x-1].end()) ){
                    if(grid[x-1][y] == 0){
                        q1.push({{x-1,y},c+1});
                    }
                    else q1.push({{x-1,y},c});
                    m2[x-1].insert(y);
                }
                if(x+1<grid.size() && (m2.find(x+1) == m2.end() || m2[x+1].find(y) == m2[x+1].end()) ){
                    if(grid[x+1][y] == 0){
                        q1.push({{x+1,y} , c+1});
                    }
                    else q1.push({{x+1,y} , c});
                    m2[x+1].insert(y);
                }
                if(y-1>=0 && (m2.find(x) == m2.end() || m2[x].find(y-1) == m2[x].end()) ){
                    if(grid[x][y-1] == 0){
                        q1.push({{x,y-1} , c+1});
                    }
                    else q1.push({{x,y-1} , c});
                    m2[x].insert(y-1);
                }
                if(y+1<grid[0].size() && (m2.find(x) == m2.end() || m2[x].find(y+1) == m2[x].end()) ){
                    if(grid[x][y+1] == 0){
                        q1.push({{x,y+1} , c+1});
                    }
                    else q1.push({{x,y+1} , c});
                    m2[x].insert(y+1);
                }
        }

        return ans;
    }
};