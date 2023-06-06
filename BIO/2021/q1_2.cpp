#include <bits/stdc++.h> 

using namespace std; 

bool check(string n) {
	if (n.length() == 1) return true; 
	bool ans = false; 
	for (int i = 1; i < n.length(); ++i) {
		string a = n.substr(0, i); 
		string b = n.substr(i, n.length()-i); 
		char mna = *min_element(a.begin(), a.end()); 
		char mxb = *max_element(b.begin(), b.end()); 
		if (mna > mxb) {
			reverse(a.begin(), a.end()); 
			reverse(b.begin(), b.end()); 
			ans |= (check(a) && check(b)); 
			if (ans) {
				return true; 
			}
		}
	}
	return ans; 
}

void pretty_print(bool x) {
	if (x) {
		cout << "YES" << "\n"; 
	} else {
		cout << "NO" << "\n"; 
	}
	return; 
}

int main() {
	string p, q; 
	cin >> p >> q; 
	pretty_print(check(p)); 
	pretty_print(check(q)); 
	pretty_print(check(p+q)); 

	return 0; 
}
