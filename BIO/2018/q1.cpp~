#include <bits/stdc++.h> 

using namespace std; 

double convert(double n) {
	n *= 100; 
	n = ceil(n); 
	n /= 100; 
	return n;
}

int main() {
	int in, re; 
	cin >> in >> re; 
	double debt = 10000; 
	double sum = 0; 
	while (debt != 0) {
		debt *= 1 + in/100.0; 
		debt = ceil(debt); 
		double t = debt * re / 100.0; 
		if (t < 5000) t = 5000; 
		if (t > debt) t = debt; 
		t = ceil(t); 
		sum += t; 
		debt -= t; 
	}
	cout << sum/100 << "\n";

	return 0; 
}
