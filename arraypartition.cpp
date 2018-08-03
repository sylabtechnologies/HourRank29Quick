// OK to use map<Ivec, int> and just make out permutations?

#define MY_MAX_NUM  1000001
typedef vector<int> Ivec;

int solve(Ivec a)
{
	// get primes
	Ivec primes = get_primes(MY_MAX_NUM);

	// get divisors
	vector<Ivec> divisors;
	for (size_t i = 0; i < a.size(); i++)
	{
		Ivec mydivisors = get_divisors(a[i], primes);
		divisors.push_back(mydivisors);
	}

	// count unique divisors
	for (size_t i = 0; i < divisors.size(); i++)
	{

	}

	// compute the answer per permutation formulas
	return ();
}
