#include"Properties.hpp"
#include<iostream>
#include<map>

using std::cout;
using std::map;
using vutils::Properties;
using std::endl;

int main() {
	std::string x("ola");
	Properties p(x);
	Properties p2("ola");
	std::string z("aki");
	cout<<p.getProperty("ola")<<endl;
}
