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
#include <utility>
#include <dirent.h>
#include <pthread.h>
//#include <bits/stdc++.h>


#define ll  long long int
#define ull unsigned long long int
#define llu unsigned long long int
#define lld long long
#define ld long
//#define sc(a,b) scanf("%d %d",&a,&b)
#define fsentak for(ll i=0;i<n;i++)
#define f(a,z,b) for(ll a=z;a<b;a++)
#define sc(n) scanf("%d",&n)
#define nlc cout <<endl;
#define nl printf("\n");
#define all(x) x.begin(),x.end()
#define vc vector<int>
#define vvc vector< vector<int> >
#define pb(x) push_back(x)
#define zero(arr) memset(arr,0,sizeof(arr))
#define MOD 1000000007
#define test int t;scanf("%d",&t);while(t--)
#define IMAX std::numeric_limits<int>::max()
#define IMIN std::numeric_limits<int>::min()
#define IMAXLL std::numeric_limits<ll>::max()
#define IMINLL std::numeric_limits<ll>::min()
//#define lim 100000001
#define lolol 1000000
using namespace std;

//recursive
int fast_exp(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;

	if(b & 1) return (a * fast_exp(a*a,b/2));
	else return (fast_exp(a*a,b/2));
}

//iterative

int fast_exp1(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;

	int res = 1;
	while(b){
		if(b & 1){
			res *= a;
		}
		a = a*a;
		b/=2;
	}
	return res;
}
int main(){
	int x,y;
	while(1){
		cin >>x >>y;
		cout <<fast_exp1(x,y)<<endl;

	}


}
