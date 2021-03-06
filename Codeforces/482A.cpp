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

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(int (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	vb udah(n+1,false);
	cout<<1;
	int last=1,now;
	udah[1]=true;
	for(int diff=k,tambah=1;diff>=1;--diff,tambah=1-tambah){
		now=(tambah?last+diff:last-diff);
		cout<<' '<<now;
		udah[now]=true;
		last=now;
	}

	for(int i=1;i<=n;++i)
		if(!udah[i])cout<<' '<<i;

	cout<<'\n';
	
	return 0;
}
