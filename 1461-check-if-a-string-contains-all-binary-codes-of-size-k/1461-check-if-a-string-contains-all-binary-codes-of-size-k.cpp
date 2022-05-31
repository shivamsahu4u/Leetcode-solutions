class Solution {
public:
    bool hasAllCodes(string s, int k) {
      
         set<string>st;
        
        if(s.size() < k){
            return false;
        }
        for(int  j = 0 ; j <= s.size() - k ; j++){
       
            st.insert(s.substr(j , k));
            
        }   
       for(auto it = st.begin() ; it != st.end() ; it++){
           cout<<*it<<endl;
       }
        cout<<"---"<<"\n";
        return pow(2,k) == st.size();
            
    }
};