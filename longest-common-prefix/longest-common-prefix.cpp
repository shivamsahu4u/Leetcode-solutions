class Solution {
public:
   
    // -- Time Complexity :: O(max(string)*min(string))
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
    
    /*
    // -- Time Complexity is O(nlog(n))
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
    */
     
    /*
     Approach Third : 
     -- we can find maximum string in O(n) time
     -- we can find minimum string in O(n) time
     -- We can compare the max and min string in O(n) time
     
     so this can be done in O(n) time as a whole
    */
};
