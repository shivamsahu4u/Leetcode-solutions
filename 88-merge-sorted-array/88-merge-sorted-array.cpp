class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        //optimised solution , start filling it from last instead
        
        int i = m - 1 , j = n - 1 , k = m + n - 1;
        
        while(j >= 0){
            
          if(i <  0 || nums2[j] > nums1[i]){
              
              nums1[k--] = nums2[j--];
          } else{
              
              nums1[k--] = nums1[i--];
          } 
        }
        
        
        //brute force solution Tc -> O(m+ n) ans space Complexity -> O(m + n)
      /*  vector<int>ans;
        
        int i = 0 , j = 0;
        //space complexity => O(m + n)
        
        while(i < m && j < n){ // 0(n+  m) time complexity
            
            if(nums1[i] < nums2[j]){
                
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < m){
            ans.push_back(nums1[i]);
            i++;
        }
        
        while(j < n){
            ans.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        for(int i = 0 ; i <ans.size() ; i++){
            
            nums1.push_back(ans[i]);
        }*/
        
    }
};