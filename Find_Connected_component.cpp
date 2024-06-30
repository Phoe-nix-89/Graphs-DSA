#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void addEdge(int src,int dstn,bool bidrn = true){
    graph[src].push_back(dstn);
    if(bidrn){
        graph[dstn].push_back(src);
    }
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

void DFS(int node,unordered_set<int> &s){
    s.insert(node);
    for(int x : graph[node]){
        if(s.find(x) == s.end()){
            DFS(x,s);
        }
    }
}

void BFS(int node,unordered_set<int> &s){
    queue<int> q;
    q.push(node);
    s.insert(node);
    while(q.size()){
        int temp = q.front();
        q.pop();


        for(int x : graph[temp]){
            if(s.find(x) == s.end()){
                q.push(x);
                s.insert(x);
            }
        }
    }
}

void check(){
    unordered_set<int> s;
    int ans = 0;
    for(int i=0;i<graph.size();i++){
        if(s.find(i) == s.end()){
            ans++;
            DFS(i,s);
        }
    }


    cout<<"The number of connected components are : "<<ans<<endl;
}

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

    check();

    //display();
}