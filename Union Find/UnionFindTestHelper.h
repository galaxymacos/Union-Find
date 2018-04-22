#pragma once
#include <iostream>
#include <ctime>
using namespace std;

namespace union_find_test_helper
{
	template<class T>
	void testUF(int n)
	{
		srand(time(nullptr));
		const time_t start_time = clock();
		T union_method = T(n);


		for (int i = 0; i<n; i++)
		{
			int p = rand() % n;
			int q = rand() % n;
			union_method.union_elements(p, q);
		}

		for (int i = 0; i<n; i++)
		{
			int p = rand() % n;
			int q = rand() % n;
			bool b = union_method.is_connected(p, q);
		}

		const time_t end_time = clock();
		cout << "Method 3 uses " << double(end_time - start_time) / CLOCKS_PER_SEC <<" s "<< endl;
	}
}


