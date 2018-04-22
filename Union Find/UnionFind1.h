#pragma once
#include <cassert>

namespace uf1
{
	class union_find
	{
		int* id_;
		int count_;
	public:
		explicit union_find(const int n) :count_(n)
		{
			id_ = new int[n];
			for (auto i = 0; i<n; i++)
			{
				id_[i] = i;
			}
		}
		~union_find()
		{
			delete[] id_;
		}

		int find(const int p) const
		{
			assert(p >= 0 && p < count_);
			return id_[p];
		}

		bool is_connected(const int p, const int q) const
		{
			return find(p) == find(q);
		}

		void union_elements(const int p, int q) const
		{
			const auto p_id = find(p);
			const auto q_id = find(q);
			if (p_id == q_id)
				return;
			for (auto i = 0; i<count_; i++)
			{
				if (id_[i] == p_id)
					id_[i] = q_id;
			}
		}
	};


}
