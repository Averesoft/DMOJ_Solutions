#include <bits/stdc++.h>
using namespace std;
int main() {
    string a; getline(cin, a);
	string x, y, ans;
	int idx = a.find(',');
	if (a.length() - 1 - idx > 1) {
		x = a.substr(idx + 2, a.length() - 3 - idx);
		if (isalpha(x[0])) x[0] = toupper(x[0]); 
		y = a.substr(0, idx); 
		if (isalpha(y[0])) y[0] = tolower(y[0]); 
		ans = x;
		if (a.length() - idx < a.length()) ans += +" " + y;
		ans += a.substr(a.length() - 1);
	} else {
		ans = a.substr(0, a.length() - 2) +
		a.substr(a.length() - 1);
	}
	cout << ans;
}