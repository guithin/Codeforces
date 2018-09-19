#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char str[110] = {};
		scanf("%s", str);
		bool flag = false;
		for (int i = 0; i < n / 2; i++) {
			if (str[i] != str[n - i - 1] && abs(str[i] - str[n - i - 1]) != 2) {
				printf("NO\n");
				flag = true; break;
			}
		}
		if (!flag) {
			printf("YES\n");
		}
	}
	return 0;
}