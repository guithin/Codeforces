#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll inp[200010];
vector<ll>vec[15];

ll arr[15] = { 1 };

int main() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= 10; i++) {
		arr[i] = (arr[i - 1] * 10) % k;
	}
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
		ll temp = inp[i];
		ll cnt = 0;
		while (temp) {
			cnt++; temp /= 10;
		}
		vec[cnt].push_back(inp[i] % k);
		inp[i] %= k;
	}
	for (ll i = 1; i <= 10; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= 10; j++) {
			ll temp = (k - (inp[i] * arr[j]) % k) % k;
			ans += upper_bound(vec[j].begin(), vec[j].end(), temp) - lower_bound(vec[j].begin(), vec[j].end(), temp);
		}
	}
	for (ll i = 1; i <= 10; i++) {
		for (auto &it : vec[i]) {
			if ((it*arr[i] + it) % k == 0)ans--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}