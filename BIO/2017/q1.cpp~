#include <bits/stdc++.h> 

using namespace std; 

int main() {
	string n; 
	cin >> n; 
	vector<vector<char>> dp (n.length(), vector<char>(n.length(), ' ')); 
	for (int i = 0; i < n.length(); ++i) {
		dp[0][i] = n[i]; 
	}
	for (int i = 1; i < n.length(); ++i) {
		for (int j = 0; j < n.length() - count(dp[i-1].begin(), dp[i-1].end(), ' ') - 1; ++j) {
			if (dp[i-1][j] == dp[i-1][j+1]) {
				dp[i][j] = dp[i-1][j]; 
			} else {
				vector<char> t = {'R', 'G', 'B'}; 
				t.erase(find(t.begin(), t.end(), dp[i-1][j])); 
				t.erase(find(t.begin(), t.end(), dp[i-1][j+1])); 
				dp[i][j] = t[0]; 
			}
		}
	}

	cout << dp[n.length()-1][0] << "\n"; 

	return 0; 
}
