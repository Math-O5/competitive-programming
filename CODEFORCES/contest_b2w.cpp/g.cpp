#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1000000000;

struct coord{
    long long x,y;
    
    coord(long long x, long long y) : x(x), y(y) {};

    coord operator+(const coord& b) const {
        return coord(x + b.x, y + b.y);
    }

    coord operator-(const coord& b) const {
        return coord(x - b.x, y - b.y);
    }

    long long int operator*(const coord& b) const {
        return x*b.x + y*b.y;
    }

    long long int operator^(const coord& b) const {
        return x*b.y - y*b.x;
    }

    long long int magnitude() {
        return sqrt(x*x + y*y);
    }
};


bool isInsideTriangule(const coord& a, const coord& b, const coord& c, const coord& p) {
    if((((b-a)^(p-a)) < 0) &&
        (((c-b)^(p-b)) < 0) &&
        ((a-c)^(p-b)) < 0) {
        return false;
    } else return true;
}

struct triangulo{
    coord a,  b,  c;
};

long long         N, M, T; // N pontos, M triangulos, T pontos dentro de 1+ triangulo
coord       pontos[5*100001];
triangulo   triang[5*10001];


// double area_triangulo(const long long& x1, 
//                         const long long& y1,
//                         const long long& x2, 
//                         const long long& y2, 
//                         const long long& x3, 
//                         const long long& y3){
//     double a = abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
//     return a;
// }

// bool esta_dentro(const coord& ponto, const triangulo& triang) { 
//    double original = area_triangulo(triang.x1, triang.y1, triang.x2, triang.y2, triang.x3, triang.y3);   
//    double area_t1 = area_triangulo(ponto.x, ponto.y, triang.x2, triang.y2, triang.x3, triang.y3); 
//    double area_t2 = area_triangulo(triang.x1, triang.y1, ponto.x, ponto.y, triang.x3, triang.y3); 
//    double area_t3 = area_triangulo(triang.x1, triang.y1, triang.x2, triang.y2, ponto.x, ponto.y); 
    
//    return (original == (area_t1 + area_t2 + area_t3)); 
// } 

int main(void){
    T = 0;

    // lendo os valores
    scanf("%d %d", &N, &M);

    // lendo os pontos
    for(long long i = 0; i < N; i++)
        scanf("%d %d", &pontos[i].x, &pontos[i].y);

    // lendo os triangulos
    for(long long i = 0; i < M; i++) {
        scanf("%d %d %d %d %d %d", &triang[i].a.x, &triang[i].a.y, &triang[i].b.x, &triang[i].b.y, 
        &triang[i].c.x, &triang[i].c.y);
    }

    // Para cada ponto, verifica se ele está dentro de algum triangulo
    for(long long i = 0; i < N; i++){
        for(long long j = 0; j < M; j++){
            if(isInsideTriangule(triang[j].a, triang[j].b, triang[j].c,pontos[i])){
                T +=1;
                break;
            }
        }
    }

    int p = T*4;
    // Verificando o tipo
    if(T == N)
        printf("4");
    else if(p >= 3*N)
        printf("3");
    else if(p >= 2*N)
        printf("2");
    else if(p >= 1*N)
        printf("1");
    else // T == 0
        printf("0");

    return 0;
}