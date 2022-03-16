class Solution {
public:
    // TC - O(N)
    // SC - O(N)
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
       int i = 0 , j = 0;
        
        for(auto x  : pushed){
            
             pushed[i] = x;
             i++;
            
            while(i > 0 && pushed[i-1] == popped[j]){
                j++;
                i--;
            }
        }
        return i==0;
    }
};

// TC - O(N)
// SC - O(N)
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
//         stack<int>st;
//         int j = 0 ;
//         for(int i = 0 ; i < pushed.size() ; i++){
            
//             st.push(pushed[i]);
            
//             while(st.size() > 0 && st.top() == popped[j]){
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.size() == 0;
//     }

//TC - O(N)
//SC - O(N)

//  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
//          int n = pushed.size();
//          // vector<bool>visited(n+1 , false);
//         unordered_map<int , bool>visited; 
//         int k = 0;
//          stack<int>st;
//          st.push(pushed[0]);
        
//          for(int i = 0 ; i < popped.size() ; i++){
             
//              if(visited[popped[i]] == true){
//                  return false;
//              }
             
//              if(st.size() > 0 && st.top() == popped[i]){
//                  int ele = st.top();
//                  st.pop();
//                  visited[ele] = true;
//              }else{
//                  k++;
//                 while(k < n && pushed[k]!=popped[i] ){
                  
//                     st.push(pushed[k]);
//                     k++;
//                 }
                 
//                 if(k >= n){
//                     return false;
//                 } 

//                 visited[popped[i]] = true; 
//              }
//          }
//         return true;
//     }