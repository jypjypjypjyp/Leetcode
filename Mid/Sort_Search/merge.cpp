#include "main.h"
#include <set>

int insert(vector<Interval>& v, Interval k)
{
	int index = 0;
	while (index < (int)(v.size()))
	{
		if (k.start < v[index].start)
			break;
		index++;
	}
	v.insert(v.begin() + index, k);
	return index;
}

bool mergeTwoIntervals(vector<Interval>& intervals, int i)
{
	if (i == -1 || i == intervals.size() - 1) return false;
	if (intervals[i].end >= intervals[i + 1].start)
	{
		intervals[i].end = intervals[i].end > intervals[i + 1].end ? intervals[i].end : intervals[i + 1].end;
		intervals.erase(intervals.begin() + i + 1);
		return true;
	}
	return false;
}

vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	if (intervals.empty()) return result;
	for (auto i : intervals)
	{
		int index = insert(result, i);
		bool isMerge = mergeTwoIntervals(result, index - 1);
		if (isMerge) index--;
		do
		{
			isMerge = mergeTwoIntervals(result, index);
		} while (isMerge);
	}
	return result;
}