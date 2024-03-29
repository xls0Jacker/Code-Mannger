#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
 
typedef long long LL;
 
// return (a * b) % m
LL mod_mult(LL a, LL b, LL m) //
{
	LL res = 0;
	LL exp = a % m;
	while (b) 
	{
		if (b & 1) 
		{
			res += exp;
			if (res > m) res -= m;
		}
		exp <<= 1;
		if (exp > m) exp -= m;
		b >>= 1;
	}
	return res;
}
 
// return (a ^ b) % m
LL mod_exp(LL a, LL b, LL m) {//快速幂
	LL res = 1;
	LL exp = a % m;
	while (b) 
	{
		if (b & 1) res = mod_mult(res, exp, m);
		exp = mod_mult(exp, exp, m);
		b >>= 1;
	}
	return res;
}
 
// 
//************************************
// Method:    miller_rabin
// FullName:  miller_rabin
// Access:    public 
// Returns:   bool 是否是素数
// Qualifier: Rabin-Miller强伪素数测试
// Parameter: LL n 待检测的数
// Parameter: LL times 
//************************************
bool miller_rabin(LL n, LL times) //大数素性测试
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (!(n & 1)) return false;
 
	LL q = n - 1;
	int k = 0;
	while (q % 2 == 0) {
		k++;
		q >>= 1;
	}
	// n - 1 = 2^k * q (q是奇素数)
	// n是素数的话，一定满足下面条件
	// (i) a^q ≡ 1 (mod n)
	// (ii) a^q, a^2q,..., a^(k-1)q 中的某一个对n求模为-1
	//
	// 所以、当不满足(i)(ii)中的任何一个的时候，就有3/4的概率是合成数
	//
	for (int i = 0; i < times; ++i) 
	{
		LL a = rand() % (n - 1) + 1; // 从1,..,n-1随机挑一个数
		LL x = mod_exp(a, q, n);
		// 检查条件(i)
		if (x == 1) continue;
		// 检查条件(ii)
		bool found = false;
		for (int j = 0; j < k; j++) 
		{
			if (x == n - 1) 
			{
				found = true;
				break;
			}
			x = mod_mult(x, x, n);
		}
		if (found) continue;
 
		return false;
	}
	return true;
}
 
LL get_gcd(LL n, LL m) 
{
	if (n < m) swap(n, m);
	while (m) 
	{
		swap(n, m);
		m %= n;
	}
	return n;
}
 
 
//************************************
// Method:    pollard_rho
// FullName:  pollard_rho
// Access:    public 
// Returns:   LL
// Qualifier: Pollard 因数分解算法
// Parameter: LL n
// Parameter: int c
//************************************
LL pollard_rho(LL n, int c) 
{
	LL x = 2;
	LL y = 2;
	LL d = 1;
	while (d == 1) 
	{
		x = mod_mult(x, x, n) + c;
		y = mod_mult(y, y, n) + c;
		y = mod_mult(y, y, n) + c;
		d = get_gcd((x - y >= 0 ? x - y : y - x), n);
	}
	if (d == n) return pollard_rho(n, c + 1);
	return d;
}
 
#define MAX_PRIME 200000
vector<int> primes;
vector<bool> is_prime;
 
// 先生成MAX_PRIME内的素数表
void init_primes() //埃氏筛生成素数表
{
	is_prime = vector<bool>(MAX_PRIME + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i) 
	{
		if (is_prime[i]) 
		{
			primes.push_back(i);
			for (int j = i * 2; j <= MAX_PRIME; j += i) 
			{
				is_prime[j] = false;
			}
		}
	}
}
 
// 判断是否是素数，优先查表，如果n很大用Rabin-Miller强伪素数测试
bool isPrime(LL n) 
{
	if (n <= MAX_PRIME) return is_prime[n];
	else return miller_rabin(n, 20);
}
 
// 分解成素因子，小数用素数表，大数用Pollard 因数分解算法
void factorize(LL n, map<LL, int>& factors) 
{
	if (isPrime(n)) //素数表
	{
		factors[n]++;
	}
	else 
	{
		for (int i = 0; i < primes.size(); ++i) //Pollard_rho因数分解算法 
		{
			int p = primes[i];
			while (n % p == 0) 
			{
				factors[p]++;
				n /= p;
			}
		}
		if (n != 1) 
		{
			if (isPrime(n)) 
			{
				factors[n]++;
			}
			else 
			{
				LL d = pollard_rho(n, 1);
				factorize(d, factors);
				factorize(n / d, factors);
			}
		}
	}
}
 
pair<LL, LL> solve(LL a, LL b) 
{
	LL c = b / a;
	map<LL, int> factors;
	factorize(c, factors);
 
	vector<LL> mult_factors;	// 每个质因子的n次方，比如2^2和5^1
	for (map<LL, int>::iterator it = factors.begin(); it != factors.end(); it++) 
	{
		LL mul = 1;
		while (it->second) 
		{
			mul *= it->first;
			it->second--;
		}
		mult_factors.push_back(mul);
	}
 
	LL best_sum = 1e18, best_x = 1, best_y = c;
	// 这是一个取数的过程，一共 2^size 种情况
	for (int mask = 0; mask < (1 << mult_factors.size()); ++mask)
	{
		LL x = 1;
		for (int i = 0; i < mult_factors.size(); ++i)
		{
			if (mask & (1 << i)) x *= mult_factors[i];
		}
		LL y = c / x;
		if (x < y && x + y < best_sum) 
		{
			best_sum = x + y;
			best_x = x;
			best_y = y;
		}
	}
	return make_pair(best_x * a, best_y * a);
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	init_primes();
	LL a, b;
	while (cin >> a >> b) 
	{
		pair<LL, LL> ans = solve(a, b);
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
///////////////////////////End Sub//////////////////////////////////