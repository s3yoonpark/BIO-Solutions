#include <bits/stdc++.h> 

using namespace std; 

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
int MAXADJ; 
unordered_map <string, unsigned long long int> mp; 

string convert(int p, int q, int r, char last_letter, int s) {
	string res; 
	res += to_string(p); 
	res += '_'; 
	res += to_string(q); 
	res += '_'; 
	res += to_string(r); 
	res += '_'; 
	res += last_letter; 
	res += '_'; 
	res += to_string(s); 
	return res;	
}


unsigned long long int countWays(int p, int q, int r, char last_letter, int s) {
	if (q == 0) return 0; 
	string save = convert(p,q,r,last_letter,s); 
	if (mp.find(save) != mp.end()) return mp[save]; 	
	if (s == r) return 1; 
	unsigned long long int total = 0; 
	for (char i : alphabet.substr(0, p)) {
		total += countWays(p, last_letter == i ? q-1 : MAXADJ, r, i, s+1); 
	}

	return mp[save] = total; 
}	

string solve(int p, int q, int r, long long int n) {
	string current = ""; 
	MAXADJ = q; 
	while (current.length() < r) {
		for (char i : alphabet.substr(0, p)) {
			unsigned long long int way = countWays(p, current[current.length()-1] == i ? q-1 : MAXADJ, r, i, current.length() + 1); 			
			if (way < n) {
				n -= way; 
			} else {
				if (current.length() >= 1) {
					if (current[current.length()-1] == i) {
						q -= 1;
					} else {
						q = MAXADJ; 
					}
				}
				current += i; 
				break; 
			}
		}	
	}	
	return current;
}

int main() {
	int p, q, r; unsigned long long int n; 
	cin >> p >> q >> r >> n; 
	cout << solve(p,q,r,n) << endl;	
	return 0; 
}
