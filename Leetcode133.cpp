#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/clone-graph/ */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// The actually begins from here...the above part is the Node class for reference...ignore it

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0){
            Node* t = new Node(1);
            return t;
        }
        vector<Node*> v;
        v.resize(105,NULL);
        queue<Node*> q;
        q.push(node);
        unordered_set<int> s;
        s.insert(node->val);
        while(q.size()){
            Node* temp = q.front();
            q.pop();
            if(v[temp->val] == NULL){
                Node* New = new Node(temp->val);
                v[temp->val] = New;
            }
            vector<Node*> n;


            for(Node* t : temp->neighbors){
                if(s.find(t->val) == s.end()){
                    q.push(t);
                    s.insert(t->val);
                }


                if(v[t->val] == NULL){
                    Node* cl = new Node(t->val);
                    v[t->val] = cl;
                    n.push_back(v[t->val]);
                }
                else{
                    n.push_back(v[t->val]);
                }
            }

            v[temp->val]->neighbors = n;
        }

        return v[1];
    }
};