typedef vector<string> S_vec;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

void checkMagazine(S_vec magazine, S_vec note) {
	map<string, int> dict;
	bool result = true;

	for (_R2(magazine)) dict[*iter]++;

	for (_R2(note))
	{
		if (dict.find(*iter) == dict.end())
		{
			result = false;
			break;
		}
		else
		{
			if (dict[*iter] <= 0)
			{
				result = false;
				break;

			}

			dict[*iter]--;
		}
	}

	cout << ((result) ? "Yes" : "No") << endl;

}
