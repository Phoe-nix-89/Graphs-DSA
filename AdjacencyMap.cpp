#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;
void addEdge(int src,int dstn,int wt,bool bidrn = true){
    graph[src][dstn] = wt;
    if(bidrn){
        graph[dstn][src] = wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto item : graph[i]){
            cout<<"("<<item.first<<","<<item.second<<")"<<",";
        }

        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,unordered_map<int,int> ());

    int e;
    cin>>e;

    int choice;
    cin>>choice;

    if(choice == 1){
        while(e--){
            int s,d,wt;
            cin>>s>>d>>wt;

            addEdge(s,d,wt);
        }
    }
    else if(choice == 2){
        while(e--){
            int s,d,wt;
            cin>>s>>d>>wt;

            addEdge(s,d,wt,false);
        }
    }

    display();
}