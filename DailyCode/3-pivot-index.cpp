// Source https://leetcode.com/problems/find-pivot-index/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of 
the index is equal to the sum of all the numbers strictly to the index's right.

*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        unsigned int n = (int)nums.size();
        int leftsum[n + 1]; 
        
        leftsum[0] = 0;
        for(unsigned int i = 0; i < n; ++i) {
            leftsum[i + 1] = leftsum[i] + nums[i];
        }
        
        for(unsigned int i = 1; i <= n; ++i) {
            if(leftsum[i-1] - (leftsum[n]-leftsum[i]) == 0) {
                return i-1;
            }
        }
        
        return -1;
    }
};