#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int x1, x2, y1, y2;
int inp[60][60];
int p[60][60];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &inp[i][j]);
		}
	}
	queue<pair<int, int>>q;
	q.push(make_pair(x1, y1));
	p[x1][y1] = 1;
	while (q.size()) {
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)continue;
			if (inp[nx][ny] || p[nx][ny])continue;
			p[nx][ny] = 1;
			q.push(make_pair(nx, ny));
		}
	}
	if (p[x2][y2]) {
		printf("0\n");
		return 0;
	}
	q.push(make_pair(x2, y2));
	p[x2][y2] = 2;
	while (q.size()) {
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)continue;
			if (inp[nx][ny] || p[nx][ny])continue;
			p[nx][ny] = 2;
			q.push(make_pair(nx, ny));
		}
	}
	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					if (p[i][j] == 1 && p[k][l] == 2) {
						ans = min(ans, (i - k)*(i - k) + (j - l)*(j - l));
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
