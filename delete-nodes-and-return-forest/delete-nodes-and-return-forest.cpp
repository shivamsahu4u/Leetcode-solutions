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
    unordered_map<int , int>mp;
    vector<TreeNode*>ans;
    
    TreeNode* helper(TreeNode* root , vector<int>&to_delete){
        
          if(root == NULL){
              return root;
          }
        // calling left and right substree to delete the required nodes
        root->left = helper(root->left , to_delete);
        root->right = helper(root->right, to_delete);
        
        //if we have to delete the root node then we will put the right and left subtree
        if(mp.find(root->val) != mp.end()){
            
            if(root->left)
            ans.push_back(root->left);
            
            if(root->right)
            ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
         //putting the elements to be deleted in the unordered map
         for(auto i : to_delete){
             mp[i]++;
         }
        
       root = helper(root , to_delete);
        
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};