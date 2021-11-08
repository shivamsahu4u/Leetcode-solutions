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
    
    void helper(TreeNode*root , int level , vector<vector<int>>&ans){
        
         if(root == NULL){
             return;
         }
        
        //level is now there , then create a level
        if(level == ans.size()){
            vector<int>v;
            ans.push_back(v);
        }
        
        ans[level].push_back(root->val);
        
        helper(root->left , level + 1 , ans);
        helper(root->right , level + 1 ,ans);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
 
         vector<vector<int>>ans;
        
         helper(root , 0 ,  ans);
        
        reverse(ans.begin() , ans.end());
        return ans;
         /*vector<vector<int>>ans;
         if(root == NULL){
             return ans;
         }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        
        while(q.size()!=0){
            
            TreeNode*front = q.front();
            q.pop();
            
            if(front == NULL){
                
                ans.push_back(v);
                v.clear();
                
                if(q.size() == 0){
                    break;
                }
                
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
        reverse(ans.begin() ,ans.end());
        return ans;*/
    }
};