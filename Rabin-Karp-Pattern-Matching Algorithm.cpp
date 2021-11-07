/*
Time Complexity:
The average and best-case running time of the Rabin-Karp algorithm is O(n+m)
(when there is only one match)
but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs
when all characters of pattern and text are same as the hash values of all
the substrings of txt[] match with hash value of pat[]. For example
pat[] = “AAA” and txt[] = “AAAAAAA”.
*/
int robinKarp(string a , string b) {

	int n = a.size(); // actual string
	int m = b.size(); // pattern

	int no = 3 , c = 0, k = 0 , d = 0;
	string str = "";
	for (int i = 0 ; i < m ; i++) {

		int s = b[i] - 'a';
		c = s * pow(no , i) + c;
		int p = a[i] - 'a';
		d = p * pow(no, i) + d;
		str = str + a[i];
	}

	int u = 0;

	for (int i = m ; i < n ; i++) {

		if (str.size() == m && c == d) {

			if (str == b) {
				cout << str << " ";
				u++;
			}

		}
		char p = str[0];
		str = str.substr(1);
		d = ((d - (p - 'a')) / no) + (a[i] - 'a') * pow(no , m - 1);
		str = str + a[i];

	}
	if (str.size() == m && c == d) {

		if (str == b) {
			cout << str << " " << endl;
			u++;
		}

	}
	return u;

}
