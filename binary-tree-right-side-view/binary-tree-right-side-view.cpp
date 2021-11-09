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
    
    //Time complexity is O(n) because we will traverse to each node in worst case
    //Space complexity is O(1) + O(n) required space
    //more optimised
    void helper(TreeNode*root , int level , vector<int>&ans){
        
        if(root == NULL){
            return;
        }
        
        if(ans.size() < level){
            ans.push_back(root->val);
        }
        
        helper(root->right , level + 1 , ans);
        helper(root->left , level + 1 ,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
     
        
         vector<int>ans;
        
         helper(root , 1 , ans);
        
        return ans;
         //first method is through level order traversal
         // Time Complexity is O(n)
        //Space Complexity is O(h)(we are using queue here)
        
        /*vector<int>ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(q.size() != 0){
            
            TreeNode*front = q.front();
            q.pop();
            
            if(front == NULL){
                ans.push_back(v[v.size() -1]);
                v.clear();
                
                if(q.size() == 0){
                    return ans;
                }
                
                q.push(NULL);
            }else{
                
                v.push_back(front->val);
                
                if(front->left!=NULL){
                    q.push(front->left);
                }
                
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
        return ans;*/
    }
};
