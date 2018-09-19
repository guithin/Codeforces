#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	ll q; scanf("%lld", &q);
	while (q--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if ((a + b) & 1) {
			ll temp;
			if (n & 1)
				temp = n / 2 * n + n / 2 + 1;
			else
				temp = (n - 1) / 2 * n + (n - 1) / 2 + 1 + (n + 1) / 2;
			if (a & 1) {
				printf("%lld\n", (a - 1) / 2 * n + (b - 1) / 2 + 1 + temp);
			}
			else {
				printf("%lld\n", (a - 1) / 2 * n + (b - 1) / 2 + 1 + temp + n / 2);
			}
		}// > (n^2)/2
		else {
			if (a & 1) {
				printf("%lld\n", a / 2 * n + b / 2 + 1);
			}
			else {
				a--; b--;
				printf("%lld\n", a / 2 * n + b / 2 + 1 + (n + 1) / 2);
			}
		}
	}
	return 0;
}