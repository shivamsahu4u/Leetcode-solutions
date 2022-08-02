class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
          stack<int>s;
        unordered_map<int , int>hash;
        
        for(int i : nums2){
            
            while(s.size() && s.top() < i){
                
                 hash[s.top()] = i;
                 s.pop();
            }
            
            s.push(i);
        }
        
        vector<int>ans;
        
        for(int j : nums1){
            
             ans.push_back(hash.count(j) ? hash[j] : -1);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
//         unordered_map<int,int>hash;
//          for(int i = 0 ; i  < nums2.size() ; i++){
//              hash[nums2[i]] = i;
//          }
        
//         vector<int>v;
//         for(int i = 0 ; i < nums1.size(); i++){
            
//             int k = hash[nums1[i]];
//             int index = -1;
//             for(int j = k+1 ; j < nums2.size() ; j++){
                
//                 if(nums1[i] < nums2[j]){
//                     index = nums2[j];
//                     break;
//                 }
//             }
            
//             v.push_back(index);
//         }
        
//         return v;
//     }
// };