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
    
    void helper(TreeNode* root , unordered_map<int , int>&hash){
        
        if(root == NULL) return;
        
        helper(root->left , hash);
        hash[root->val]++;
        helper(root->right , hash);
    }
    vector<int> findMode(TreeNode* root) {
     
        unordered_map<int , int>hash;
        helper(root , hash);
        int m = INT_MIN;
        for(auto it = hash.begin() ; it!=hash.end(); it++){
            if(it->second > m){
                m = it->second;
            }
        }
        
         vector<int>v;
        
        for(auto it = hash.begin() ; it!=hash.end(); it++){
            if(it->second == m)
            v.push_back(it->first);
        }
        
        return v;
    }
};