
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define base 1000000007
#define fi first
#define se second
#define ll long long
#define ii pair<int,int>
#define Dennis "shelf"
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)

using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
void File(){
	freopen(Dennis".inp", "r", stdin);
	freopen(Dennis".out", "w", stdout);
}
const int N = 2e5 + 5;
int n, a[N];

struct IT{
	struct node{
		node *rson, *lson;
		ll val, lazy;
		node(){
			lson = rson = nullptr;
			val = lazy = 0;
		}
	};
	
	node *root;
	IT(){
		root = new node();
	}
	
	void down(node *p){
		if(p -> lson != nullptr){
			p -> lson -> val += p -> lazy;
			p -> lson -> lazy += p -> lazy;
		}
		
		if(p -> rson != nullptr){
			p -> rson -> val += p -> lazy;
			p -> rson -> lazy += p -> lazy;
		}
		p -> lazy = 0;
	}
	
	void Up(node *p, int l, int r, int u, int v, ll val){
		if(l > r || l > v || r < u) return;
		if(l >= u && r <= v) {
			p -> val += val;
			p -> lazy += val;
			return;
		}
		int m = (l + r) / 2;
		if(p -> lson == nullptr) p -> lson = new node();
		if(p -> rson == nullptr) p -> rson = new node();
		down(p);
		Up(p -> lson, l, m, u, v, val);
		Up(p -> rson, m + 1, r, u, v, val);
		p -> val = p -> lson -> val + p -> rson -> val;
	}
	
	void update(int l, int r, ll val){
		Up(root, 1, n, l, r, val);
	}
	
	
	ll Ge(node *p, int l, int r, int u, int v){
		if(l > r || l > v || r < u) return 0;
		if(l >= u && r <= v) return p -> val;
		ll ret = 0;
		int m = (l + r) / 2;
		down(p);
		if(p -> lson != nullptr) ret += Ge(p -> lson, l, m, u, v);
		if(p -> rson != nullptr) ret += Ge(p -> rson, m + 1, r, u, v);
		return ret;
	}
	ll get(int l, int r){
		return Ge(root, 1, n, l, r);
	}
	
}T;

void solve(){
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int bla = uniform_int_distribution<int>(1, 100)(rng);
	File();
	int T = 1;
	//cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}

