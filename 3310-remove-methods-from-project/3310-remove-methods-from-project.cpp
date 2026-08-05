class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for(int next : adj[node])
        {
            if(!vis[next])
            {
                dfs(next, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Step 1 : Graph banao
        vector<vector<int>> adj(n);

        for(auto edge : invocations)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2 : DFS se suspicious methods mark karo
        vector<int> vis(n,0);

        dfs(k, adj, vis);

        // Step 3 : Check karo ki koi outside node
        // suspicious node ko call to nahi kar raha

        for(auto edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if(vis[u] == 0 && vis[v] == 1)
            {
                vector<int> ans;

                for(int i=0;i<n;i++)
                {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        // Step 4 : Suspicious methods hata do
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};