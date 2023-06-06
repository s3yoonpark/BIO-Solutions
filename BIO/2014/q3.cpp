#include <bits/stdc++.h>

using namespace std; 

#define ll long long 

string map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 



string solve(ll n, vector<vector<ll>>& pascal_triangle) {
    string ans = "";  
    for (int i = 1; i < pascal_triangle[n].size(); ++i) {
        if (pascal_triangle[n][i] > n) {
            n -= pascal_triangle[n][i]; 
        } else {
            
        }
    }
    return ans; 
}

int main() {
    ll n; 
    cin >> n; 
    vector<vector<ll>> pascal_triangle(n+1, vector<ll>{}); 
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < i+1; ++j) {
            if (j == 0 || j == i) {
                pascal_triangle[i].push_back(1); 
                continue; 
            }
            pascal_triangle[i].push_back(pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j]); 
        }
    }

    cout << solve(n, pascal_triangle); 

    return 0; 
}