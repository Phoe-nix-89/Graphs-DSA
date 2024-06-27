#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
vector<int> shortestPath;
int v;
void addEdge(int src,int dstn,bool bidrn = true){
    graph[src].push_back(dstn);
    if(bidrn){
        graph[dstn].push_back(src);
    }
}

void BFS(int node){
    int i = 0;
    queue<pair<int,int>> q;
    unordered_set<int> s;

    q.push({node,i});
    s.insert(node);
    while(q.size()){
        int n = q.front().first;
        int l = q.front().second;
        q.pop();

        for(auto x : graph[n]){
            if(s.find(x) == s.end()){
                q.push({x,l+1});
                s.insert(x);
            }
        }

        shortestPath[n] = l;

        cout<<n<<" ";
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
    shortestPath.resize(v,INT_MAX);

    int e;
    cin>>e;   

    while(e--){
        int s,d;
        cin>>s>>d;

        addEdge(s,d);
    }

    int node;
    cin>>node;

    BFS(node);
    cout<<endl;

    for(int i=0;i<shortestPath.size();i++){
        cout<<i<<"->"<<shortestPath[i];
        cout<<endl;
    }
}