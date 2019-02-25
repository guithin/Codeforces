#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll inp[200010];
ll loc[100010][2];
ll dp[100010];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= 2 * n; i++) {
		scanf("%lld", inp + i);
		if (loc[inp[i]][0])loc[inp[i]][1] = i;
		else loc[inp[i]][0] = i;
	}
	ll ans = 0;
	dp[1] = loc[1][0] + loc[1][1] - 2;
	for (ll i = 2; i <= n; i++) {
		dp[i] = min(abs(loc[i][0] - loc[i - 1][0]) + abs(loc[i][1] - loc[i - 1][1]), abs(loc[i][1] - loc[i - 1][0]) + abs(loc[i][0] - loc[i - 1][1])) + dp[i - 1];
	}
	printf("%lld\n", dp[n]);
	return 0;
}
