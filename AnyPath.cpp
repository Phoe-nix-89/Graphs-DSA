#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> s;
int v;
void addEdge(int src,int dstn,bool bidrn = true){
    graph[src].push_back(dstn);
    if(bidrn){
        graph[dstn].push_back(src);
    }
}

bool DFS(int src,int end){
    s.insert(src);
    if(src == end) return true;

    bool ans = false;
    for(auto x : graph[src]){
        if(s.find(x) == s.end()){
            ans = ans || DFS(x,end);
        }
    }

    return ans;

}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(int elem : graph[i]){
            cout<<elem<<" ";
        }

        cout<<endl;
    }
}
/*
7
8
0 1
0 4
3 1
3 4
1 5
5 6
5 2
2 6
0 6
1
*/

int main(){
    cin>>v;
    graph.resize(v,list<int> ());

    int e;
    cin>>e;

    

    while(e--){
        int s,d;
        cin>>s>>d;

        addEdge(s,d);
    }

    int x,y;
    cin>>x>>y;

    cout<<DFS(x,y);
}