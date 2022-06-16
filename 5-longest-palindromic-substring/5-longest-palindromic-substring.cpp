class Solution {
  public :
    string longestPalindrome(string s) {
        
     int n = s.size();

	bool **arr = new bool*[n];
	for (int i = 0 ; i < n ; i++) {

		arr[i] = new bool[n];

		for (int j = 0 ; j < n; j++) {

			arr[i][j] = false;
		}
	}

	for (int i = 0 ; i < n ; i++) {
		arr[i][i] = true;
	}
	int start = 0 , end = 0 , mx = 1;
	for (int i = n - 2 ; i >= 0 ; i--) {

		for (int j = i + 1 ; j < n ; j++) {

			if (s[i] == s[j]) {

				if (arr[i + 1][j - 1] || i == j - 1) {
					arr[i][j] = true;
					int len = j - i + 1;
					if (mx < len) {
						start = i;
						end = j;
                        mx = len;
					}
				}
			}
		}
	}
	string st = "";
	for (int i = start ; i <= end ; i++) {
		st = st + s[i];
	}
	return st;   
    }
    /*if ( s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        
        int len = max(len1, len2);
        if (len > (end - start)) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
            
            cout<<start<<" "<<end<<endl;
        }
    }
        
        
   string st = "";
        
        for(int i = start ; i <= end; i++ )st = st + s[i];
        
        return st;
}

 int expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}*/
};

//babad 