
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
#define MOD 1000000007
#define test int t;scanf("%d",&t);while(t--)
#define IMAX std::numeric_limits<int>::max()
#define IMIN std::numeric_limits<int>::min()
#define IMAXLL std::numeric_limits<ll>::max()
#define IMINLL std::numeric_limits<ll>::min()
//#define lim 100000001
#define lolwa 10000000


using namespace std;
int *arr;
int n;

int returnParent(int i){
    return (i & 1)?i/2:(i/2)-1;
}
void heapify(int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;

    if(left < n && arr[left] > arr[i]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(i != largest){
        swap(arr[i],arr[largest]);
        heapify(largest);
    }
}
void buildHeap(){
    for(int i = n/2 -1 ; i >= 0; i--) heapify(i);
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
void printArray(){
    fsentak cout <<arr[i] <<" ";
    nl;
}
int extractMax(){
    if(n==0){
        cout <<"error empty\n";
        return -1;
    }
    else{
        int x = arr[0];
        arr[0] = arr[n-1];
        n--;
        heapify(0);
        return x;
    }
}
void printMax(){
    if(n==0){
        cout <<"empty\n";
        return;
    }
    else{
        cout <<arr[0] <<endl;
    }
}
void increaseValue(int i,int value){
    if(value < arr[i]) return;
    arr[i] = value;

    while(i > 0 && arr[returnParent(i)] < arr[i]){
        swap(arr[i],arr[returnParent(i)]);
        i = returnParent(i);
    }
}

void insert(int value){
    n++;
    arr[n-1] = -1;
    increaseValue(n-1, value);
}
int main(){

    int arr1[100] = {5,3,2,1,6,9};
    arr = arr1;
    n = 6;

    buildHeap();
   //heapSort();
    int x;
    while(1){
        cout <<"1.Extract Max\n2.Print Max\n3.Insert\n";
        cin >>x;
        if(x==1) cout <<"Max = " <<extractMax() <<endl;
        else if (x==2) printMax();
        else{
            int value;
            cin >>value;
            insert(value);
        }
        cout <<"\n\n";
    }

}

/*

 0 1 2 3 4



 */
