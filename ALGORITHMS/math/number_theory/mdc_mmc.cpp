/******************************************************************************
    Máximo divisor comum (mdc) e 
    Mínimo divisor comum (mmc)
    
        Disponivel em,
            https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides#Demonstra.C3.A7.C3.A3o_da_termina.C3.A7.C3.A3o_e_exatid.C3.A3o_do_algoritmo
*******************************************************************************/

#include <iostream>

using namespace std;

/*
    Maximo dividor comum
        q =: quociente, r =: resto. 
        x = y * (q) + r
        x % y = r
        mdc(x,y) = mdc(y, x%y) = mdc(y, r)
        mdc(x, 0) = x.
*/
long long mdc(long long x, long long y) { return (y==0)? x : mdc(y, x%y);}

/*
    Minimo multiplo comum:
    mmc(x,y) * mdc(x,y) = x * y.
    (y / mdc) is first to avoid overflow.
*/
long long mmc(long long x, long long y) { return (x* (y / mdc(x,y)) ); }

int main()
{
    cout << mmc(5,3) << endl;
    cout << mdc(5,3) << endl;
    return 0;
}
