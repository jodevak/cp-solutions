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

	int n,t;
	cin>>n>>t;
	vi v(n);
	int mx=0,cntmax=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]>mx){
			mx=v[i];
			cntmax=1;
		} else if(v[i]==mx){
			++cntmax;
		}
	}

	int ans=0,last=0,i=0;
	while(t){
		if(v[i]>=last){
			++ans;
			last=v[i];
		}

		if(i==n-1){
			i=0,--t;
			if(last==mx){
				cout<<"here "<<last<<' '<<mx<<' '<<cntmax<<' '<<t<<'\n';
				ans+=cntmax*t;
				break;
			}

		} 
		else ++i;
	}

	cout<<ans<<'\n';
	
	return 0;
}
