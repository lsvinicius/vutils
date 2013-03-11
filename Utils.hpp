#ifndef __VUTILS__UTILS_H__
#define __VUTILS__UTILS_H__

#include<iostream>
#include"namespace.hpp"

namespace vutils {

	namespace utils {
		class Utils {
			public:
				static unsigned long long calculateHash(const std::string &toBeHashed);
				static unsigned long long calculateHash(const char * toBeHashed);
		};

	};
	
};

#endif
