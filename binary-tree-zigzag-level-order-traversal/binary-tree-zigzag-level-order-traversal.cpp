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
 
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
 
         vector<vector<int>>ans;
         if(root == NULL){
             return ans;
         }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        int i = 0;
        while(q.size()!=0){
            
            TreeNode*front = q.front();
            q.pop();
            
            if(front == NULL){
                
               if(i % 2 == 0){
                ans.push_back(v);    
               } else{
                   reverse(v.begin() , v.end());
                   ans.push_back(v);
               }
               
                v.clear();
                
                if(q.size() == 0){
                    break;
                }
                i++;
                q.push(NULL);
            }else{
                
                v.push_back(front->val);
                
                if(front->left!=NULL){
                    q.push(front->left);
                }
                
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
     //   reverse(ans.begin() ,ans.end());
        return ans;
    }
};