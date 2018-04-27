#pragma once

#include <cassert>

using namespace std;

namespace uf3
{
	class union_find
	{
		int count_;
		int* parent_;
		int* sz_;
	public:
		explicit union_find(const int count) : count_(count)
		{
			parent_ = new int[count];
			sz_ = new int[count];
			for (auto i = 0; i < count; i++)
			{
				parent_[i] = i; // self points to itself
				sz_[i] = 1;
			}
		}

		~union_find()
		{
			delete[] parent_;
			delete[] sz_;
		}

		int find(int p) const
		{
			assert(p >= 0 && p < count_);
			while (p != parent_[p])
				p = parent_[p];
			return p;
		}

		bool is_connected(const int p, const int q) const
		{
			return find(p) == find(q);
		}

		void union_elements(int p, int q) const
		{
			const auto p_root = find(p);
			const auto q_root = find(q);
			if (p_root == q_root)
			{
				return;
			}
			if (sz_[p_root] < sz_[q_root])
			{
				parent_[p_root] = q_root;
				sz_[q_root] += sz_[p_root];
			}
			else
			{
				parent_[q_root] = p_root;
				sz_[p_root] += sz_[q_root];
			}
		}
	};
}
