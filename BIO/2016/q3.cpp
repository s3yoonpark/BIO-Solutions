#include <bits/stdc++.h>

using namespace std; 

unordered_set<int> find_primes(int l) {
    unordered_set<int> primes; 
    vector<int> numbers (l, 1); 

    numbers[0] = 0; 
    numbers[1] = 0; 

    for (int i = 2; i < l+1; ++i) {
        if (numbers[i] == 0) {
            continue;
        }
        primes.insert(i); 
        
        for (int j = 2 * i; j < l+1; j += i) {
            numbers[j] = 0; 
        }
    }

    return primes; 
}

int shortest_path(unordered_set<int>& primes, int p, int q, int l) {
    queue<vector<int>> qu; 
    qu.push({1, p}); 
    int upper_bit_limit = floor(log(l)/log(2)) + 1; 
    primes.erase(find(primes.begin(), primes.end(), p)); 

    while (!qu.empty()) {
        vector<int> t = qu.front(); 
        qu.pop(); 

        int node = t[1]; 
        int prev_len = t[0]; 

        if (node == q) return prev_len; 

        for (int i = 0; i < upper_bit_limit; ++i) {
            int diff = 1 << i; 

            int next_one = node + diff; 
            if (primes.find(next_one) != primes.end()) {
                primes.erase(next_one); 
                qu.push({prev_len+1, next_one}); 
            }

            next_one = node - diff; 
            if (primes.find(next_one) != primes.end()) {
                primes.erase(next_one); 
                qu.push({prev_len+1, next_one}); 
            }
        }
    }
    cout << "NOT FOUND" << endl;
    return -1; 
}

int solve(int l, int p, int q) {
    unordered_set<int> primes = find_primes(l); 

    return shortest_path(primes, p, q, l); 
}

int main() {
    int l, p, q; 
    cin >> l >> p >> q; 
    cout << solve(l, p, q) << endl; 

    return 0; 
}
