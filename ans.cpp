#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
#define nax int(5e5 + 5)

int query(int a, int b, int c){

	cout << "? " << a << ' ' << b << ' ' << c << endl;
	int val;
	cin >> val;
	return val;
}

int main() {
    boost
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		vector<int> ans(n + 4, -1), tell(n, -1);

		for(int i = 0; i < n / 3; i++)
		{
			int start = 3 * i + 1, val;

			val = query(start, start + 1, start + 2);
			tell[i] = val;

		}

		int onum = -1, znum = -1, status = -1;

		for(int i = 0; i < n / 3; i++)
		{
			if(status == -1)
				status = tell[i];

			else if(status == tell[i])
				continue;
			
			else 
			{	
				int pos = 3 * (i - 1) + 2;
				for(int j = 0; j < 2; j++)
				{
					int curval = query(pos, pos + 1, pos + 2);
					if(status != curval)
					{
						znum = pos - 1;
						onum = pos + 2;
						if(status == 1)
							swap(znum, onum);

						break;
					}
					pos++;
				}
				break;
			}

		}
		



	}



    return 0;
}   