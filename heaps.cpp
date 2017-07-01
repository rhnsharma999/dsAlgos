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

int n;
int *arr;
void heapify(int i){
	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest = i;
	if((left < n) && (arr[left] > arr[i])) largest = left;

	if((right < n) && (arr[right] > arr[largest])) largest = right;

	if(largest != i){
		swap(arr[i],arr[largest]);
		heapify(largest);
	}
}
void buildHeap(){
	for(int i = (n/2)-1; i >= 0; i--){
		heapify(i);
	}
}

void printHeap(){
	fsentak cout <<arr[i] <<" ";
	nl;
}
void heapSort(){
	int x = n;
	f(i,1,x){
		swap(arr[0],arr[n-1]);
		n--;
		heapify(0);
	}
	n = x;
}

int main(){
	n = 7;
	arr = new int[7];
	int some[] = {1,4,2,2,7,5,9};
	arr = some;
	buildHeap();
	heapSort();

	printHeap();

}
