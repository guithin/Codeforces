#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, p = 0, n = 0, z = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		if (!t)z++;
		else if (t > 0)p++;
		else n++;
	}
	if (p >= (N + 1) / 2) {
		printf("1\n");
	}
	else if (n >= (N + 1) / 2) {
		printf("-1\n");
	}
	else printf("0\n");
	return 0;
}
