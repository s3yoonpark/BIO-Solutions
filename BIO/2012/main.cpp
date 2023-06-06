#include <bits/stdc++.h> 

using namespace std; 

typedef unsigned long long ull; 

set<int> pr; 

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p]) pr.insert(p); 
}

ull solve(ull n) {
	ull prod = 1; 
	unordered_set<int> s; 
	while (n != 1) {
		for (int i : pr) {
			if (n % i == 0) {
				n /= i; 
				s.insert(i); 
				break; 
			}
		}
	}
	for (auto& i : s) {
		prod *= i; 
	}
	return prod;
}

int main() {
	SieveOfEratosthenes(1000000); 
	ull n; 
	cin >> n; 
	cout << solve(n) << "\n"; 

	return 0; 
}
