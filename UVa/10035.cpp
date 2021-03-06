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
 
//functions
template<class T,class Type> 
inline void reset(T begin, T end, Type fills=0){
	fill(begin,end,fills);
}
template<class T,class Type>
inline void reset(T stdcontainer, Type fills=0){
	fill(stdcontainer.begin(),stdcontainer.end(),fills);
}
template<class T,class Type>
inline void mfill(T container, int r, int c, Type fills=0){
	for(int i=0;i<r;++i)
		fill(container[i],container[i]+c,fills);
}
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string a,b;
	int c,carry,temp,la,lb;
	while(cin>>a>>b){
		if(a=="0" && b=="0") return 0;
		la=a.size(),lb=b.size();
		if(la<lb){
			swap(a,b);
			swap(la,lb);
		}
		c=carry=0;
		for(int i=la-1,j=lb-1;i>=0;--i){
			if(j>=0)temp=a[i]-'0'+b[j]-'0',--j;
			else temp=a[i]-'0';
			temp+=c;
			if(temp>9){
				c=1;
				++carry;
			} else {
				c=0;
			}
		}
		if(carry==0) cout<<"No carry operation.\n";
		else if(carry==1) cout<<"1 carry operation.\n";
		else cout<<carry<<" carry operations.\n";
	}

	return 0;
}
