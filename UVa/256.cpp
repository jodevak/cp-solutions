//IO
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
 
//C Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
 
//container
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
 
//misc
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<int,ii> iii;
typedef pair<double,dd> ddd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vc> vvc;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define mp3(_x,_y,_z) make_pair((_x),(mp(_y,_z)))
#define fir first
#define sec second
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n')
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

//classes

//Union Find
class UnionFind{
private:
	vi parent;
	vi rank;
public:
	UnionFind(int n){
		rank.resize(n,0);
		parent.resize(n);
		for(int i=0;i<n;++i)parent[i]=i;
	}
	int findSet(int i){
        return (parent[i]==i)? i : (parent[i]=findSet(parent[i]));
	}
	bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
	}
	void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i), y=findSet(j);
            if(rank[x]>rank[y]) parent[y]=x;
            else {
                parent[x]=y;
                if(rank[x]==rank[y]) ++rank[y];
            }
        }
	}
};

// int power10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

// bool can(int x,int d){
// 	int original=x;
// 	int n=0;
// 	d>>=1;
// 	for(int i=0;i<d;++i){
// 		n=(x%10)*power10[i]+n;
// 		x/=10;
// 	}
// 	//cout<<x<<' '<<n<<'\n';
// 	return (((x+n)*(x+n))==original);
// }

// void print(int x,int d){
// 	cout<<setw(d)<<setfill('0')<<x;
// 	cout<<'\n';
// }

string ans[]={"","00\n01\n81","","0000\n0001\n2025\n3025\n9801","","000000\n000001\n088209\n494209\n998001","","00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001"};
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,MAX;
	while(cin>>n){
		// MAX=1;
		// for(int i=0;i<n;++i)MAX*=10;
		// for(int i=0;i*i<MAX;++i){
		// 	if(can(i*i,n))print(i*i,n);
		// }
		cout<<ans[n-1]<<'\n';
	}

	return 0;
}
