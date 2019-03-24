#include <bits/stdc++.h>
using namespace std;

/* Brief: This program takes in an array of ages of children and 
          places the children into groups such that maximum age
          difference between children of each group does not 
          exceed a given number 'd'. The purpose is to find the 
          minimum number of groups that do this.
*/

int main()
{
    vector<pair<int, int>> groups;
    vector<int> ages = {1,2,9,10,9,9,9,9,10,11,14,4,7,4,4,7,17}; // Vector of ages
    int d = 1; // Max difference between children in a group
    
    // Sort the vector - O(nlog(n))
    sort(ages.begin(), ages.end());

    int n = ages.size();
    int i = 0;
    int left, right;
    
    while(i<n){
        left = ages[i];
        right = ages[i] + d;
        i++;
        while(i<n && ages[i]<=right)
            i++;
        
        groups.push_back(make_pair(left, right));
    }
    cout<<"Min number of groups "<<groups.size()<<endl;
    for(auto it:groups){
        cout<<"("<<it.first<<","<<it.second<<"), ";
    }
    
    return 0;
}
