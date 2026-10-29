class Solution {
public:
    int orangesRotting(vector<vector<int>>& gd) {
        int n=gd.size();
        int m=gd[0].size();
        
        //{{r,c}t}
         vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gd[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                   
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        //uppar neeche lft rgt
       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
       int tm=0;
       
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            
           for(int i=0;i<4;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<n && col>=0 && col<m
            && vis[row][col]!=2 && gd[row][col]==1){
                q.push({{row,col},tm+1});
                vis[row][col]=2;
                
            }
           }
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && gd[i][j]==1){
                    return -1;
                }
            }}
            return tm;
    }
};