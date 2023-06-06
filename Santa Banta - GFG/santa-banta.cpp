//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<bool> check; vector<long long> primes;
    void precompute(){
        check.resize(2000002, true);
        check[0] = check[1] = false;
        for(long long i=2; i<=2000001; i++){
            if(check[i]){
                primes.push_back(i);
                for(long long j=i*i; j<=2000001; j+=i) check[j] = false;
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<bool> vis(n+1, false);
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                int c = 0;
                dfs(g, vis, i, c);
                ans = max(ans, c);
            }
        }
        if(ans < 2) return -1;
        else return primes[ans-1];
    }
    void dfs(vector<vector<int>>&graph, vector<bool>&vis, int node, int &cnt){
        vis[node] = true;
        cnt++;
        for(auto child : graph[node]){
            if(!vis[child]) dfs(graph, vis, child, cnt);
        }
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends