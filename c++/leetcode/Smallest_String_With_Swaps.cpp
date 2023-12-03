// You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

// You can swap the characters at any pair of indices in the given pairs any number of times.

// Return the lexicographically smallest string that s can be changed to after using the swaps.

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef pair<ll,ll> myPair;

stuct Graph{
    vector<ll> parents;
    // vector<ll> sizes;

    // vector<ll,mypair> edges;

    Graph(ll n){
        parents.resize(n);
        // sizes.resize(n);

        for(ll i = 0; i < n; i++){
            parents[i] = i;
            // sizes[i] = 0;
        }
    }

    ll find_root(ll node){
        if(parents[node] == node){
            return node;
        }

        ll root = find_root(parents[node]);
        parents[i] = root;
        return root;
    } // find_root ends

    void make_union(ll u, ll v){
        ll pu = find_root(u);
        ll pv = find_root(v);

        if(pu != pv){
            if(pu <= pv){
                // parents[pu] = pu;
                parents[pv] = pu;
            } else {
                parents[pu] = pv;
                // parents[pv] = pv;
            }
        }
    } // make_union ends

    
}