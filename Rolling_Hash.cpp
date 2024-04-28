#define ll long long 
#define pll pair<ll,ll> 

vector<pll> powers;
int mod = 1000000007;
vector<pll> hash_values;
const pll primes = {1000992299, 1000000009};

pll getHash(string &s)
{
  int n = s.size();
  pll h = {0,0};
  for(int i=0;i<n;i++)
  {
    h.first = (h.first*31+(s[i]-'a'+1))%primes.first;
    h.second = (h.second*53+(s[i]-'a'+1))%primes.second;
  }
  return h;
}
void rollinHash(string &s)
{
    int n = s.length();
    hash_values.clear();
    powers.clear();
    vector<pll> hashes(n, {s[0] - 'a'+1, s[0] - 'a'+1});
    vector<pll> power(n, {1, 1});
    for (int i = 1; i < n; i++)
    {
        hashes[i].first = (hashes[i - 1].first * 31 + (s[i] - 96)) % primes.first;
        hashes[i].second = (hashes[i - 1].second * 53 + (s[i] - 96)) % primes.second;
        power[i].first = (power[i - 1].first * 31) % primes.first;
        power[i].second = (power[i - 1].second * 53) % primes.second;
    }
    hash_values = hashes;
    powers = power;
}
pll substringHash(ll int l, ll int r)
{
    ll hash1, hash2;
    hash1 = hash_values[r].first;
    if (l > 0)
        hash1 = ((hash1 - (hash_values[l - 1].first * powers[r - l + 1].first) % primes.first) + primes.first) % primes.first;
    hash2 = hash_values[r].second;
    if (l > 0)
        hash2 = ((hash2 - (hash_values[l - 1].second * powers[r - l + 1].second) % primes.second) + primes.second) % primes.second;
    return {hash1, hash2};
}
