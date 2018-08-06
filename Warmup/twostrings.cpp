// do easy map
string twoStrings(string s1, string s2)
{
	set<char> dict;
	bool result = false;

	// trie sort of
	for (_R2(s1))
	{
		dict.insert(*iter);
	}

	// test dict
	for (_R2(s2))
	{
		char key = *iter;

		if (dict.find(key) != dict.end())
		{
			result = true;
			break;
		}
	}

	return ((result) ? "YES" : "NO");
}
