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
    
  
     vector<TreeNode*> helper(int n){
        
        if(n == 1){
            vector<TreeNode*>ans;
            TreeNode*a = new TreeNode(0);
            ans.push_back(a);
            return ans;
        }
        
         vector<TreeNode*>ans;
        for(int i = 1 ; i < n ; i+=2){
            vector<TreeNode*> l = helper(i);
            vector<TreeNode*> r = helper(n-i-1);
            
            for(TreeNode* k : l){
                
                for(TreeNode* p : r){
                    
                     TreeNode*a = new TreeNode(0);
                     a->left = k;
                     a->right = p;
                    ans.push_back(a);
                }
            }
        }
         return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};