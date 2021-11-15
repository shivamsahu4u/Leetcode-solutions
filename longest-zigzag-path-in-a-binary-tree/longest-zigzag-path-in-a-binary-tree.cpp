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
    int ans = 0;
   void inorder(TreeNode* root,bool dir,int len){
        
        if(root==NULL) return ;
         
        ans=max(ans,len);
        if(dir==0){
            inorder(root->left,1,len+1);
            inorder(root->right,0,1);
        }
        else{
             inorder(root->right,0,len+1);
             inorder(root->left,1,1);
        }
         
        return ;
       } 
    
    int longestZigZag(TreeNode* root) {
        ans=0;
         inorder(root->left,1, 1);
         inorder(root->right,0, 1);
        
        return ans ;
    }
};