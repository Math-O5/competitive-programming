
    #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 102000

int values[MAXN];
map<int, int> arvore[4*MAXN];   // max size 2^n + 2^(n-1) + ... 1

/**
 *       *[1,4]*           no (1)
 *  *[1,2]*   *[3,4]*     no (2) e (3), respectivamente.
 * 
 */ 
map<int,int>  build(int no, int i, int j) {

    if (i == j) {
        map<int, int> m;
        m[values[i]] = 1;
        arvore[no] = m;
        return arvore[no]; 
    } else {
        int meio = (i + j) / 2;
        map<int, int> arr_a, arr_b;
        arr_a = build(no*2, i, meio);
        arr_b = build(no*2+1, meio+1, j);

        for(auto& it : arr_b)
        {
            auto it_a = arr_a.find(it.first);
            if(it_a != arr_a.end())
                it_a->second += it.second;
            else arr_a[it.first] = it.second;
        }

        return arvore[no] = arr_a;
    }
}

// A, B é a query
// i, j é o intervalo atual
map<int,int> consulta(int no, int i, int j, int A, int B){
	
	if(A <= i && j <= B) { 
        return arvore[no];
	}
	
	if(i > B || A > j) {
        map<int, int> m;
        m[0] = 0; 
		return m;
	}
	
	int esquerda = 2*no;     
	int direita  = 2*no + 1; 
	int meio = (i + j)/2;
	
    map<int, int> a = consulta(esquerda, i, meio, A, B),
				b = consulta(direita, meio+1, j, A, B); 
       
    for(auto& it : b)
    {
         auto it_a = a.find(it.first);
            if(it_a != a.end())
                it_a->second += it.second;
            else a[it.first] = it.second;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, q;

    while(cin >> n, n > 0) {
        cin >> q;
        for(int i = 0; i < n; ++i) {
            cin >> values[i];
        } 

        build(1, 0, n-1);
            
        while(q-- > 0) {
            int l, r;
            cin >> l >> r;
            map<int, int> out = consulta(1, 0, n-1, l-1, r-1);
            int maxn = 0;
            for(auto& it : out)
            {
                maxn = max(it.second, maxn);
            }
            cout << maxn << endl;
        
        }
    }
	
    return 0;
}

