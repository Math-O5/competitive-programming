/*
    Weighted Interval Schedule Problem

    1 <= begin <= end 

    Input: List of integers begin time task and end.
        (Begin task, End Task), 
                ..., 
        (Begin task, End Task)


    Output: The longest interval of task such that them don't have any conflit in schedule.

    tasks : Each tasks with your interval (begin, end)
    p(j)  : Greater indice i < j, such  that the intervals i  and j are disjunts. 

    1. Sort intervals by ending time.
    2. Calculate p
    3. OPT(j) the optimal sums to {1, 2, ..., j }

    if j is in the solution:
        OPT(j) = v[j] + OPT(p(j))
    else
        OPT(j) = OPT(j-1)

    source: http://www.lcad.icmc.usp.br/~jbatista/scc210/ProgDin1.pdf
*/ 
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX 100000

vector<pair<int, int>> tasks;
int p[MAX], memo[MAX];

int compute_opt(int j) {
    if(j == 0) 
        return 0;
    else if(memo[j])
        return memo[j];
    return memo[j] = max(tasks[j].second - tasks[j].first + compute_opt(p[j]), compute_opt(j - 1));
}

int iterative_opt(int numTasks) {

    memo[0] = 0;
    for(int i = 1; i < numTasks; ++i) {
        memo[i] = max(tasks[i].second - tasks[i].first + memo[p[i]], memo[i - 1]);
    }
}

bool mySort(pair<int, int> tasks1, pair<int, int> tasks2) {
    if(tasks1.second < tasks2.second) {
        return true;
    } else if(tasks1.second > tasks2.second) {
        return false;
    } else if(tasks1.first <= tasks2.first) {
        return true;
    }
    return false;
}

void calculate_p() {
   for(int i = 1; i < (int)tasks.size(); ++i) {
        int j = i - 1;
        while(j-- >= 0) {
            if(tasks[i].first > tasks[j].second) {
                p[i] = j + 1;
                break;
            }
        }
    }
}

int main() {
    int numTask, begin, end;

    cin >> numTask;
    tasks.push_back(make_pair(0, 0));

    for(int i = 0; i < numTask; ++i) {
        cin >> begin >> end;

        tasks.push_back(make_pair(begin, end));
    }

    sort(tasks.begin(), tasks.end(), mySort);

    calculate_p();

    cout << compute_opt(numTask) << '\n';
    cout << iterative_opt(numTask) << '\n';

    for(int i = 0; i < (int)tasks.size(); ++i) {
        cout << p[i] << ' ' << tasks[i].first << ' ' << tasks[i].second << endl;
    }

    return 0;
}