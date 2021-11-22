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
    bool isEvenOddTree(TreeNode* root) {
        
         // using queue
        //Time Complexity - O(n)
        //Space Complexity - O(n) (using queue)
        
        if(root == NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        int l = 0;
        while(q.size()!=0){
            
            int s = q.size();
            
            int m = INT_MIN , n = INT_MAX;
            for(int i = 0 ; i < s ;i++){
                
                 TreeNode*front = q.front();
                 q.pop();
                 if(l % 2 == 0){
                     if(front->val > m && front->val % 2 != 0){
                         m =front->val;
                     }else{
                         return false;
                     }
                 }else{
                     if(front->val < n && front->val % 2 == 0){
                         n = front->val;
                     }else{
                         return false;
                     }
                 }
                
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            l++;
        }
        return true;
    }
};