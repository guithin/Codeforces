#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	char str[110] = {};
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	int myi = 0;
	for (int i = 1; i <= n; i++) {
		if (!strncmp(str, str + i, n - i)) {
			myi = i; break;
		}
	}
	printf("%s", str);
	for (int i = 1; i < k; i++) {
		printf("%s", str + n - myi);
	}
	printf("\n");
	return 0;
}