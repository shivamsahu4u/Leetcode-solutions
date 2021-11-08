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
        
        //now create a level first
        
        if(ans.size() == level){
            //create a level
            vector<int>v;
            ans.push_back(v);
        }
        
        ans[level].push_back(root->val);
        
        helper(root->left , level + 1 , ans);
        helper(root->right, level + 1 , ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>>ans;
        //taking level into consederation
        helper(root, 0 , ans);
        
        return ans;
        
        //Time Complexity is O(n)
        //Space Complexity is O(n) for queue
         /*vector<vector<int>>v;
        
        if(root == NULL){
           return v; 
        }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        while(q.size()!=0){
            
            TreeNode*front = q.front();
            q.pop();
            if(front == NULL){
                
                v.push_back(ans);
                
                if(q.size() == 0){
                    break;
                }
                
                q.push(NULL);
                ans.clear();
            }
            else{
                
                ans.push_back(front->val);
                
                if(front->left!=NULL){
                    q.push(front->left);
                }
                
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
        
        return v;*/
    }
};