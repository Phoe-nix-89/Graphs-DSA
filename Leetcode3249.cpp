#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-the-number-of-good-nodes/ */

class Solution {
public:
    int ans = 0;
    unordered_map<int,unordered_set<int>> m;
    unordered_set<int> v;
    int find(int i){
        //cout<<i<<endl;
        if(m.find(i) == m.end()){
            //cout<<i<<endl;
            ans++;
            return 1;
        }
        v.insert(i);

        int f = -1;
        int size = 0;
        bool r = true;
        for(auto x : m[i]){
            if(v.find(x) == v.end()){
                int t = find(x);
                //if(i == 0) cout<<t<<" "<<x<<endl;
                if(f == -1) f = t;
                else{
                    if(f != t) {
                        r = false;
                    }
                }
                size += t;
            }
        }
        v.erase(i);

        if(r == true){
            //cout<<i<<endl;
            ans++;
        }
        return size+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        for(auto x : edges){
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }
        find(0);

        return ans;
    }
};