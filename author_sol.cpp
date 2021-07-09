#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<bool> dp(1024, false);
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 1024; j++) {
				bool temp1 = dp[j ^ a[i]];
				bool temp2 = dp[j];
				dp[j ^ a[i]] = temp1 | temp2;
			}
		}
		int ans = k;
		for (int i = 0; i < 1024; i++) {
			if (dp[i]) {
				ans = max(ans, k ^ i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
