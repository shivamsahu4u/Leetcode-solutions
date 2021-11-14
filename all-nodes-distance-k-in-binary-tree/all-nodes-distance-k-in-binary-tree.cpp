/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
//k distance nodes from the target 
//Recursion Method

unordered_map<TreeNode* , TreeNode*>parent; //parent of node
unordered_map<TreeNode* , bool>visited; // node is visited or not
vector<int>ans; // storage of answer
void par(TreeNode* root){

     if(root == NULL){
        return;
     }

     if(root->left){
        parent[root->left] = root;
        par(root->left);
     }

     if(root->right){
        parent[root->right] = root;
        par(root->right);
     }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K){

     if(root == NULL)return ans;
     par(root);
     dfs(target , K);
     return ans;
}
void dfs(TreeNode* target , int k){

     if(visited.find(target) != visited.end()){
        return ;
     }

     visited[target] = true;

     if(k == 0){
        ans.push_back(target->val);
        return;
     }

     if(target->left){
        dfs(target->left , k-1);
     }

     if(target->right){
        dfs(target->right , k-1);
     }

     TreeNode*p = parent[target];

     if(p){
        dfs(p , k-1);
     }
}


};