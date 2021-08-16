#include <iostream>
#include <vector>
using std::vector;

vector<int> minSort(vector<int> v);
vector<int> insSort(vector<int> v);
vector<int> selSort(vector<int> v);

int main()
{
	vector<int> v = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 4};
	vector<int> sorted = minSort(v);

	return 0;
}

vector<int> insSort(vector<int> v)
{
	// change init i to 0? is it safe?
	for (int i = 0; i != v.size(); i++)
	{
		int j = i;
		while (j && v[j] < v[j - 1])
		{
			v[j] ^= v[j - 1] ^= v[j] ^= v[j - 1];
			j--;
		}
	}

	return v;
}

vector<int> selSort(vector<int> v)
{
	for (int i = 0; i != v.size() - 1; i++)
	{
		for (int j = i + 1; j != v.size(); j++)
		{
			if (v[i] > v[j])
			{
				v[i] ^= v[j] ^= v[i] ^= v[j];
			}
		}
	}

	return v;
}

vector<int> minSort(vector<int> v)
{
	for (auto it = v.begin(); it != v.end() - 1; it++)
	{
		auto min = it;
		for (auto i = it + 1; i != v.end(); i++)
		{
			if (*i < *it)
			{
				min = i;
			}
		}
		/* xor swap method must be used when there's two variables (can
		have the same values). But one variable cannot xor itself, which
		will always lead to zero. */
		if (min != it) { *min ^= *it ^= *min ^= *it; }
	}
	return v;
}