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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	list<int> v;
	list<int>::iterator it1,it2,it3;
	int q,op,x,y,sum;
	cin>>q;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>x;
			v.push_back(x);
		} else {
			cin>>x>>y;
			--x,--y;
			it1=v.begin();
			advance(it1,x);
			it2=v.begin();
			advance(it2,y+1);
			// cout<<*it1<<' '<<*it2<<'\n';
			sum=accumulate(it1,it2,0);
			v.erase(it1,it2);
			v.push_back(sum);
		}
	}

	for(list<int>::iterator it=v.begin();it!=v.end();++it){
		cout<<*it;
		it1=it;
		if(++it1==v.end())cout<<'\n';
		else cout<<' ';
	}

	return 0;
}
