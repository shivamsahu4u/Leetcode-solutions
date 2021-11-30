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
    
    TreeNode* helper(TreeNode* root , TreeNode* p , TreeNode* q){
        
        if(root == NULL){
            return root;
        }
        
        if(root->val == p->val){
            return p;
        }
        
        if(root->val == q->val){
            return q;
        }
        
        TreeNode*left = helper(root->left , p , q);
        TreeNode*right = helper(root->right , p ,q);
        
        if((left == p && right == q) || (right == p && left == q)){
            return root;
        }else{
            return left !=NULL?left:right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
         TreeNode*ans = helper(root , p , q);
        return ans;
    }
};