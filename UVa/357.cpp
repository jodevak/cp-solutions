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
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

const int coins[5]={1,5,10,25,50};
vector<vector<ll> > memo(30005,vector<ll>(5,-1));

ll f(int n,int type=0){
	if(n<0) return 0;
	if(type==5 && n!=0) return 0;
	if(n==0) return 1LL;
	if(memo[n][type]!=-1) return memo[n][type];
	memo[n][type]=1LL*f(n-coins[type],type)+f(n,type+1);
	return memo[n][type];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	while(cin>>n){
		if(f(n)==1)
			cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
		else
			cout<<"There are "<<f(n)<<" ways to produce "<<n<<" cents change.\n";
	}

	return 0;
}
