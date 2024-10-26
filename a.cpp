#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long calculateWays(long long N, long long K, const string& S, const vector<long long>& A);
bool isValidSubstr(const vector<long long>& charCount, const vector<long long>& A);
void updateCharCount(vector<long long>& charCount, char ch, int delta);

long long calculateWays(long long N, long long K, const string& S, const vector<long long>& A) {
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = 1;

    for (long long i = 1; i <= N; ++i) {
        vector<long long> charCount(26, 0);
        for (long long j = i; j >= 1; --j) {
            updateCharCount(charCount, S[j - 1], 1);
            if (isValidSubstr(charCount, A)) {
                for (long long k = 1; k <= K; ++k) {
                    dp[i][k] = (dp[i][k] + dp[j - 1][k - 1]) % MOD;
                }
            } else {
                break;
            }
        }
    }

    return dp[N][K];
}

bool isValidSubstr(const vector<long long>& charCount, const vector<long long>& A) {
    for (long long k = 0; k < 26; ++k) {
        if (charCount[k] > A[k]) {
            return false;
        }
    }
    return true;
}

void updateCharCount(vector<long long>& charCount, char ch, int delta) {
    charCount[ch - 'a'] += delta;
}

int main() {
    long long N, K;
    cin >> N;
    string S;
    cin >> S;
    vector<long long> A(26);
    for (long long i = 0; i < 26; ++i) {
        cin >> A[i];
    }
    cin >> K;

    long long result = calculateWays(N, K, S, A);
    cout << result << endl;
    return 0;
}