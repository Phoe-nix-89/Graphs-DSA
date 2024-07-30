#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 */

class Solution {
  public:
    vector<vector<int>> temp;
    vector<string> ans;
    void find(int i,int j,string str,unordered_map<int,unordered_set<int>> m){
        if(i == temp.size()-1 && j == temp[0].size()-1){
            ans.push_back(str);
            return;
        }
        
        if(i-1>=0 && temp[i-1][j] == 1 && (m.find(i-1) == m.end() || m[i-1].find(j) == m[i-1].end())){
            str.push_back('U');
            m[i-1].insert(j);
            find(i-1,j,str,m);
            str.pop_back();
            m[i-1].erase(j);
        }
        if(j-1>=0 && temp[i][j-1] == 1 && (m.find(i) == m.end() || m[i].find(j-1) == m[i].end())){
            str.push_back('L');
            m[i].insert(j-1);
            find(i,j-1,str,m);
            str.pop_back();
            m[i].erase(j-1);
        }
        if(i+1<temp.size() && temp[i+1][j] == 1 && (m.find(i+1) == m.end() || m[i+1].find(j) == m[i+1].end())){
            str.push_back('D');
            m[i+1].insert(j);
            find(i+1,j,str,m);
            str.pop_back();
            m[i+1].erase(j);
        }
        if(j+1<temp[0].size() && temp[i][j+1] == 1 && (m.find(i) == m.end() || m[i].find(j+1) == m[i].end())){
            str.push_back('R');
            m[i].insert(j+1);
            find(i,j+1,str,m);
            str.pop_back();
            m[i].erase(j+1);
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0] == 0) return {"-1"};
        temp = mat;
        unordered_map<int,unordered_set<int>> m;
        m[0].insert(0);
        find(0,0,"",m);
        
        return ans;
    }
};