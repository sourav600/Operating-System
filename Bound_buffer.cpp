#include<iostream>
using namespace std;

#define nl '\n'
#define For(i,n) for(ll i=0; i<n; i++)

int semaphore = 1, full = 0, empt=10, item = 0;

void producer(){
    --semaphore;

    ++full;
    --empt;
    item++;

    cout<<"\n Producer produces: item "<<item<<nl;

    ++semaphore;
}

void consumer(){
    --semaphore;
    --full;
    ++empt;

    cout<<"\n Consumer consume: item"<<item<<nl;

    ++semaphore;
}

int main(){
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
            if(semaphore==1 && empt>0) producer();
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



