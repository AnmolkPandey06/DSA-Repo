vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
      vector<vector<int>> ans(n);
      for(int i=0;i<m;i++){
          int u=edges[i][0];
          int v=edges[i][1];
          ans[u].push_back(v);
          ans[v].push_back(u);

      }
      vector<vector<int>> finalans;
      for(int i=0;i<ans.size();i++){
          
                  vector <int> onepass;
                  onepass.push_back(i);
                  for(int j=0; j<ans[i].size();j++ ){
                      onepass.push_back(ans[i][j]);
                  }

                  finalans.push_back(onepass);


         

      }

      return finalans;

      