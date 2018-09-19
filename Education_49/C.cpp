#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inp[1000010];
ll arr[10010];
vector<ll>vec;

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);

		memset(arr, 0, sizeof(arr));
		vec.clear();
		bool flag = false;
		for (ll i = 1; i <= n; i++) {
			scanf("%lld", inp + i);
			arr[inp[i]]++;
			if (arr[inp[i]] == 2) {
				vec.push_back(inp[i]);
			}
			if (arr[inp[i]] == 4 && !flag) {
				printf("%lld %lld %lld %lld\n", inp[i], inp[i], inp[i], inp[i]);
				flag = true;
			}
		}
		if (flag)continue;
		sort(vec.begin(), vec.end());
		ll mj = vec[0] * vec[0] + vec[1] * vec[1];
		ll mo = vec[0] * vec[1];

		ll myi = 1;
		for (ll i = 2; i < vec.size(); i++) {
			ll tj = vec[i] * vec[i] + vec[i - 1] * vec[i - 1];
			ll tm = vec[i] * vec[i - 1];
			if (mj*tm > mo*tj) {
				mj = tj; mo = tm;
				myi = i;
			}
		}
		printf("%lld %lld %lld %lld\n", vec[myi], vec[myi], vec[myi - 1], vec[myi - 1]);
	}
	return 0;
}