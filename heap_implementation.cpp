#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define deb(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9 + 7)
#define nax int(1e5 + 5)

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}

//*************************** Template Ends *******************************//

// heap indexing from 1...n
// vector<int> a(n + 1)
void max_heapify (vector<int>& a, int i, int n)
{
    int left = 2 * i, right = 2 * i + 1, largest = i;

    if(left<= n && a[left] > a[i] )
		largest = left;
    if(right <= n && a[right] > a[largest] )
        largest = right;
    if(largest != i )
    {
        swap(a[i], a[largest]);
        max_heapify (a, largest, n);
    } 
}
void build_maxheap (vector<int>& a, int n)
{
	for(int i = n / 2; i >= 1; i--)
		max_heapify(a, i, n);
}

int extract_max(vector<int>& a, int& n){
	int max_element = a[1];
	a[1] = a[n];
	n--;
	max_heapify(a, 1, n);
	return max_element;
}
void insert_value(vector<int>& a, int value, int& n){
	n++;
	if((int)a.size() > n)
		a[n] = value;
	else a.push_back(value);

	int pos = n;
	while(pos > 1 && a[pos / 2] < a[pos])
		swap(a[pos / 2], a[pos]), pos /= 2;
}


int main() {
	boost
	int t;
	cin >> t;
	while(t--)
	{	
		
	}


	return 0;
}


