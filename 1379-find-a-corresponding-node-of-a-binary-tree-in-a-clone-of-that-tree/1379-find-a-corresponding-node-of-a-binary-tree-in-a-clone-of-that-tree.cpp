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
    int search(TreeNode*root , TreeNode*target){
        
        if(root == NULL){
            return -1;
        }
        
        if(root == target){
            return root->val;
        }
        
        int ans1 = search(root->left , target);
        int ans2 = search(root->right , target);
        
        if(ans1 != -1){
            return ans1;
        }else{
            return ans2;
        }
    }
    TreeNode* find(TreeNode* root , int target){
        
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == target){
            return root;
        }
        
        TreeNode*ans1 = find(root->left , target);
        if(ans1 != NULL){
            return ans1;
        }
        
        TreeNode*ans2 = find(root->right , target);
            return ans2;
    }
    TreeNode* get(TreeNode* root1 , TreeNode* root2 , TreeNode* target){
        
        if(root1 == NULL){
            return NULL;
        }
        
        if(root1 == target){
            return root2;
        }
        
       TreeNode*ans1 =  get(root1->left , root2->left , target);
       if(ans1 != NULL){
           return ans1;
       }
        
        TreeNode*ans2 = get(root1->right , root2->right , target);
        return ans2;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // int c = search(original , target);
       // return find(cloned , c);
    return get(original , cloned , target);
    }
};