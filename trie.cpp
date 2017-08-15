#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <bitset>
#include <utility>
#include <dirent.h>
#include <string>
#include <pthread.h>


#include <stdio.h>

#define ll  long long int
#define ull unsigned long long int
#define llu unsigned long long int
#define lld long long
#define ld long
//#define sc(a,b) scanf("%d %d",&a,&b)
#define fsentak for(int i=0;i<n;i++)
#define f(a,z,b) for(int a=z;a<(int)b;a++)
#define sc(n) scanf("%d",&n)
#define nlc cout <<endl;
#define nl printf("\n");
#define all(x) x.begin(),x.end()
#define vc vector<int>
#define vvc vector< vector<int> >
#define pb(x) push_back(x)
#define zero(arr) memset(arr,0,sizeof(arr))
//#define MOD 1000000007
#define test int t;scanf("%d",&t);while(t--)
#define IMAX std::numeric_limits<int>::max()
#define IMIN std::numeric_limits<int>::min()
#define IMAXLL std::numeric_limits<ll>::max()
#define IMINLL std::numeric_limits<ll>::min()
#define m(a,b) (((a%MOD) * (b%MOD))%MOD)
//#define lim 100000001
#define lim 1000001


using namespace std;


struct node{
    map<char,node*> s;
    bool isLeaf;
    int count;

};

node* root = new (struct node);
node* getNode(){
    node* newNode = new (struct node);
    newNode->isLeaf = false;
    newNode->count = 0;
    return newNode;
}

int dhundo(string data){
    auto temp = root;
    for(int i = 0; i < data.size() ;i++){
        if(!(temp->s[data[i]])) return 0;
        temp = temp->s[data[i]];
    }
    return temp->count;
}

void insert(string data){
    auto temp = root;
    for(int i = 0; i < data.size() ;i++){
        if(!(temp->s[data[i]])){
            temp->s[data[i]] = getNode();
        }

        temp = temp->s[data[i]];
        (temp->count)++;
    }
    temp->isLeaf = true;
}
int main(){
    int n;
    cin >>n;
    string x,y;
    while(n--){
        cin >>x >>y;
        if(x == "add"){
            insert(y);
        }
        else{
            cout <<dhundo(y) <<endl;
        }
    }
}
