#define _USE__MATH__DEFINES
#include<iostream>
#include<cmath>
#include<utility>
#include<iomanip>
using namespace std;

int p, q,  r, s, t, u;

double solve(double x)
{
    return  p*pow(M_E, -x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    double ini, fim, mid;
    while(cin>>p>>q>>r>>s>>t>>u && (p != 0 || q != 0 || r != 0 || s != 0 || t != 0 || u != 0))
    {  
        ini = 0, fim = 1;
        while(ini <= fim)
        {
            mid = (ini + fim)/2;
            double aux = solve(mid);
            if(fabs(aux) < 0.00001)
            {
                cout << setprecision(4) << mid << '\n';
                break;
                //i did it
            } else 
            if(aux > 0)
                ini = mid + 0.000001;
            else
                fim = mid - 0.000001;
                //cout << aux << ' ' << mid << "...";
        }
        if(ini > fim)
            cout << "No solution\n";
    }
    return 0;
}