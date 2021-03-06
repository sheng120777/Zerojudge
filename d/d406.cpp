#include <bits/stdc++.h>
using namespace std;
#define int long long  

signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int s;
    int case_num=1;
    while(cin>>s){
        int n,m;
        cin>>n>>m;
        int grid[n][m];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int y=0;               //確定第一行有，所以直接設定
        int x;
        for(int j=0;j<m;j++){  //找第一行的第j個
            if(grid[0][j]==1){
                x=j;
                break;         //找到就break
            }
        }
        //這邊排列很細節，因為s=2水不能向上，所以最後一個是向上的
               //右 左 上 下
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        queue<int>qx;
        queue<int>qy;
        qx.push(x);
        qy.push(y);
        int for_num;
        while(!qx.empty()){
            x=qx.front();
            y=qy.front();
            qx.pop();
            qy.pop();
            for (int i=0;i<5-s;i++){
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0 and ty>=0 and tx<m and ty<n){  //判斷是否在界內
                    if(grid[ty][tx]==1){                //如果是1(水管)
                        grid[ty][tx]=grid[y][x]+1;      
                        qx.push(tx);
                        qy.push(ty);
                    }
                }
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]!=0){
                grid[0][j]=1;          //第一行的數字(開始位置)可能被改掉
                break;
            }
        }
        for(int i=1;i<n;i++){          //從第二行開始(所以for loop 從1開始)
            for(int j=0;j<m;j++){     
                if(grid[i][j]==1){     //把流不到的改0
                    grid[i][j]=0;
                }
            }
        }
        cout<<"Case "<<case_num<<":\n";
        case_num++;
        for(int i=0;i<n;i++){
            cout<<grid[i][0];
            for(int j=1;j<m;j++){
                cout<<" "<<grid[i][j];
            }
            cout<<"\n";
        }
    }
}
