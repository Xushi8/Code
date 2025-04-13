#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

enum {
	RED,
	BLACK,
};

struct node {
	int val;
	node *l, *r;
	
	node(int x = 0, node* left = nullptr, node* right = nullptr) : 
	val(x), l(left), r(right) {}
	
};

void build(node* root, int deep) {
	if(deep > 16) {
		return;
	}
	

	root->l = new node(root->val);
	root->r = new node(!(root->val));
	build(root->l, deep + 1);
	build(root->r, deep + 1);
}

node* root;

void solve1(int n, int k) {
	deque<node*> que;
	que.emplace_back(root);
	for(int i = 1; i < n; i++) {
		int siz = que.size();
		while(siz--) {
			node* p = que.front();
			que.pop_front();
			que.emplace_back(p->l);
			que.emplace_back(p->r);
		}
	}
	
	int ans = que[k - 1]->val;
	cout << (ans == RED ? "RED" : "BLACK") << '\n';
}

void solve2(int n, int k, int ans) {
	if(n == 1) {
		cout << (ans == RED ? "RED" : "BLACK") << '\n';
		return;
	}
	
	int num = (1 << (n - 1));
	if(k <= num / 2) { // left
		solve2(n - 1, k, ans);
	} else { // right
		solve2(n - 1, k - num / 2, !ans);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	root = new node(RED);
	build(root, 1);
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int n, k;
		cin >> n >> k;
		if(n <= 15) {
			solve1(n, k);
		} else {
			solve2(n, k, RED);
		}
	}
	
	
	return 0;
}
