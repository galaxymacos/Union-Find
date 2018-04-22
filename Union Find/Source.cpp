#include <iostream>
#include <cassert>
#include "UnionFindTestHelper.h"
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"

using namespace std;


int main(int argc, char* argv[])
{
	const auto n = 1000000;
	// union_find_test_helper::testUF<uf1::union_find>(n);
	// union_find_test_helper::testUF<uf2::union_find>(n);
	union_find_test_helper::testUF<uf3::union_find>(n);
	union_find_test_helper::testUF<uf4::union_find>(n);
	cin.get();
}
