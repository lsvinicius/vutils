#include"Properties.hpp"
#include<iostream>
#include"Utils.hpp"
namespace vutils {
	using std::string;
	using std::ofstream;
	using std::ifstream;
	using utils::Utils;


	Properties::Properties(const string &fileName) : filename(fileName) {
		read = NULL;
		write = NULL;
		hash = NULL;
		readFile();
	}

	Properties::Properties(const char * fileName) : filename(fileName) {
		read = NULL;
		write = NULL;
		hash = NULL;
		readFile();
	}

	Properties::~Properties() {
		if(write != NULL) {
			write->close();
			delete write;
			write = NULL;
		}
		if(read != NULL) {
			read->close();
			delete read;
			read = NULL;
		}
		if(hash != NULL) {
			delete hash;
			hash = NULL;
		}
	}

	const string & Properties::getProperty(const string key) const {
		string &val = hash->find(Utils::calculateHash(key))->second;
		return val;
	}

	const string & Properties::getProperty(const char * key) const {
		string val(key);
		return getProperty(val);
	}

	void Properties::readFile() {
		if(read == NULL) {
			read = new ifstream(filename.c_str());
		}
		if(hash == NULL) {
			hash = new std::map<unsigned long long, string>();
		}
		char buffer[500];
		string *tmp;
		int pos;
		char delimiter='=';
		string key;
		string value;
		while(!read->eof()) {
			read->getline(buffer, 500, '\n');
			tmp = new string(buffer);
			if(tmp->size() > 0) {
				pos = tmp->find_first_of(delimiter);
				key = tmp->substr(0,pos);
				value = tmp->substr(pos+1,string::npos); //string::npos is to copy everything beginning from pos+1
				hash->insert(std::pair<int,string>(Utils::calculateHash(key), value));
			}
			delete tmp;
		}
	}

	ifstream & Properties::getRead() {
		return *read;
	}

	ofstream & Properties::getWrite() {
		return *write;
	}

};
