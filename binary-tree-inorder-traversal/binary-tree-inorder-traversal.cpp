/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
     vector<int> inorderTraversal(TreeNode* root) {
       
          vector<int>ans;
         if(root == NULL){
             return ans;
         }
         
         stack<TreeNode*>s;
          TreeNode*curr = root;
         
         while(curr != NULL || s.size() != 0){
             
               if(curr){
                   s.push(curr);
                   curr = curr->left;
               }else{
                   
                   curr = s.top();
                   s.pop();
                   cout<<curr->val<<" ";
                   ans.push_back(curr->val);
                   curr = curr ->right;
               }
         }
         
         return ans;
     }
    
  /*  void helper(TreeNode*root , vector<int>&v){
        
        if(root == NULL){
            return;
        }
        
        helper(root->left , v);
        
        v.push_back(root->val);
        
        helper(root->right , v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>v;
        
        helper(root , v);
        
        return v;
    }*/
};