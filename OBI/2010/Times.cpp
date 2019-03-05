#include <bits/stdc++.h>

using namespace std;

int comp(pair<string,int> a,pair<string,int> b) {
    return a.second>b.second;
} 


int main()
{
 int n_alunos, m_times;
 cin >> n_alunos >> m_times;
 pair<string, int> aluno[n_alunos];
 vector<pair<string,int> >times[m_times];
 pair<string, int> a;
 for(int i=0;i<n_alunos;++i) {
     cin >> a.first >> a.second;
     aluno[i]=a;

 }
 int j=0;
 sort(aluno, aluno+n_alunos,comp);
 
  for(int i=0;i<n_alunos;++i) {
     if(j>=m_times) {j=0;}
           times[j].push_back(aluno[i]);
           j++;
    
 }
  for(int i=0;i<m_times;++i)
   sort(times[i].begin(),times[i].end());
  
  for(int i=0;i<m_times;++i) {
      printf("Time %d \n",i+1);
      for(int j=0;j<times[i].size();++j) {
          cout << times[i][j].first << "\n";
      }
      cout << "\n";
  }
 
 
    return 0;
}
