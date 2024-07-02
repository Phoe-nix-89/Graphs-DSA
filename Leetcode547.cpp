#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-provinces/ */

class Solution {
public:
    unordered_set<int> s;
    vector<list<int>> v;
    void BFS(int i){
        queue<int> q;
        q.push(i);
        s.insert(i);
        while(q.size()){
            int temp = q.front();
            q.pop();
            
            for(int x : v[temp]){
                if(s.find(x) == s.end()){
                    q.push(x);
                    s.insert(x);
                }
            }


        }
    }
    int findCircleNum(vector<vector<int>>& con) {
        v.resize(con.size(),list<int> ());

        for(int i=0;i<con.size();i++){
            for(int j=0;j<con.size();j++){
                if(i!=j && con[i][j] == 1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }

        int c = 0;
        
        for(int i=0;i<con.size();i++){
            if(s.find(i) == s.end()){
                c++;
                BFS(i);
            }
        }

        return c;
    }
};