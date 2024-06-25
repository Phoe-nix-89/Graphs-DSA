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

    display();
}