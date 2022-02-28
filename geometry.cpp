/// templates GEOMETRY_BASIC vjp pro
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define fx(i,j,n) for(int i=(j);i<=(n);i++)
#define fn(i,j,n) for(int i=(j);i>=(n);i--)
#define x first
#define y second
using namespace std;

template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}

void file(){
	#define TASK "GEOMETRY_BASIC"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

const int Mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

#define ld long double
#define ll long long
#define ALL(v) (v).begin(), (v).end()
struct dt{
	ld a, b, c;
};

struct diem{
	ld x, y;
};
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433
struct Geometry_basic{

	// Vector ch? phýõng
	diem Vector_cp(diem a, diem b){
		return {b.x - a.x, b.y - a.y};
	}

	// Vector pháp tuy?n
	diem Vector_pt(diem a, diem b){
		return {a.y - b.y, b.x - a.x};
	}

	// phýõng tr?nh ðý?ng th?ng
	dt ptdt(diem a, diem b){
		diem tmp = Vector_pt(a, b);
		ld A = tmp.x, B = tmp.y, C = a.x*b.y - a.y*b.x;
		return {A, B, C};
	}

	// ki?m tra song song
	bool ktss(dt a, dt b){
		ld a1 = a.a, b1 = a.b, c1 = a.c;
		ld a2 = b.a, b2 = b.b, c2 = b.c;
		return (a1 * b2 == a2 * b1 && a1 * c2 != a2 * c1);
	}

	// ki?m tra c?t nhau
	bool ktgiao(dt a, dt b){
		ld a1 = a.a, b1 = a.b, c1 = a.c;
		ld a2 = b.a, b2 = b.b, c2 = b.c;
		return (a1 * b2 != a2 * b1);
	}

	// ki?m tra trùng
	bool kttrung(dt a, dt b){
		ld a1 = a.a, b1 = a.b, c1 = a.c;
		ld a2 = b.a, b2 = b.b, c2 = b.c;
		return (a1 * b2 == a2 * b1 && a2 * c1 == c2 * b1);
	}

	// ki?m tra vuông góc
	bool ktvuonggoc(diem a, diem b){
		ld x1 = a.x, y1 = a.y;
		ld x2 = b.x, y2 = b.y;
		return (x1*x2 + y1*y2 == 0);
	}

	// giao ði?m
	diem intersect(dt a, dt b){
		ld a1 = a.a, b1 = a.b, c1 = a.c;
		ld a2 = b.a, b2 = b.b, c2 = b.c;
		if (a1 == 0){
			swap(a1, a2); swap(b1, b2); swap(c1, c2);
		}
		ld y = (c1*a2 - c2*a1)/(a1*b2 - a2*b1);
		ld x = ((c2*a1*b1 - c1*a2*b1)/(a1*b2 - a2*b1) - c1)/a1;
		return {x, y};
	}

	// tích chéo (cross product)
	ll ccw(diem a, diem b, diem c){ // = 2 l?n di?n tích = |a|*|b|*sin(a, b)
    	diem p = Vector_cp(a, b);
    	diem q = Vector_cp(b, c);
    	return (1ll*p.x*q.y - 1ll*p.y*q.x); // abs(x1*y2 - x2*y1)/2 : di?n tích tam giác
    	// ccw > 0 => r? trái
    	// ccw < 0 => r? ph?i
    	// ccw = 0 => th?ng hàng
	}

	// kho?ng cách 2 ði?m
	ld dist(diem a, diem b){
    	ld X = (a.x - b.x);
    	ld Y = (a.y - b.y);
    	return sqrt(X*X + Y*Y);
	}

	// dt ða giác : 1/2 (t?ng xích ma (a[i].x - a[i - 1].x)*(a[i].y + a[i - 1].y))

	// nghi?m c?a phýõng tr?nh b?c 2
	diem nghiem(dt A){
		ld a = A.a, b = A.b, c = A.c;
		if (a == 0) return {-c/b, -c/b};
		ld delta = b*b - 4*a*c;
		if (delta < 0) return {-INF, -INF};
		if (delta == 0) return {-b/(2*a), -b/(2*a)};
		return {(-b - sqrt(delta))/(2*a), (-b + sqrt(delta))/(2*a)};
	}
} A;

int n;
diem a[N], b[N];
bool cmp(diem c, diem b)
{
    ll w = A.ccw(a[1], c, b);
    if (!w) return (c.x < b.x || (c.x == b.x && c.y < b.y));
     return w > 0;
}

void CONVEXHULL(){
	cin >> n;
	fx (i, 1, n)
	{
	    cin >> a[i].x >> a[i].y;
	     if(a[i].x < a[1].x || (a[i].x == a[1].x && a[i].y < a[1].y))
            swap(a[1], a[i]);
	}
    sort (a + 2, a + n + 1, cmp);
    int m = 1;
    b[1] = a[1];
    fx (i, 2, n)
    {
        while (m > 1 && A.ccw(b[m - 1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
    
}
void solve()
{
	
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	int T = 1;
	//cin>>T;
	while(T--)
	{
	solve();
	}
	return 0;
}
