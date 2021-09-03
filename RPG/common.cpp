#include "common.h"



//Function to split a string into a vector.
std::vector<std::string> split(const std::string& s, char seperator)
{
	std::vector<std::string> output;
	std::string::size_type prev_pos = 0, pos = 0;

	while ((pos = s.find(seperator, pos)) != std::string::npos)
	{
		std::string substring(s.substr(prev_pos, pos - prev_pos));
		output.push_back(substring);
		prev_pos = ++pos;
	}

	output.push_back(s.substr(prev_pos, pos - prev_pos));
	return output;
}

int getIntFromString(std::string s)
{
	std::stringstream ss;
	int sInt;
	ss << s;
	ss >> sInt;

	return sInt;
}
