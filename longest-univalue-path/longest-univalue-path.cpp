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
    int s = INT_MIN;
    pair<int , int>helper(TreeNode* root){
        
        pair<int , int>ans;
        //ans.first  = length of that path
        //ans.second = that number whose path is formed
         ans.first = 0;
            ans.second = INT_MIN;
        if(root == NULL){
           
            return ans;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.first = 1;
            ans.second = root->val;
            s = max(s, ans.first);
            return ans;
        }
        
        pair<int , int>ans1 = helper(root->left);
        pair<int , int>ans2 = helper(root->right);
        //pair<length , number>
        
        int len1 = 0 , len2 = 0;
        
        if(root->val == ans1.second && root->val == ans2.second){
            int t = ans1.first + 1 + ans2.first;
            ans.first = max(ans1.first , ans2.first)  + 1;
            ans.second = ans1.second;
            s = max(s , t);
            return ans;
        }else if(root->val == ans1.second && root->val != ans2.second){
            len1 = ans1.first + 1;
            len2 = ans2.first;
            ans.first = max(len1 , len2);
            ans.second = ans.first == len1?ans1.second : ans2.second;
            s = max(s , ans.first);
            ans.first = ans1.first + 1;
            ans.second = ans1.second;
            return ans;
        }else if(root->val != ans1.second && root->val == ans2.second){
            len1 = ans1.first;
            len2 = ans2.first + 1;
            ans.first = max(len1 , len2);
            ans.second = ans.first == len1?ans1.second : ans2.second;
            s = max(s , ans.first);
            ans.first = ans2.first + 1;
            ans.second = ans2.second;
            return ans;
        }else if(root->val != ans1.second && root->val != ans2.second){
            len1 = ans1.first;
            len2 = ans2.first;
            int len3 = 1;
            ans.first = max(len3 , max(len1 , len2));
            
            if(ans.first == len3){
                ans.second =root->val;
            }else if(ans.first == len2){
                ans.second = ans2.second;
            }else{
                ans.second = ans1.second;
            }
            s = max(s , ans.first);
            ans.first = 1;
            ans.second = root->val;
            return ans;
        }
        return ans;
    }
    int longestUnivaluePath(TreeNode* root) {
        
         if(root == NULL){
             return 0;
         }
       
         helper(root).first;
        
        return s-1;
    }
};