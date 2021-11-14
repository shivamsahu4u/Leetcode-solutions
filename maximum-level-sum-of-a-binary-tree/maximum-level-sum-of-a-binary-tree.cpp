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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int m = INT_MIN;
        int i = 0 , index;
        while(q.size()!=0){
            
            int size = q.size();
            int cur = 0;
            i++;
            for(int i = 0 ; i < size; i++){
                
                 TreeNode*front = q.front();
                 q.pop();
                
                 cur = cur + front->val;
                
                 if(front->left)q.push(front->left);
                 if(front->right)q.push(front->right);
            }
            
            if(cur > m){
                m = cur;
                index = i;
            }
            
        }
        
        return index;
    }
};