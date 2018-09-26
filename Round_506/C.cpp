#include<bits/stdc++.h>
using namespace std;

struct pos {
	int l, r;
	pos() {};
	pos(int _l, int _r) {
		l = _l; r = _r;
	}
	bool operator<(const pos &io)const {
		return l < io.l;
	}
};

int n;
int high = 1;
pos tree[1200000];

pos find(int node, int nl, int nr, int fl, int fr) {
	if (fl <= nl && nr <= fr)return tree[node];
	if (nl > fr || fl > nr)return pos(0, 1000000007);
	int mid = (nl + nr) / 2;
	pos a = find(node * 2, nl, mid, fl, fr);
	pos b = find(node * 2 + 1, mid + 1, nr, fl, fr);
	return pos(max(a.l, b.l), min(a.r, b.r));
}

int main() {
	scanf("%d", &n);
	while (n > high)high <<= 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b)swap(a, b);
		tree[high + i] = pos(a, b);
	}
	for (int i = n; i <= high; i++) {
		tree[i + high] = pos(0, 1000000007);
	}
	for (int i = high - 1; i; i--) {
		tree[i].l = max(tree[i * 2].l, tree[i * 2 + 1].l);
		tree[i].r = min(tree[i * 2].r, tree[i * 2 + 1].r);
	}
	pos a = find(1, 1, high, 2, n);
	pos b = find(1, 1, high, 1, n - 1);
	int temp = max({ a.r - a.l, b.r - b.l, 0 });
	for (int i = 2; i < n; i++) {
		pos ll = find(1, 1, high, 1, i - 1);
		pos rr = find(1, 1, high, i + 1, n);
		temp = max(temp, min(ll.r, rr.r) - max(ll.l, rr.l));
	}
	printf("%d\n", temp);
	return 0;
}