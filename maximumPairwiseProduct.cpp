#include <bits/stdc++.h>
using namespace std;

/* Brief: This program finds the maximum pairwise product
          from a list of integers. The algorithm runs in 
          O(n) time complexity.
*/
int main(){
vector <int> nums = {1,30,7,2,7,9,2,10};
    int maxidx1 = 0, maxidx2 = 0;
    if(nums[0]>nums[1]){
        maxidx1 = 0; maxidx2 = 1;
    }
    for(int i=0; i<nums.size(); i++){
        if (nums[i]>nums[maxidx1]){
            maxidx2 = maxidx1; maxidx1 = i;
        }
        else{
            if (nums[i]>nums[maxidx2])
                maxidx2 = i;
        }
    }
    cout<<nums[maxidx1]*nums[maxidx2]<<endl;
    return 0;
}