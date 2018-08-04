// 13_arraypartition.cpp : https://www.hackerrank.com/contests/hourrank-29/challenges/array-partition
// - debug to completion, if a[i] = 1 intersections++?
// 

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

#define MAX_PRIME	1000
typedef vector<int> Ivec;
typedef set<int>	Iset;
Ivec get_primes(const int);

const Ivec global_primes(get_primes(MAX_PRIME));

Ivec get_divisors(const int number)
{
	Ivec result;

	for (auto iter = global_primes.begin(); iter != global_primes.end(); ++iter)
	{
		if (number < *iter) break;

		if (number % *iter == 0) result.push_back(*iter);
	}

	return result;
}

void add_to_set(Iset& myset, const Ivec& myvec)
{
	for (auto iter = myvec.begin(); iter != myvec.end(); ++iter)
	{
		myset.insert(*iter);
	}
}

bool set_intersects(Iset& myset, const Ivec& myvec)
{
	for (auto iter = myvec.begin(); iter != myvec.end(); ++iter)
	{
		auto iter1 = myset.find(*iter);

		if (iter1 != myset.end()) return true;
	}

	return false;
}

long long factorial(const int num)
{
	long long result = 1;

	for (int i = 1; i <= num; i++)
		result *= i;

	return result;
}

int solve(Ivec a)
{
	if (a.size() == 0) return 0;

	// get divisors
	vector<Ivec> divisors;
	for (size_t i = 0; i < a.size(); i++)
	{
		Ivec mydivisors;
		if (a[i] == 1)
			mydivisors.push_back(1);
		else
			mydivisors = get_divisors(a[i]);

		if (mydivisors.size() > 0)
			divisors.push_back(mydivisors);
	}

	// count non intersecting sets
	Iset all_divisors;
	add_to_set(all_divisors, divisors[0]);

	int intersections = 1;
	for (size_t i = 1; i < divisors.size(); i++)
	{
		if (!set_intersects(all_divisors, divisors[i])) intersections++;
		add_to_set(all_divisors, divisors[i]);
	}

	// compute the answer per permutation formulas
	return factorial(intersections);
}

// make simplest test
Ivec get_primes(const int limit)
{
	Ivec result;

	result.push_back(2);
	result.push_back(3);

	for (int number = 4; number <= limit; number++)
	{
		bool isprime = true;

		if (number <= 1) isprime = false;

		if (number <= 3) isprime = true;

		if (number % 2 == 0 || number % 3 == 0) isprime = false;

		for (int i = 5; i*i <= number; i = i + 6) {
			if (number % i == 0 || number % (i + 2) == 0)
				isprime = false;
		}

		if (isprime) result.push_back(number);
	}

	return result;
}
