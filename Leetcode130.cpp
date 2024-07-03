#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/surrounded-regions/ */

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O' && ((i == 0 || i == board.size()-1) || (j == 0 || j == board[0].size()-1) ) && (m.find(i) == m.end() || m[i].find(j) == m[i].end())){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    m[i].insert(j);
                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();

                        if(x-1>=0 && board[x-1][y] == 'O' && (m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end()) ){
                            q.push({x-1,y});
                            m[x-1].insert(y);
                        }
                        if(x+1<board.size() && board[x+1][y] == 'O' && (m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end()) ){
                            q.push({x+1,y});
                            m[x+1].insert(y);
                        }
                        if(y-1>=0 && board[x][y-1] == 'O' && (m.find(x) == m.end() || m[x].find(y-1) == m[x].end()) ){
                            q.push({x,y-1});
                            m[x].insert(y-1);
                        }
                        if(y+1<board[0].size() && board[x][y+1] == 'O' && (m.find(x) == m.end() || m[x].find(y+1) == m[x].end()) ){
                            q.push({x,y+1});
                            m[x].insert(y+1);
                        }
                    }
                }
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O' && (m.find(i) == m.end() || m[i].find(j) == m[i].end())){
                    board[i][j] = 'X';
                }
            }
        }

    }
};