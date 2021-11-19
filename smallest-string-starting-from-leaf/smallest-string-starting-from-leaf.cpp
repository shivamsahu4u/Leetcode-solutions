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
    string ans = "";
    void helper(TreeNode* root , string s){
        
        if(root == NULL){
            return;
        }
        char t = root->val + 97;
        s = s + t;
        
        if(root->left == NULL && root->right == NULL){
            reverse(s.begin() , s.end());
            if(ans == ""){
                ans = s;
            }else{
                if(s < ans){
                    ans =s ;
                }
            }
            s = "";
            return;
        }
        
        helper(root->left , s);
        helper(root->right , s);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        helper(root , "");
        return ans;
    }
};