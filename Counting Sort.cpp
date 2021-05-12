#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD ((ll) 1e9 + 7)
#define MOD2 ((ll) 1e9 + 9)
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b)
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

//Type => Stable Sort
//Time => O(n + k)
//Space => O(n + k)
//k = (mx - mn + 1) => number of possible values.

void counting_sort(ll a[], ll n, ll mn, ll mx)
{
	vector<ll> freq(mx - mn + 1);
	loop(i, 0, n - 1) freq[a[i] - mn]++;

	//finding end positions
	loop(i, 1, freq.size() - 1) freq[i] += freq[i - 1];

	vector<ll> ans(n);

	//why ? => to make sort stable
	rloop(i, n - 1, 0)
	{
		ans[freq[a[i] - mn] - 1] = a[i];
		freq[a[i] - mn] -= 1;
	}

	//filling original array
	loop(i, 0, n - 1) a[i] = ans[i];

}

void Solve()
{
	ll n; cin >> n;
	ll a[n]; loop(i, 0, n - 1) cin >> a[i];
	ll mn = a[0], mx = a[0];
	loop(i, 1, n - 1) { mn = min(mn, a[i]); mx = max(mx, a[i]); }

	counting_sort(a, n, mn, mx);

	loop(i, 0, n - 1) cout << a[i] << " ";
}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}