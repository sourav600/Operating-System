#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m; //no. of process, resource

    queue<int>q;
    for(int i=0; i<n;i++)q.push(i);

    int resource[m],available[m];
    for(int i=0; i<m;i++){
        cin>>resource[i];
        available[i]=resource[i]; //assume all resource are free
    }

    int maxNeed[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maxNeed[i][j];
        }
    }

    int allocation[n][m],need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
            need[i][j]= maxNeed[i][j]-allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }

    vector<int>v;
    int flag=0;
    while(!q.empty()){
            flag=0;
            int i= q.front();
            q.pop();
            for(int j=0;j<m;j++){
                if(available[j]<need[i][j]){
                    break;
                }
                else flag=flag+1;
            }
            if(flag>=m-1){
                for(int j=0;j<m;j++){
                    available[j]=available[j]+allocation[i][j];
                    need[i][j]=INT_MAX;
                }
                v.push_back(i);
            }
            else q.push(i);
        }
        cout<<"Safe sequence: \n";
        for(auto i:v)cout<<"P"<<i<<" ";
        cout<<endl;
        return 0;
}

//input
// 5 3
// 10 5 7
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
