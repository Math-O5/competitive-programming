#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int course[5], strongest, aux;
map<string, int> match;
string s;

void parse()
{
     s.clear();
     for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 3; ++j)
        {
            s += (char(course[i]%10)+'0');
            course[i] /= 10;
        }
    //cout << s << endl;
}

int main()
{
    int n;

    while(cin >> n, n > 0)
    {
        strongest = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < 5; ++j)
                cin >> course[j];
            sort(course, course+5);
            parse();
            aux = ++match[s];
            strongest = max(strongest, aux);
        }
        aux = 0;
        for(auto it = match.begin(); it != match.end(); ++it)
        {
            if(it->second == strongest)
                ++aux;
        }
        cout << aux*strongest << '\n';
        match.clear();
    }
    return 0;
}