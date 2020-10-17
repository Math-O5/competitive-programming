#include<iostream>
#include<string>

using namespace std; 

int t, n;

int magic(const string& s, char nivel) {
    int length = s.size();
    
    if(length == 1) {
        if(s[0] == nivel) return 0;
        else return 1;
    }
    int rightScore = 0, leftScore = 0;
    
    int scoreL =  magic(s.substr(0, length/2), nivel + 1);
    int scoreR =  magic(s.substr(length/2, length/2), nivel + 1);
    
    for(int i = 0; i < length/2; ++i) {
        if(s[i] == nivel) {
            leftScore++;
        }
    }

    for(int i = length/2; i < length; ++i) {
      if(s[i] == nivel) {
            rightScore++;
        }
    }

    scoreR += (length/2) - rightScore;
    scoreL += (length/2) - leftScore;
    
    return min(scoreL, scoreR);
}

int count(string a,int l,int r,char c)
{
	int count=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==c)
			count++;
	}
	return count;
}

// int calc(const string& s, char c) {
// 	if (s.size() == 1) {
// 		return s[0] != c;
// 	}
// 	int mid = s.size() / 2;
// 	int cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
// 	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
// 	int cntr = calc(string(s.begin() + mid, s.end()), c + 1);
// 	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
// 	return min(cntl, cntr);
// }

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cin >> t;   
    string s;
    
    while(t--) {
        cin >> n;
        cin >> s;
        cout << magic(s, 'a') << endl;
    }
    
    return 0;
}