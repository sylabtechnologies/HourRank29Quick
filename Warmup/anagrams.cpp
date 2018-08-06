typedef unordered_multimap<int, string> U_map;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

int simple_hash(const string &s)
{
	int result = 0;

	for (_R2(s))
	{
		result += (*iter - 'a' + 1);
	}

	return result % 1000;
}

int sherlockAndAnagrams(string s)
{
	U_map dict;
	int result = 0;

	// prep dictionary
	for (_R2(s))
	{
		string temp;

		for (auto iter1 = iter; iter1 != s.end(); ++iter1)
		{
			temp.push_back(*iter1);
			int mycode = simple_hash(temp);
			dict.emplace(mycode, temp);
		}
	}

	for (int i = 0; i < 12; i++)
	{
		auto its = dict.equal_range(i);
		for (auto it = its.first; it != its.second; ++it) {
			cout << it->first << '\t' << it->second << endl;
		}
	}

	// search in reverse
	for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
	{
		string temp;

		for (auto iter1 = iter; iter1 != s.rend(); ++iter1)
		{
			temp.push_back(*iter1);
			int mycode = simple_hash(temp);

			auto myrange = dict.equal_range(mycode);

			for (auto it = myrange.first; it != myrange.second; ++it)
			{
				if (it->second == temp)
					result++;
			}

		}
	}

	return result;
}
