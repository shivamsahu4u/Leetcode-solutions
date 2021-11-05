class Solution {
public:
    /*string longestCommonPrefix(vector<string>& strs) {
        
     
        string s = "";
        
        if(strs.size() == 0){
            return s;
        }
        
        for(int i =  0 ; i < strs[0].size() && strs[0].size() > 0 ; i++){
            
               char sr = strs[0][i];
              
            for(int j = 1 ; j < strs.size() ; j++){
                
                  if(sr != strs[j][i] || strs[j].size() < 0){
                    
                      return s;
                  }
            }
            
            s =  s + sr;
        }
        
        return s;
    }*/
    
    string longestCommonPrefix(vector<string>&strs) {

	if (strs.size() == 0)return "";
	if (strs.size() == 1)return strs[0];
	string s = "";
	int m = INT_MAX;
	for (int i = 1 ; i < strs.size() ; i++) {

		string st1 = strs[0];
		string st2 = strs[i];
		string p = "";
		for (int j = 0 ; j < st2.size() ; j++) {
			if (st2[j] != st1[j]) {
				break;
			}
			p = p + st2[j];
		}

		if (p.size() < m) {
			s = p;
            m = p.size();
		}
	}
	return s;
}
};