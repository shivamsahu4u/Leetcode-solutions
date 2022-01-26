/*
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
*/

class Solution {
public:
    void clone(Node* node , Node*ans , unordered_map<int , Node*>&visited){
        
         visited[node->val] = ans;
        
         for(auto it : node->neighbors){
             
              if(visited.count(it->val) > 0){
                  //if they are already visited , then no need to visited them again
                  ans->neighbors.push_back(visited[it->val]);
              }else{
                  
                  Node*newNode = new Node(it->val);
                  ans->neighbors.push_back(newNode);
                  clone(it , newNode , visited);
              }
         }
    }
    
    Node* cloneGraph(Node* node) {
         if(node == NULL){
             return node;
         }
    unordered_map<int , Node*>visited;
    Node*count = new Node(node->val);
    visited[node->val] =  count; // value , address
        
        for(int i = 0 ; i < node->neighbors.size() ; i++){
                  
            if(visited.count(node->neighbors[i]->val) > 0){
             //already present
         count->neighbors.push_back(visited[node->neighbors[i]->val]);
          //clone(node->neighbors[i] , ans); // already visited so khatam
            }else{
                
                 Node*newNode = new Node(node->neighbors[i]->val);
                  count->neighbors.push_back(newNode);
                  clone(node->neighbors[i] , newNode , visited);
            }   
            
                  
        }
       return count;
    }
};