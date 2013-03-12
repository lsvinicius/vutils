#ifndef __VUTILS__PROPERTIES_H__
#define __VUTILS__PROPERTIES_H__

#include<cstring>
#include<fstream>
#include<map>
#include"namespace.hpp"

namespace vutils {
	
	class Properties {
		public:
			Properties(const std::string &fileName);
			Properties(const char * fileName);
			virtual ~Properties();
			const std::string & getProperty(const std::string *key) const;
			const std::string & getProperty(const char * key) const;
		protected:
			virtual void readFile();
			std::ifstream & getRead();
			std::ofstream & getWrite();
		private:
			std::ifstream *read;
			std::ofstream *write;
			const std::string filename;
			std::map<unsigned long long, std::string> *hash;

	};

};

#endif
