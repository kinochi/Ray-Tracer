#ifndef HITABLELISTH
#define HITABLELISTH

#include <vector>
#include <memory>
#include "hitable.hpp"

class hitable_list: public hitable {
	public :
		std::vector<std::unique_ptr<hitable>> list;
		int list_size=0;
		hitable_list(){};
		hitable_list(std::vector<std::unique_ptr<hitable>> l) : list(std::move(l)),list_size(l.size()) {}
		bool hit( const ray &r, float t_min, float t_max, hit_record &rec ) const override;
		void add(std::unique_ptr<hitable> p){ list.push_back(std::move(p)); list_size++;}
};

#endif
