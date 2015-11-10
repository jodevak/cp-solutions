#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,x;
	cin>>n;
	vll v(n);
	for(int i=0;i<n;++i)cin>>v[i];
	ll gcd=v[0],lcm=1;
	
	for(int i=1;i<n;++i) // 10^5 log 10^9
		gcd=__gcd(gcd,v[i]);

	for(int i=0;i<n;++i){ // 10^5 log 10^9?
		x=v[i]/gcd;
		while(!(x&1)) x>>=1;
		while(x%3==0) x/=3;
		if(x!=1){
			cout<<"No\n";
			return 0;
		}
	}

	cout<<"Yes\n";

	return 0;
}
