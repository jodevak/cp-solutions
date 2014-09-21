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

int N;
string s_tinggi,s_warna;
vector<vvi> memo;

int f(int pos,int tinggi,int bitmask){
	if(pos==N) return 0;
	int &memo_now=memo[pos][tinggi][bitmask];
	if(memo[pos][tinggi][bitmask]!=-1) return memo_now;
	
	int hnow=s_tinggi[pos]-'0',cnow=s_warna[pos]-'0';
	if(tinggi<=hnow){
		if(bitmask & (1<<cnow)) memo_now=max(memo_now,f(pos+1,hnow,bitmask));
		else memo_now=max(memo_now,1+f(pos+1,hnow,bitmask|(1<<cnow)));
	}
	memo_now=max(memo_now,f(pos+1,tinggi,bitmask));
	return memo_now;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string dummy;
	getline(cin,dummy);

	cin>>N>>s_tinggi>>s_warna;
	memo.resize(N,vvi(10,vi((1<<10),-1)));

	cout<<f(0,0,0)<<'\n';


	return 0;
}
