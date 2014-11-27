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

struct point{ 
    double x,y; 
    point(){}
    point(double a,double b):x(a),y(b){}
};
struct vec{ 
    double x,y; 
    vec(){}
    vec(double dx,double dy):x(dx),y(dy){}
    vec(point a,point b):x(b.x-a.x),y(b.y-a.y){}
};
struct line{
	point a,b;
	line(){}
	line(point x,point y):a(x),b(y) {}
};
point translate(point p,vec v){
    return point(p.x+v.x,p.y+v.y);
}
vec scale(vec v,double s){
    return vec(v.x*s,v.y*s);
}
double dist(point a,point b){
    return hypot(fabs(a.x-b.x),fabs(a.y-b.y));
}
double cross(vec a,vec b){
    return (a.x*b.y)-(a.y*b.x);
}
double cross(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool ccw(point a,point b,point c){
    return cross(a,b,c)< -EPS;
}
bool collinear(point a,point b,point c){
    return fabs(cross(a,b,c))<EPS;
}
bool parallel(point a,point b,point c,point d){
    return fabs((fabs(a.y-b.y)/fabs(a.x-b.x))-(fabs(c.y-d.y)/fabs(c.x-d.x)))<EPS;
}
double dot(vec a,vec b){
    return a.x*b.x+a.y*b.y;
}
double norm_sq(vec a){
    return a.x*a.x+a.y*a.y;
}
bool is_intersect(point a,point b,point c,point d){
    return (ccw(a,b,c)!=ccw(a,b,d)) && (ccw(c,d,a)!=ccw(c,d,b));
}
bool is_intersect(line a,line b){
	return is_intersect(a.a,a.b,b.a,b.b);
}
bool in_segment(point p,point a,point b){
    return fabs(dist(a,p)+dist(p,b)-dist(a,b))<EPS;
}
double dist_point_line(point p,point a,point b,point &intersection){
    vec ap(a,p), ab(a,b);
    double u=dot(ap,ab)/norm_sq(ab);
    intersection=translate(a,scale(ab,u));
    return dist(p,intersection);
}
point intersection(point a,point b,point c,point d){
    point intersect;
    double pembagi=(a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x);
    intersect.x=(((a.x*b.y)-(a.y*b.x))*(c.x-d.x)-
                 ((c.x*d.y)-(c.y*d.x))*(a.x-b.x))/pembagi;
    intersect.y=(((a.x*b.y)-(a.y*b.x))*(c.y-d.y)-
                 ((c.x*d.y)-(c.y*d.x))*(a.y-b.y))/pembagi;
    return intersect;
}
point intersection(line a,line b){
	return intersection(a.a,a.b,b.a,b.b);
}

bool cmp(point a,point b){
	return mp(a.x,a.y)<mp(b.x,b.y);
}

vector<point> monotone_chain(vector<point> p){
	vector<point> upper,lower;
	sort(p.begin(),p.end(),cmp);
	int n=p.size();

	for(int i=0;i<n;++i){
		while(upper.size()>=2 && cross(upper[upper.size()-2],upper[upper.size()-1],p[i])<0) upper.pop_back();
		upper.push_back(p[i]);
	}

	for(int i=n-1;i>=0;--i){
		while(lower.size()>=2 && cross(lower[lower.size()-2],lower[lower.size()-1],p[i])<0) lower.pop_back();
		lower.push_back(p[i]);
	}

	for(int i=1,len=lower.size();i<len;++i) upper.push_back(lower[i]);

	return upper;
}

double width(vector<point> p){
	double ret=1e10,tmp,w=0;
	point dummy;
	int n=p.size();
	for(int i=0;i<n-1;++i){
		tmp=0;
		for(int j=0;j<n-1;++j){
			if(j==i || j==i+1) continue;
			tmp=max(tmp,dist_point_line(p[j],p[i],p[i+1],dummy));
		}
		// cout<<tmp<<'\n';
		ret=min(ret,tmp);
	}
	return ret;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int tc=0,n;
	vector<point> pol,hull;
	while(cin>>n && n){
		cout<<"Case "<<++tc<<": ";
		pol.resize(n);
		for(int i=0;i<n;++i) cin>>pol[i].x>>pol[i].y;
		hull=monotone_chain(pol);
		cout<<fixed<<setprecision(2)<<width(hull)<<'\n';
	}	

	return 0;
}
