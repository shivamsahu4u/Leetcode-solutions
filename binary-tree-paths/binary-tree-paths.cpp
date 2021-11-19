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
    vector<string>ans;
    
    void helper(TreeNode* root , string s){
        
        if(root == NULL){
            return;
        }
        s = s + to_string(root->val) + "->";
        if(root->left == NULL && root->right == NULL){
            s.pop_back();s.pop_back();
            ans.push_back(s);
            s = "";
            return;
        }
        
        helper(root->left , s);
        helper(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
         helper(root , "");
        return ans;
    }
};