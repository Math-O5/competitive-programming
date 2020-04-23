#include <cstdio>

int main() {
  
  for (int A, B, C, D; scanf("%d %d %d %d", &A, &B, &C, &D) == 4 && (A || B || C || D);) {
    if (A == B + C + D && B + C == D && B == C) {
      printf("S\n");
    }
    else {
      printf("N\n");
    }
  }
  
  return 0;
}
