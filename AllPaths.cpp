#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> s;
vector<vector<int>> result;
int v;
void addEdge(int src,int dstn,bool bidrn = true){
    graph[src].push_back(dstn);
    if(bidrn){
        graph[dstn].push_back(src);
    }
}

void DFS(vector<int> temp,int src,int end){
    s.insert(src);
    temp.push_back(src);
    if(src == end){
        result.push_back(temp);
        s.erase(src);
        return;
    }

    for(auto x : graph[src]){
        if(s.find(x) == s.end()){
            DFS(temp,x,end);
        }
    }

    s.erase(src);

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
7
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

    
    vector<int> temp;
    while(e--){
        int s,d;
        cin>>s>>d;

        addEdge(s,d);
    }

    int x,y;
    cin>>x>>y;

    DFS(temp,x,y);

    cout<<"All paths are : "<<endl;
    for(vector<int> x : result){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }

        cout<<endl;
    }
}