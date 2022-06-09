class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        
       int i = 0 , j = numbers.size()-1;
        vector<int>v;
        while(i < j){
            
            int s = numbers[i] + numbers[j];
            
            if(s == target){
                vector<int>v{i+1,j+1}; 
                return v;
            }else if(s < target){
               i++;
            }else{
                j--;
            }
        }
        return v;
//          for(int i = 0 ; i < numbers.size()-1 ; i++){
             
//              for(int j = i+1 ; j < numbers.size() ; j++){
                 
//                  if(numbers[i] + numbers[j] == target){
                     
//                      vector<int>ans{i+1 , j+1};
//                      return ans;
                     
//                  }
//              }
//          }
        
//         vector<int>a;
//         return a;
    }
};