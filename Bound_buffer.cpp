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

int semaphore = 1, full = 0, empty=10, item = 0;

void producer(){
    --semaphore;

    ++full;
    --empty;
    item++;

    cout<<"\n Producer produces: item "<<item<<nl;

    ++semaphore;
}

void consumer(){
    --semaphore;
    --full;
    ++empty;

    cout<<"\n Consumer consume: item"<<item<<nl;

    ++semaphore;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cout<<"Choice List: \n";
    cout<<"\t1. Press 1 for producer\n";
    cout<<"\t2. Press 2 for consumer\n";
    cout<<"\t3. Press 3 for exit\n";

    int n;
    while(true){
        cout<<"Enter your choice: ";
        cin>>n;

        switch(n){
        case 1:
            if(semaphore==1 && empty>0) producer();
            else cout<<"Buffer is Full!\n";

            break;

        case 2:
            if(semaphore==1 && full>0) consumer();
            else cout<<"Buffer is Empty!\n";

            break;
        case 3:
            exit(0);
            break;
        }

    }
return 0;
}



