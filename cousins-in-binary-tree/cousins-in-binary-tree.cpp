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
    
    int xdepth , xparent , ydepth , yparent;
    void helper(TreeNode*root , int x , int y , int d , int parent){
        
        if(root == NULL){
            return ;
        }
        
        if(root->val == x){
         xdepth = d;
            xparent = parent;
            return;
        }
        
        if(root->val == y){
            ydepth = d;
            yparent = parent;
            return;
        }
        
        helper(root->left , x , y , d + 1 , root->val);
        helper(root->right , x , y , d + 1 , root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        //depth , parent
        if(root== NULL){
            return false;
        }
        
        helper(root , x , y , 0 , 0);
        
        if(xdepth == ydepth && xparent != yparent){
            return true;
        }else{
            return false;
        }
    }
};