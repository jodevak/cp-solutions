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

int c[]={1,2,5,10,20,50,100,200,500,1000};

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int n;
	cin>>n;
	int i=9,x;
	while(n){
		while(c[i]>n)--i;
		x=0;
		while(n>=c[i]){
			n-=c[i];++x;
		}
		cout<<c[i]<<' '<<x<<'\n';

	}

	return 0;
}
