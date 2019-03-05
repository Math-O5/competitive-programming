#include <bits/stdc++.h>

using namespace std;

vector< pair<int, double> > x;
map<int, double> r;
set<int> S;

bool sortpair(const pair<int, double> a, const pair<int, double> b){
	return a.second < b.second;
}

int main() {
	int n, seg;
	double ans;
	double x1,y1,x2,y2,r1;
	cin >> n;
	while(n--){
		getchar();
		cin >> seg;
		for(int i = 0; i < seg; ++i){
			cin >>x1>>y1>>x2>>y2>>r1;
			x.push_back(make_pair(i,x1));
			x.push_back(make_pair(i,x2));
			r.insert(make_pair(i,r1));
		}
		sort(x.begin(),x.end(), sortpair);
		ans = 1.000;
		
		cout << setprecision(3) << fixed;
		double xinicial = x[0].second;
		cout << "-inf" <<", "<<xinicial<<" -> "<<ans<<endl;
		S.insert(x[0].first);
		for(int i = 1; i < x.size(); ++i){
		    if(S.find(x[i].first) == S.end()) {
		        S.insert(x[i].first);
		        ans = (double)ans*r[x[i-1].first];
		        cout << xinicial <<", "<<x[i].second<<" -> "<<ans<<endl;
		    }
		    else {
		        S.erase(x[i].first);
		        if() ans = ans*r[x[i-1].first];
		        cout << xinicial <<", "<<x[i].second<<" -> "<<ans<<endl;
		        ans = ans/r[x[i].first];
		    }
		    xinicial = x[i].second;
		    cout << "ans" << ans << endl;
		}
		x.clear();
		r.clear();
	}

return 0;
}

/* #2

#include <bits/stdc++.h>
using namespace std;

bool sortpair(const pair<int, double>a, const pair<int, double>b){
	return a.second < b.second;
}

int main() {
	int n, seg;
	double x1,y1,x2,y2,r1;
	cin >> n;
	while(n--){
		getchar();
		cin >> seg;
		for(int i = 0; i < seg; ++i){
			cin >>x1>>y1>>x2>>y2>>r1;
			x.push_back(make_pair(i,x1));
			x.push_back(make_pair(i,x2));
			r.push_back(insert(make_pair(i,r1)));
		}
		sort(x.begin(),x.end(), sortpair);
		cout << "-inf" <<", "<<x[0].first<<" -> "<<x[0].second<<endl;
	}

return 0;
}

*/
