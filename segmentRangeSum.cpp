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

int *st;


void updateUtil(int ss,int se,int si,int diff,int i){
	if(i < ss || i > se) return;

	st[si] += diff;
	if(ss != se){
		int mid = (ss + se)/2;
		updateUtil(ss,mid,2*si+1,diff,i);
		updateUtil(mid+1,se,2*si+2,diff,i);
	}
}
void update(int newVal,int index,int n,int *arr){

	if(index < 0 || index > n-1) return ;
 	int diff = -(arr[index] - newVal);
	arr[index] = newVal;
	updateUtil(0,n-1,0,diff,index);
}
int query(int ss,int se,int si,int qs,int qe){
	if(ss >= qs && se <= qe){
		return st[si];
	}
	if(ss > qe || se < qs) return 0;

	int mid = (ss+se)/2;
	return (query(ss,mid,2*si+1,qs,qe)+query(mid+1,se,2*si+2,qs,qe));
}

int buildUtil(int ss,int se,int si,int arr[]){
	if(ss == se){
		return st[si] = arr[ss];
	}
	int mid = (ss+se)/2;
	st[si] = (buildUtil(ss,mid,2*si+1,arr) + buildUtil(mid+1,se,2*si+2,arr));
	return st[si];
}
void build(int n,int arr[]){
	st = new int[4*n];
	memset(st,0,4*n*sizeof(int));
	buildUtil(0,n-1,0,arr);
}


int main(){

	int arr[] = {1,2,3,4,5};
	int n = 5;
	build(n,arr);
	int x,y,z;
	while(1){
		cout <<"1 for sum and 2 for update\n";
		cin >>x;
		cin >>y >>z;
		if(x==1){
			cout <<query(0,n-1,0,y-1,z-1) <<endl;
		}
		else{
			update(y,z-1,n,arr);
		}

	}

}
