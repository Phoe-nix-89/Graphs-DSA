#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/flood-fill/description/ */

class Solution {
public:
    vector<vector<int>> temp;
    int c;
    int prev;
    int count = 0;
    void update(int i,int j){
        if(count == (temp.size() * temp[0].size())) return;


        temp[i][j] = c;
        count++;
        cout<<i<<" "<<j<<" "<<prev<<" "<<temp[i][j]<<endl;


        if(i-1>=0 && prev == temp[i-1][j]){
            update(i-1,j);
            if(count == (temp.size() * temp[0].size())) return;
        }
        if(i+1<temp.size() && prev == temp[i+1][j]){
            update(i+1,j);
            if(count == (temp.size() * temp[0].size())) return;
        }
        if(j-1>=0 && prev == temp[i][j-1]){
            update(i,j-1);
            if(count == (temp.size() * temp[0].size())) return;
        }
        if(j+1<temp[0].size() && prev == temp[i][j+1]){
            update(i,j+1);
            if(count == (temp.size() * temp[0].size())) return;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        temp.resize(image.size(),vector<int> (image[0].size()));
        temp = image;
        prev = image[sr][sc];
        c = color;
        update(sr,sc);
        return temp;
    }
};