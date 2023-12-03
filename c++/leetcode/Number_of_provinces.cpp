// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces



// In short, find the connected components

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

using ll = long long;

class Solution {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    int find_root(int node){
        if(parents[node] == node){
            return node;
        }

        int root = find_root(parents[node]);
        parents[node] = root;
        return root;
    }

    void make_union(int u, int v){
        int pu = find_root(u);
        int pv = find_root(v);

        if(pu != pv){
            if(ranks[pu] < ranks[pv]){
                parents[pu] = pv;
            } else if (ranks[u] > ranks[v]) {
                parents[pv] = pu;
            } else {
                parents[pv] = pu;
                ranks[pu] += 1;
            }
        }


        // if(pu != pv){
        //     if(pu < pv){
        //         parents[pv] = pu;
        //         parents[pu] = pu;
        //     } else {
        //         parents[pu] = pv;
        //         parents[pv] = pv;
        //     }
        // }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int N = isConnected.size();
        parents.resize(N);
        ranks.resize(N);

        for(int i = 0; i < N; i++){
            parents[i] = i;
            ranks[i] = 1;
        }

        for(int u = 0; u < N; u++){
            for (int v = 0; v < N; v++){
                if(isConnected[u][v]){
                    make_union(u,v);
                }
            }
        }

        for(int i = 0 ; i < N; i++){
            find_root(i);
        }

        // for(int i = 0 ; i < N; i++){
        //     cout << parents[i] << "\t";
        // }
        // cout << endl;

        unordered_map<int,int> components;

        for(int i = 0; i < N; i++){
            components[parents[i]]++;
        }

        return components.size();
    }
};


int main(){

    Solution obj;

    vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

    auto start = std::chrono::system_clock::now();
    auto output = obj.findCircleNum(isConnected);
    auto end = std::chrono::system_clock::now();
    long elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    cout << "Output "  << output << endl;
    printf("Time Taken %ld us \n", elapsed);
    return 0;
}
