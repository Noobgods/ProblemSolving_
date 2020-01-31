#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX_V 123456789.0f


long long rangeSum(const vector<long long> & psum, int a, int b)
{
	if (a == 0) return psum[b];
	return psum[b] - psum[a - 1];
}

long double standardDeviation(const vector<long long> &sqpsum, const vector<long long> &psum, int a, int b)
{
	long double mean = rangeSum(psum, a, b) / static_cast<long double>(b - a + 1);
	long double ret = rangeSum(sqpsum, a, b) - 2 * mean * rangeSum(psum, a, b) + (b - a + 1) * mean * mean;
	long double variance = ret / (b - a + 1);
	return sqrt(variance);
}

int main()
{
	int nrDoll, minSub;
	cin >> nrDoll >> minSub;

	vector<long long> subsumList;
	vector<long long> sqSubsumList;

	int tmp;
	long long sum = 0;
	long long sqSum = 0;
	for (int i = 0; i < nrDoll; i++)
	{
		cin >> tmp;
		sum += tmp;
		sqSum += static_cast<long long>(tmp) * tmp;

		subsumList.push_back(sum); // 각 원소 의 부분합 , 제곱의 부분합을 미리 계산
		sqSubsumList.push_back(sqSum);
	}
	long double min_v = MAX_V;
    // 모든 sub 구간을 탐색하면서 표준편차를 계산한다
	for (int s = 0; s < nrDoll; s++)
	{
		for (int e = s + minSub - 1; e < nrDoll; e++)
		{
            long double V =standardDeviation(sqSubsumList, subsumList, s, e);
			min_v = min(min_v, V);
            cout << V << " ";
		}
        cout<<endl;
	}

	cout.setf(ios::fixed);
	cout.precision(11);
	cout << min_v << endl;
	return 0;
}

