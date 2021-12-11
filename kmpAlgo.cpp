#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
#define nax int(5e5 + 5)

/* 
lps always looks like - 0 0 1 1 2 3 0 1 2 3 3 4 
i.e increasing then 0 then increasing (repeat)
 */
void createLps(vector<int>& lps, string s){

    // len tells at which position next match is to be made with current position i.e 'i'
    int n = s.size(), len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < n)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(len != 0)      
        {
            // len != 0 means right now 'len' characters of prefix matched with 
            // suffix before position 'i' (at 'i' (len + 1)th character didn't matched)
            // so we can try reducing size of prefix by 1 and match 'len'th char. with ith char.
            len = lps[len - 1];
        }     
        else 
        {
            lps[i] = 0;
            i++;
        }

    }

}

void kmpSearch(string s, string pat, vector<int>& lps){

    createLps(lps, pat);
    int i = 0, j = 0, M = pat.size();

    while(i < int(s.size()))
    {
        if(s[i] == pat[j])
        {
            i++;
            j++;
            if(j == M)
            {
                cout << "found at pos " << i - M << '\n';
                j = lps[j - 1];         
            }
        }
        else if(j == 0)
            i++;
        else 
            j = lps[j - 1];
    }

}

int main() {
    boost
	
    string s = "AAAAAAAAAAAAAAAAAB", pat = "AAAAB";
    vector<int> lps( int(pat.size()) );

    kmpSearch(s, pat, lps);  

    return 0;
}   