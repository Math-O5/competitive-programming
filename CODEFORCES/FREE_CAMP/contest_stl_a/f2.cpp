    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<utility>
     
    using namespace std;
     
    vector<pair<long long int,long long int>> v;
     
    bool stable(const pair<long long int,long long int>&a, const pair<long long int,long long int>&b)
    {
        if(a.first - b.first >  a.second - b.second)
            return true;
        return false;
    }
    int main()
    {
        long long int n, a, b;
        cin >> n;
        while(n--)
        {
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }
     
        sort(v.begin(), v.end(), stable);
     
        long long int ans = 0;
        for(long long int i = 0; i < v.size(); ++i)
        {
            ans += (v[i].first*(i)) + (v[i].second*(v.size()-i-1));
        }
        cout << ans << '\n';
        return 0;
    }