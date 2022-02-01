#include<stack>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
         //stack based question
        
        int n = prices.size();
        stack<int>s;
        s.push(prices[0]);
        int mx = 0;
        
        for(int i = 1 ; i < n ; i++){
            
          if(s.size() >  0 && prices[i] < s.top()) {
            while(s.size() >  0 && prices[i] < s.top()){
                s.pop();  
               
            } s.push(prices[i]);
          }else{
                int data;
                if(s.size() > 0 && prices[i] >= s.top()){
                  data  = s.top();
                    mx = max(mx , prices[i] - s.top());
                    s.pop();
                }
              s.push(data);
          }
            
        }
        
        return mx;
    }
};