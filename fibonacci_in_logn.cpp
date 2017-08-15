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
#define sc(n) scanf("%lld",&n)
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
ll mod;
struct matrix{
    ll mat[2][2];

    void init(){
        memset(mat,0,sizeof(mat));
        mat[0][0] = mat[1][1] = 1;
    }
    void init1(){
        memset(mat,0,sizeof(mat));
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
    }
    void allZeros(){
     memset(mat,0,sizeof(mat));
    }
};


matrix mul(matrix a,matrix b){
    matrix c;
    c.allZeros();

    f(i,0,2) f(j,0,2) f(k,0,2) c.mat[i][k] = (c.mat[i][k] + (a.mat[i][j] * b.mat[j][k]))%mod;

    return c;
}
matrix fibo(ll n){
    matrix identity;
    identity.init();

    matrix nonIdent;
    nonIdent.init1();


    if(n==0) return identity;
    if(n==1) return nonIdent;

    while(n){
        if(n & 1){
            auto temp = mul(identity, nonIdent);
            identity = temp;
        }
        auto temp = mul(nonIdent, nonIdent);
        nonIdent = temp;
        n/=2;
    }
    return identity;
}
int main(){

    ll n,m;
    while(scanf("%lld %lld",&n,&m) != EOF){
        mod = 1 << m;
        cout <<fibo(n).mat[0][1] <<endl;
    }



}
