#include <cstdio>
#include <string>
#include <iostream>
int main()
{
	int h = 12;
	int m = 30;
	std::string time[] = {
		"o' clock", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine", "ten",
		"eleven", "tweleve", "thirteen", "fourteen", "quarter",
		"sixteen", "seventeen", "eighteen", "nineteen", "twenty"		
	};
	const int size = 40;
	char buf[size] = {};
	if (0 == m)
		snprintf(buf, size, "%s %s", time[h].c_str(), time[m].c_str());
	else if (1 == m)
		snprintf(buf, size, "%s minute past %s", time[m].c_str(), time[h].c_str());
	else if (m <= 14)
		snprintf(buf, size, "%s minutes past %s", time[m].c_str(), time[h].c_str());
	else if (15 == m)
		snprintf(buf, size, "%s past %s", time[m].c_str(), time[h].c_str());
	else if (m <= 20)
		snprintf(buf, size, "%s minutes past %s", time[m].c_str(), time[h].c_str());
	else if (m <= 29)
		snprintf(buf, size, "%s %s minutes past %s", time[20].c_str(), time[m-20].c_str(), time[h].c_str());
	else if (30 == m)
		snprintf(buf, size, "half past %s", time[h].c_str());
	else if (m <= 39)
		snprintf(buf, size, "%s %s minutes to %s", time[20].c_str(), time[40-m].c_str(), time[h+1].c_str());
	else if (m <= 44)
		snprintf(buf, size, "%s minutes to %s", time[60 - m].c_str(), time[h + 1].c_str());
	else if (45 == m)
		snprintf(buf, size, "quarter to %s", time[h + 1].c_str());
	else if (m <= 59)
		snprintf(buf, size, "%s minutes to %s", time[60-m].c_str(), time[h + 1].c_str());
	std::string answer = buf;
}