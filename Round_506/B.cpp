#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll inp[200010];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	sort(inp + 1, inp + 1 + n);
	ll cnt = 1;
	ll flag = inp[1];
	ll temp = 1;
	for (ll i = 2; i <= n; i++) {
		if (flag * 2 >= inp[i]) {
			flag = inp[i]; temp++;
		}
		else {
			cnt = max(temp, cnt); temp = 1; flag = inp[i];
		}
	}
	cnt = max(cnt, temp);
	printf("%lld\n", cnt);
	return 0;
}