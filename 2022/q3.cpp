#include <bits/stdc++.h>

using namespace std; 

#define ll long long 

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
string lower_case_alphabet = "abcdefghijklmnopqrstuvwxyz"; 

string solve(string n, ll c) {
    int l = n.length(); 
    vector<vector<char>> pref_list (l, vector<char>{}); 
    // int index = n.find('a'); 
    // pref_list[0].push_back(alphabet[index]); 
    // index = alphabet.find((char)(n[0] - 32));
    // pref_list[index].push_back('A'); 

    // now for the simulation 

    string start = ""; 
    for (int i = 0; i < l; ++i) start += '_'; 

    for (int i = 0; i < l; ++i) {
        int ind = n.find(lower_case_alphabet[i]); 
        start[ind] = lower_case_alphabet[i]; 
        // now check if there are any preceeding consecutive 
        
        for (int r = ind; r >= 0; --r) {
            if (start[r] != '_') {
                pref_list[i].push_back(alphabet[r]); 
            } else {
                break; 
            }
        }

        sort(pref_list[i].begin(), pref_list[i].end()); 
    }

    for (int i = 0; i < pref_list.size(); ++i) {
        cout << i << ": "; 
        for (int j = 0; j < pref_list[i].size(); ++j) {
            cout << pref_list[i][j] << " "; 
        }
        cout << endl; 
    }

    string ans = ""; 
    for (int i = 0; i < l; ++i) ans += '_'; 
    for (int i = 0; i < pref_list.size(); ++i) {
        if (pref_list[i].size() > 1) continue; 
        ans[i] = pref_list[i][0];
    }

    int last_count = 0; 

    for (int r = pref_list.size()-1; r >= 0; --r) {
        if (pref_list[r].size() > 1) {
            last_count = pref_list[r].size();
            break; 
        }
    }

    while (count(ans.begin(), ans.end(), '_') != 0) {
        int counter = 0; 
        long long product = 1; 
        int first; 
        for (int i = 0; i < pref_list.size(); ++i) {
            if (pref_list[i].size() > 1) {
                ++counter; 
                if (counter == 1) {
                    first = i; 
                    continue; 
                }
                product *= pref_list[i].size(); 
            }
        }

        if (counter == 1) {
            ans[first] = pref_list[first][c-1]; 
            return ans; 
        }
        
        if (c > product) {
            c -= product; 
            pref_list[first].erase(pref_list[first].begin()); 
            if (pref_list[first].size() == 1) ans[first] = pref_list[first][0]; 
        } else {
            ans[first] = pref_list[first][0]; 
            for (int i = 1; i < pref_list[first].size(); ++i) {
                pref_list[first].erase(i + pref_list[first].begin()); 
            }
        }
    }

    return ans; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    string n; ll c; 
    cin >> n >> c; 
    cout << solve(n, c);    

    return 0; 
}