#include<bits/stdc++.h>

using namespace std;

/* 
25-3-22
https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    bool palin(string s)
{
	int i = 0, n = s.length();
	for(; i < n / 2; i++)
		if(s[i] != s[n - i - 1])
			return false;
	
	return true;
	
}
vector<deque<string>> doit(string s, int pos, vector<vector<deque<string>>>& store)
{
	if(pos == s.length())
	{
		vector<deque<string>> another;
		deque<string> dqs;
        another.push_back(dqs);
        // for(auto st: dqs)
        //     cout << st << '\n';
		return another;
	}
	string cur = "";
	vector<deque<string>> ans;
	for(int i = pos; i < s.length(); i++)
	{
		cur += s[i];
		if(palin(cur))
		{
            vector<deque<string>> got;
			if(!store[i + 1][0].empty() && i + 1 != s.length())
				got = store[i + 1];
			else 
            {
                 got = doit(s, i + 1, store);
                store[i + 1] = got;
            }
     
			for(auto& dq: got)
            {
                dq.push_front(cur);
                // for(auto st: dq)
                //     cout << st << '\n';
            }
				
			ans.insert(ans.end(), got.begin(), got.end());
		}
	}
	return ans;
}

vector<vector<string>> partition(string s) {
	
	vector<vector<deque<string>>> store(s.length() + 4, vector<deque<string>>(1));

	auto ans = doit(s, 0, store);
    // cout << "df";
	vector<vector<string>> res;
	
	for(auto& dq: ans)
	{
		vector<string> fi;
		while(!dq.empty())
		{
			fi.push_back(dq.front());
			dq.pop_front();
		}
		res.push_back(fi);
	}
	return res;

}
};

