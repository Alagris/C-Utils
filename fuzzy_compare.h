#ifndef __fuzzy_compare_H_INCLUDED__
#define __fuzzy_compare_H_INCLUDED__
#include <string>	//cout,cin

namespace util_lib{
	unsigned int fuzzyCompare(const std::string & w1, const std::string & w2);
	unsigned int fuzzyCompare2(const std::string & w1, const std::string & w2);
	unsigned int fuzzyCompare3(const std::string & w1, const std::string & w2,long * startIncluding ,long *endIncluding );
}

#endif
