#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j;
    cin>>i>>j;

    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    
    unordered_map<int,unordered_set<int>> m;
    m[0].insert(0);

    while(q.size()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int l = q.front().second;
        //cout<<x<<" "<<y<<endl;

        if(x == i && y == j){
            cout<<l;
            break;
        }
        q.pop();
        int x1 = x;
        int x2 = (-1)*x;
        int y1 = y;
        int y2 = (-1)*y;
        if((abs(x) + abs(y))>300) continue;
        

        if(m.find(x+2) == m.end() || m[x+2].find(y+1) == m[x+2].end()){
            q.push({ {x+2,y+1} , l+1 });
            m[x+2].insert(y+1);
        }
        if(m.find(x+2) == m.end() || m[x+2].find(y-1) == m[x+2].end()){
            q.push({ {x+2,y-1} , l+1 });
            m[x+2].insert(y-1);
        }

        if(m.find(x-2) == m.end() || m[x-2].find(y+1) == m[x-2].end()){
            q.push({ {x-2,y+1} , l+1 });
            m[x-2].insert(y+1);
        }
        if(m.find(x-2) == m.end() || m[x-2].find(y-1) == m[x-2].end()){
            q.push({ {x-2,y-1} , l+1 });
            m[x-2].insert(y-1);
        }

        if(m.find(x+1) == m.end() || m[x+1].find(y+2) == m[x+1].end()){
            q.push({ {x+1,y+2} , l+1 });
            m[x+1].insert(y+2);
        }
        if(m.find(x+1) == m.end() || m[x+1].find(y-2) == m[x+1].end()){
            q.push({ {x+1,y-2} , l+1 });
            m[x+1].insert(y-2);
        }

        if(m.find(x-1) == m.end() || m[x-1].find(y+2) == m[x-1].end()){
            q.push({ {x-1,y+2} , l+1 });
            m[x-1].insert(y+2);
        }
        if(m.find(x-1) == m.end() || m[x-1].find(y-2) == m[x-1].end()){
            q.push({ {x-1,y-2} , l+1 });
            m[x-1].insert(y-2);
        }
    }
}