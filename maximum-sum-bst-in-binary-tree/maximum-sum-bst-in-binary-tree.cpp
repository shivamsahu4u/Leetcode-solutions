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
    
    class bst{
        public : 
        int sum;
        bool isBst;
        int mi;
        int mx;
    };
    int res = 0;
   bst helper(TreeNode* root ){
        
       bst ans;
         if(root == NULL){
            ans.sum = 0;ans.isBst = true;ans.mi = INT_MAX ; ans.mx = INT_MIN;
             return ans;
         }

        bst ans1 = helper(root->left);
        bst ans2 = helper(root->right);

        if(ans1.isBst == true && ans2.isBst == true && (root->val > ans1.mx && root->val < ans2.mi)){
            
            ans.isBst = true; // this tree is a bst;
            ans.sum = root->val + ans1.sum + ans2.sum;
            ans.mi =  min(ans1.mi , min(ans2.mi , root->val));
            ans.mx = max(ans2.mx , max(ans1.mx , root->val));
        }else{
            
            //this tree is not bst and moving forward due to this above trees can be bst also
            ans.isBst = false;
            ans.sum =  0;
        }
        
        res = max(res , ans.sum);
        
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
         return res > 0 ? res : 0;
    }
};