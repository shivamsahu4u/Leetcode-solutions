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
    vector<int> preorderTraversal(TreeNode* root) {
        
         vector<int>ans;
        if(root == NULL){
            return ans;
        }
         stack<TreeNode*>s;
          
         s.push(root);
        
        while(s.size() != 0){
            
             TreeNode*top = s.top();
            s.pop();
             if(top->right!=NULL)s.push(top->right);
             if(top->left!=NULL)s.push(top->left);
            
             ans.push_back(top->val);
        }
        return ans;
    }
};