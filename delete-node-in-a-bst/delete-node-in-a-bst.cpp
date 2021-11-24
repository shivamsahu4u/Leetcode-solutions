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
    
     TreeNode* deleteNode(TreeNode* root, int key) {
       
          if(root == NULL){
              return NULL;
          }
         
         if(root->left == NULL && root->right == NULL && root->val == key){
             return NULL;
         }
         if(key < root->val){
             root->left = deleteNode(root->left , key);
             return root;
         }else if(key > root->val){
             root->right = deleteNode(root->right , key);
             return root;
         }else{
             //root is the value of key
             
             if(root->left == NULL){
                 return root->right;
             }else if(root->right == NULL){
                 return root->left;
             }
             TreeNode*parent = root;
             TreeNode*curr = root->right;
             
             while(curr->left!=NULL){
                 parent = curr;
                 curr = curr->left;
             }
             
             if(parent == root){
                 parent->right = curr->right;
             }else{
                 parent->left =  curr->right;
             }
             
             root->val = curr->val;
             delete curr;
             return root;
         }
     }
   /* TreeNode* deleteNode(TreeNode* root, int key) {
        
         if(root == NULL){
             return root;
         }
        
        if(root->left == NULL && root->right == NULL && root->val == key){
            return NULL;
        }
        root->left = deleteNode(root->left , key);
        root->right = deleteNode(root->right , key);
        
        if(root->val == key){
        TreeNode*temp = root->right;
        
        if(temp == NULL){
            return root->left;
        }else{
            
            while(temp->left!=NULL){
                temp = temp->left;
            }
            
            swap(root->val , temp->val);
            
            root->right = deleteNode(root->right , temp->val);
            
            return root;
        }
        }else{
            return root;
        }
    }*/
};