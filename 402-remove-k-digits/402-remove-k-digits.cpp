class Solution {
public:
    string removeKdigits(string num, int k) {
     
        stack<char>q;
        
        if(num.size() <= k){
            return "0";
        }
        
        
        for(auto c : num){
            
            //c are the characters
            
            while(q.size() != 0 && k > 0 && q.top() > c){
                q.pop();
                k--;
            }
            
            if(!q.empty() || c != '0'){
                q.push(c);
            }
        }
        
        //there is case when the letters are in ascending order already
        
        while(q.size()!= 0 && k > 0){
            q.pop();
            k--;
        }
        
        int n = num.size();
        while(q.size()!=0){
            num[n-1] = q.top();
            q.pop();
            n--;
        }
        
        return num.substr(n) == ""?"0":num.substr(n);
        
    }
};