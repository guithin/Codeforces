#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>vec[5010];
int ans[5010];

int dist(int a, int b) {
	if (a == b)return 0;
	if (a < b)return b - a;
	return b - a + n;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a == b)continue;
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end(), [i](int a, int b) {
			return dist(i, a) < dist(i, b);
		});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vec[j].size())
				ans[i] = max((unsigned int)ans[i], dist(i, j) + n * (vec[j].size() - 1) + dist(j, vec[j][0]));
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
