#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/keys-and-rooms/ */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        queue<int> q;
        s.insert(0);
        for(int x : rooms[0]){
            if(s.find(x) == s.end()){
                q.push(x);
                s.insert(x);
            }
        }

        while(q.size()){
            int t = q.front();
            q.pop();

            for(int x : rooms[t]){
                if(s.find(x) == s.end()){
                    q.push(x);
                    s.insert(x);
                }
            }
        }

        if(s.size() == rooms.size()) return true;
        return false;
    }
};