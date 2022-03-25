#include<bits/stdc++.h>

using namespace std;

const int inf = 99999999;

void merge(vector<int>& a, int l, int mid, int r)
{
    // initialize first and second with sorted partitions
    vector<int> first(a.begin() + l, a.begin() + mid + 1);
    vector<int> second(a.begin() + mid + 1, a.begin() + r + 1);

    first.push_back(inf);
    second.push_back(inf);

    int pos_l = 0, pos_r = 0;

    for(int i = l; i <= r; i++)
    {
        if(first[pos_l] < second[pos_r])
        {
            a[i] = first[pos_l];
            pos_l++;
        }
        else
        {
            a[i] = second[pos_r];
            pos_r++;
        }
    }
}

void merge_sort(vector<int>& a, int l, int r)
{
    if(l == r)
        return;
    
    int mid = (l + r) / 2;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    merge(a, l, mid, r);

}

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x: a)
        cin >> x;
    
    merge_sort(a, 0, n - 1);

    for(auto x: a)
        cout << x << ' ';

    cout << '\n';

    return 0;
}
