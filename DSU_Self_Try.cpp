#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rnk;

int Find(int i){
    if(i == parent[i]) return i;

    return parent[i] =  parent[parent[i]];
}

void display(int t){
    for(int i=0;i<parent.size();i++){
        int n = Find(i);
        if(n == t){
            cout<<i<<" ";
        }
    }

    cout<<endl;
}

void Union(int i,int j){
    int a = Find(i);
    int b = Find(j);

    if(rnk[a] < rnk[b]){
        rnk[b] += rnk[a];
        parent[a] = parent[b];
    }
    else if(rnk[a] >= rnk[b]){
        rnk[a] += rnk[b];
        parent[b] = parent[a];
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        parent.push_back(i);
        rnk.push_back(1);
    }

    Union(0,1);
    Union(2,3);
    display(0);
    display(2);
    Union(1,3);
    display(0);
    Union(2,4);
    display(0);
}