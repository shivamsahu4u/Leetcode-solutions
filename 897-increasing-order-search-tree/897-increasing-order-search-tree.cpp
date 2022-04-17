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
    TreeNode*tail = NULL , *head = NULL;
    void inorder(TreeNode*root){
        
        if(root == NULL){
            return ;
        }
        
        inorder(root->left );
        if(head == NULL){
           // cout<<root->val<<" ";
           TreeNode* node = new TreeNode(root->val);
              head = node;
              tail = node;
            cout<<node->val<<" ";
              //tail = tail->right;
        }else{
            //cout<<root->val<<" ";
             TreeNode* node = new TreeNode(root->val);
            tail->right = node;
            cout<<node->val<<" ";
            tail = tail->right;
        }
        inorder(root->right );
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        inorder(root );
            return head;
    }
};