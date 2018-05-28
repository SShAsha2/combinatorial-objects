//Author: Matvei Zhukov (matzhukov2000@gmail.com)
#include <algorithm>
#include <cassert>
#include "sum_representation.h"

string SumRepresentation::name()
{
	return "SumRepresentation";
}

bool is_valid(vector <int> const & v)
{
	auto n = (int)(v.size());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 & v[i] > v[i - 1])
		{
			return false;
		}
		sum = sum + v[i];
	}
	if (sum != n)
	{
		return false;
	}
	return true;
}

int64_t SumRepresentation::total(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n = 0)
	{
		return 1;
	}
	int res = 0;
	for (int q = 1; (3 * q*q - q) / 2 <= n; q++)
	{
		res = res + ((-1) ^ q)*(total(n - (3 * q*q - q) / 2) + total(n - (3 * q*q + q) / 2));
	}
	return res;
}

vector <int> nextel(vector <int> const & v)
{
	auto n = (int)(v.size());
	bool unfixed = true;
	vector <int> ans = v;
	for (int i = 0; i < n; i++)
	{
		if (ans[i] > ans[i + 1] & !unfixed)
		{
			ans[i + 1]++;
		}
		if (ans[i] > 1 & ans[i] > ans[i + 1] & unfixed)
		{
			ans[i] = ans[i] - 1;
			unfixed = false;
		}
	}
}
vector <vector <int> > SumRepresentation::generate_all(int n)
{   
	vector < vector <int> > all;
	vector <int> cur;
	cur[0] = n;
	for (int i = 1; i < n; i++)
	{
		cur.push_back(0);
	}
	vector <int> end;
	for (int i = 0; i < n; i++)
	{
		cur.push_back(1);
	}
	while (cur != end)
	{
		all.push_back(cur);
		cur = nextel(cur);
	}
	return all;
}

bool SumRepresentation::is_valid(vector <int> const & v)
{
	return ::is_valid(v);
}

int64_t SumRepresentation::number_by_object(vector <int> const & v)
{
	auto n = (int)(v.size());
	auto all = generate_all(n);
	return (int64_t)(std::find(begin(all), end(all), v) - begin(all));
}

vector <int> SumRepresentation::object_by_number(int n, int64_t k)
{
	auto all = generate_all(n);
	return all[k];
}

bool SumRepresentation::prev(vector <int> & v)
{
	auto n = (int)(v.size());
	auto k = number_by_object(v);
	if (k == 0)
	{
		return false;
	}
	v = object_by_number(n, k - 1);
	return true;
}

bool SumRepresentation::next(vector <int> & v)
{
	auto n = (int)(v.size());
	auto k = number_by_object(v);
	if (k + 1 == total(n))
	{
		return false;
	}
	v = object_by_number(n, k + 1);
	return true;
}

SumRepresentation::~SumRepresentation()
{
}
