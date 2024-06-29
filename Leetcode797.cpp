#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/all-paths-from-source-to-target/description/ */

class Solution {
public:
    unordered_set<int> s;
    vector<vector<int>> v;
    vector<vector<int>> ans;
    void find(int i,vector<int> temp){
        if(i == (v.size()-1)){
            temp.push_back(i);
            ans.push_back(temp);
            return;
        }
        temp.push_back(i);
        s.insert(i);

        for(int x : v[i]){
            find(x,temp);
        }

        s.erase(i);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        v.resize(graph.size(),vector<int> ());
        v = graph;
        find(0,temp);

        return ans;
    }
};