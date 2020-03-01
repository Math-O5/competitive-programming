#include<iostream>
#include<deque>
using namespace std;

int n, m, k, aux;
deque<int> reator;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i = 1; i <= n ; ++i)
    {
        cin >> aux;
        reator.push_back(aux);
    }

    for(int i=0; i<m; ++i)
    {
        deque<int> d;
        int strongest = 0;
        for(int j = 0; j < k && !reator.empty(); ++j)
        {
            d.push_back(reator.front());
            strongest = max(strongest, d.back());
            reator.pop_front();
        }
        cout << strongest << ' ';
        for(int j = 0; j < k && !d.empty(); ++j)
        {
            if(strongest != d.front())
            {
                reator.push_back(d.front());
            } else
                strongest = -1;
            d.pop_front();
        }
    }
    cout << '\n';
    return 0;
}

