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
    
    vector<int>ans;
    int i = 0;
    bool helper(TreeNode* root , vector<int>&voyage){
        
         if(root == NULL){
             return true;
         }
        
        if(root->val != voyage[i++]){
            return false;
        }
        
        if(root->left && root->left->val != voyage[i]){
            //then we need to swap right now
            ans.push_back(root->val);
            return helper(root->right , voyage) && helper(root->left , voyage);
        }
        
        return helper(root->left , voyage) && helper(root->right , voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
          vector<int>v{-1};
         return helper(root , voyage) ? ans : v;
    }
};