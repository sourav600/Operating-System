#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl '\n'
#define pi acos(-1)
#define ll long long
#define For(i,n) for(ll i=0; i<n; i++)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>

typedef unsigned long long  ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
const ll M = 1e9 + 7;
const ll N = 2e5 + 10;
vector<pair<int,int> > movements = { {+1,0},{-1,0},{0,+1},{0,-1} };
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
ll mod(ll a){ return ((a%M)+M)%M;}

void SOURAV(int tc){

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m; cin>>n>>m; //no. of process and frame
    int frame[m], process[n];
    For(i,n) cin>>process[i];
    For(i,m) cin>>frame[i];

    vector<int> allocation(n,-1);

    For(i,n){
        For(j,m){
            if(frame[j] >= process[i]){
                allocation[i] = j;
                frame[j] -= process[i];
                break;
            }
        }
    }
    For(i,n){
        cout<<"P"<<i+1<<" -> ";
        if(allocation[i]==-1){
            cout<<"Not allocated\n";
        }
        else cout<<"Frame No. "<<allocation[i]+1<<nl;
    }


return 0;
}


//input
// 4 5
// 212 417 112 426
// 100 500 200 300 600

// output
// P1 -> Frame No. 2
// P2 -> Frame No. 5
// P3 -> Frame No. 2
// P4 -> Not allocated
