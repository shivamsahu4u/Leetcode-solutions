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
    
    vector<TreeNode*> helper(int start , int end){
        
        vector<TreeNode*>ans;
        if(start > end){
            TreeNode*node = NULL;
            ans.push_back(node);
            return ans;
        }
        
        for(int i = start ; i<= end ; i++){
            
            vector<TreeNode*>l = helper(start , i-1);
            vector<TreeNode*>r = helper(i+1 , end);
            
            
            
            for(auto le : l){
                
                for(auto ri : r){
                  TreeNode*root = new TreeNode(i);  
                    root->left = le;
                    root->right = ri;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
         
         return helper(1 , n);
    }
};