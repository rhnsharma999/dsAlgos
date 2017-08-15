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

//#include <bits/stdc++.h>
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
#define pii pair<ll,ll>
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

#define MAX 100

using namespace std;

int printNth(int arr[][MAX],int n,int m,int k){
    if(n < 1 || m < 1){
        return -1;
    }
    if(k <= m){
        return arr[0][k-1];
    }
    else if(k <= (n + m -1)){
        return arr[k-m][m-1];
    }
    else if(k <= (n + m - 1 + m -1)){
        return arr[n-1][m - 1 - (k - (n + m -1))];
    }
    else if(k <= (n + m -1 + m - 1 + n - 2)){
        return arr[(n-1) - (k - (n + m -1 + m - 1))][0];
    }
    return printNth((int (*)[MAX])(&arr[1][1]), n-2, m-2, k - ((n + m -1 + m - 1 + n - 2)));
}

int main() {
    int n,m;

    cin >>n >>m;
    int arr[MAX][MAX];
   // int arr[n][m];
    f(i,0,n){
        f(j,0,m){
            cin >>arr[i][j];
        }
    }
   // int k;
   // cin >>k;
    int x;
    while(1){
        cin >>x;
        cout <<printNth(arr, n, m,x) <<endl;
    }

}
