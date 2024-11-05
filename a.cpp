//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> computeLPS(string &pat)
  {
      int m = pat.size();
      vector<int> LPS(m,0);
      int len=0;
      int i=1;
      while(i<m)
      {
          if(pat[i]==pat[len]) {
              len++;
              LPS[i]=len;
              i++;
          }
          else {
              if(len!=0) len = LPS[len-1];
              else {
                  LPS[i]=0;
                  i++;
              }
          }
      }
      return LPS;
  }
    vector<int> search(string& pat, string& txt) {
        vector<int> ans;
        vector<int> LPS = computeLPS(pat);
        int i=0,j=0;
        int m = pat.size();
        while(i<txt.size()) 
        {
            if(pat[j]==txt[i]) {
                i++;
                j++;
            }
            if(j==m) {
                ans.push_back(i-j+1);// 1 based index;
                j=LPS[j-1];
            }
            else if(pat[j]!=txt[i]){
                if(j!=0) {
                    j=LPS[j-1];
                }
                else i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends