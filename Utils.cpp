#include"Utils.hpp"
#include<iostream>
namespace vutils {

	using std::string;
	namespace utils {
		unsigned long long Utils::calculateHash(const string &toBeHashed) {
			unsigned long long hash = 7;
			int size = toBeHashed.size();
			for(int i = 0; i < size; i++) {
				hash = hash*31 + int(toBeHashed[i]);
			}
			return hash;
		}
		unsigned long long Utils::calculateHash(const char *toBeHashed) {
			string val(toBeHashed);
			return calculateHash(val);
		}

	};

};
