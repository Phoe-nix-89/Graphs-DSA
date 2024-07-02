#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/pacific-atlantic-water-flow/ */

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> v(heights.size(),vector<int> (heights[0].size(),0));
        queue<pair<int,int>> q;
        int i = heights.size()-1;
        int j = 0;
        int k = 0;
        unordered_map<int,unordered_set<int>> m1;
        while(j<heights[0].size()){
            q.push({i,j});
            v[i][j]+=1;
            m1[i].insert(j);
            

            if(i == 0 && j == 0) k = 1;


            if(k%2 == 0) i--;
            else if(k%2 == 1) j++;
        }

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            

            q.pop();

            if(x-1>=0 && heights[x-1][y] >= heights[x][y] && (m1.find(x-1) == m1.end() || m1[x-1].find(y) == m1[x-1].end())){
                q.push({x-1,y});
                v[x-1][y]+=1;
                m1[x-1].insert(y);
            }
            if(x+1<heights.size() && heights[x+1][y] >= heights[x][y] && (m1.find(x+1) == m1.end() || m1[x+1].find(y) == m1[x+1].end())){
                q.push({x+1,y});
                v[x+1][y]+=1;
                m1[x+1].insert(y);
            }
            if(y-1>=0 && heights[x][y-1] >= heights[x][y] && (m1.find(x) == m1.end() || m1[x].find(y-1) == m1[x].end())){
                q.push({x,y-1});
                v[x][y-1]+=1;
                m1[x].insert(y-1);
            }
            if(y+1<heights[0].size() && heights[x][y+1] >= heights[x][y] && (m1.find(x) == m1.end() || m1[x].find(y+1) == m1[x].end())){
                q.push({x,y+1});
                v[x][y+1]+=1;
                m1[x].insert(y+1);
            }
        }

        i = heights.size()-1;
        j = 0;
        k = 0;
        unordered_map<int,unordered_set<int>> m2;
        while(i>=0){
            q.push({i,j});
            v[i][j]+=1;
            m2[i].insert(j);
            

            if(i == (heights.size()-1) && j == (heights[0].size()-1)) k = 1;


            if(k%2 == 0) j++;
            else if(k%2 == 1) i--;
        }

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x-1>=0 && heights[x-1][y] >= heights[x][y] && (m2.find(x-1) == m2.end() || m2[x-1].find(y) == m2[x-1].end())){
                q.push({x-1,y});
                v[x-1][y]+=1;
                m2[x-1].insert(y);
            }
            if(x+1<heights.size() && heights[x+1][y] >= heights[x][y] && (m2.find(x+1) == m2.end() || m2[x+1].find(y) == m2[x+1].end())){
                q.push({x+1,y});
                v[x+1][y]+=1;
                m2[x+1].insert(y);
            }
            if(y-1>=0 && heights[x][y-1] >= heights[x][y] && (m2.find(x) == m2.end() || m2[x].find(y-1) == m2[x].end())){
                q.push({x,y-1});
                v[x][y-1]+=1;
                m2[x].insert(y-1);
            }
            if(y+1<heights[0].size() && heights[x][y+1] >= heights[x][y] && (m2.find(x) == m2.end() || m2[x].find(y+1) == m2[x].end())){
                q.push({x,y+1});
                v[x][y+1]+=1;
                m2[x].insert(y+1);
            }
        }

        vector<vector<int>> ans;

        for(int x=0;x<v.size();x++){
            for(int y=0;y<v[0].size();y++){
                if(v[x][y] == 2) ans.push_back({x,y});
                cout<<v[x][y]<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};