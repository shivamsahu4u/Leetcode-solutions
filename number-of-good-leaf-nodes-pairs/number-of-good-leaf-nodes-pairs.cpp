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
    int count = 0;
    vector<int> helper(TreeNode* root , int s){
        
        if(root == NULL){
            vector<int>v;
           
            return v;
        }
        
        if(root->left == NULL && root->right == NULL){
            vector<int>v;
            v.push_back(1);
            return v;
        }
        
        vector<int>ans1 = helper(root->left , s);
        vector<int>ans2 = helper(root->right , s);
        
        for(auto i : ans1){
            
            for(auto j : ans2){
                
                 if(i + j <= s){
                     count++;
                 }
            }
        }
        
        for(int i = 0 ; i < ans1.size() ; i++){
            ans1[i]++;
        }
        
        for(int i = 0 ; i < ans2.size() ; i++){
            ans2[i]++;
            ans1.push_back(ans2[i]);
        }
        
    return ans1;
    }
    int countPairs(TreeNode* root, int distance) {
        
         helper(root , distance);
        return count;
    }
};