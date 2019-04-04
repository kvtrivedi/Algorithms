/*
The Ruler of HackerLand believes that every citizen of the country should 
have access to a library. Unfortunately, HackerLand was hit by a tornado 
that destroyed all of its libraries and obstructed its roads! As you are 
the greatest programmer of HackerLand, the ruler wants your help to repair 
the roads and build some new libraries efficiently.

HackerLand has  cities numbered from  to . The cities are connected by  
bidirectional roads. A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.

The cost of repairing any road is c_road dollars, and the cost to build
 a library in any city is c_lib dollars. 
You are given q queries, where each query consists of a map of HackerLand
 and value of  and . For each query, find the minimum cost of making libraries
  accessible to all the citizens and print it on a new line.

Approach: DFS

*/


#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if (a>b)
        return a;
    return b;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities){
    long cost = 0;
    unordered_map<int,vector<int>> city_map;
    vector<bool> visited(n,false);
    for(int i=0;i<cities.size();i++){
        city_map[cities[i][0]].push_back(cities[i][1]);
        city_map[cities[i][1]].push_back(cities[i][0]);
    }
    
    for(int j=1; j<=n; j++){
        if(!visited[j]){
            stack <int> visit_stack;
            visit_stack.push(j); 
            visited[j] = true;
            int nodes = 1;
            while(visit_stack.size()){
                int cur = visit_stack.top();
                visited[cur] = true;
                visit_stack.pop();
                
                for(auto it:city_map[cur]){
                    if(!visited[it]){
                        visit_stack.push(it);
                        visited[it] = true;
                        nodes++;
                    }
                }
            }
            //cout<<"Nodes when j= "<<j<<" "<<nodes<<endl;
            if(c_lib<c_road){
                cost += c_lib*(nodes);
            }
            else{
                cost += c_lib + c_road*max(0,(nodes-1));
            }
        }
    }
    return cost;
}

int main()
{
    vector<vector<int>> cities = {{1,2},{2,3},{3,1}};
    cout<<roadsAndLibraries(3, 2, 1, cities);

    return 0;
}
