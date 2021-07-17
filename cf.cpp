#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define md 1000000007
#define int long long
#define pi pair<int,int>
 
 
int getSum(int BITree[], int index)
{
    int ans = 0;
    index += 1;
 
    // Traverse ancestors
    // of BITree[index]
    while (index > 0)
    {
         
        // Update the sum of current
        // element of BIT to ans
        ans -= BITree[index];
 
        // Update index to that
        // of the parent node in
        // getSum() view by
        // subtracting LSB(Least
        // Significant Bit)
        index -= index & (-index);
    }
    return ans;
}
 
// Function to update the Binary Index
// Tree by replacing all ancestores of
// index by their respective sum with val
static void updateBIT(int BITree[], int n,
                      int index, int val)
{
    index = index + 1;
 
    // Traverse all ancestors
    // and sum with 'val'.
    while (index <= n)
    {
         
        // Add 'val' to current
        // node of BIT
        BITree[index] -= val;
 
        // Update index to that
        // of the parent node in
        // updateBit() view by
        // adding LSB(Least
        // Significant Bit)
        index += index & (-index);
    }
}
 
// Function to construct the Binary
// Indexed Tree for the given array
int* constructBITree(int arr[], int n)
{
     
    // Initialize the
    // Binary Indexed Tree
    int* BITree = new int[n + 1];
 
    for(int i = 0; i <= n; i++)
        BITree[i] = 0;
 
    // Store the actual values in
    // BITree[] using update()
    for(int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    return BITree;
}
 
// Function to obtian and return
// the index of lower_bound of k
int getLowerBound(int BITree[], int arr[],
                  int n, int k)
{
    int lb = -1;
    int l = 0, r = n - 1;
 
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (getSum(BITree, mid) >= k)
        {
            r = mid - 1;
            lb = mid;
        }
        else
            l = mid + 1;
    }
    return lb;
}
 
void performQueries(int A[], int n, int q[][3])
{
     
    // Store the Binary Indexed Tree
    int* BITree = constructBITree(A, n);
 
    // Solve each query in Q
    for(int i = 0;
            i < sizeof(q[0]) / sizeof(int);
            i++)
    {
        int id = q[i][0];
 
        if (id == 1)
        {
            int idx = q[i][1];
            int val = q[i][2];
            A[idx] += val;
 
            // Update the values of all
            // ancestors of idx
            updateBIT(BITree, n, idx, val);
        }
        else
        {
            int k = q[i][1];
            int lb = getLowerBound(BITree,
                                   A, n, k);
            cout << lb << endl;
        }
    }
}

vector<int> solve(int n,int a[],int q, vector<vector<int>> query){
    vector<int> ans;
    map<int,int> ind;
    vector<pair<int,int>> b;
    sort(a,a+n);
    for(int i=0;i<n;i++) b.push_back({a[i],i});

    sort(b.begin(),b.end());
    
    for(int i=0;i<b.size();i++){
        ind[b[i].second] = i;
    }

    int temp[n];
    for(int i=0;i<n;i++) temp[i] = b[i].first;

    int* BITree = constructBITree(temp, n);

    for(int i=0;i<q;i++){
        int c=query[i][0];
        int k =query[i][1];

        for(int j=2;j<k+2;j++){
            int idx = ind[query[i][j]] -1;
             int val =temp[idx];
            temp[idx] -=val;
           
            updateBIT(BITree,n,idx,val);
        }
        int lb = getLowerBound(BITree,temp,n,C);
        cout <<lb<<endl;
        for(int j=2;j<k+2;j++){
            int idx = ind[query[i][j]];
             int val =-1*temp[idx];
            temp[idx] -=val;
           
            updateBIT(BITree,n,idx,val);
        }


    }


    return {};

    




}
 
 
int32_t main(){
    IOS

   int N;
   cin>>N;
   int a[N];
   for(int i=0;i<N;i++){
    cin>>a[i];
   }

   int q;
   cin>>q;
   vector<vector<int> query;
   while(q--){
    int c,k;
    cin>>c>>k;
    vector<int> p;
    p.push_back(c);
    p.push_back(k);

    for(int j=0;j<k;j++){
        int b;
        cin>>b;
        p.push_back(p);
    }
    query.push_back(p);

   }

   vector<int> ans = solve( n, a[], q,  query);







 
 
   
 
 
 
 
 
 
 
 
 return 0;
 
}