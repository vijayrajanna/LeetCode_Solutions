/*
 * [252] Meeting Rooms
 *
 * https://leetcode.com/problems/meeting-rooms/description/
 *
 * algorithms
 * Easy (50.16%)
 * Total Accepted:    64K
 * Total Submissions: 127.7K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
 * meetings.
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,30],[5,10],[15,20]]
 * Output: false
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[7,10],[2,4]]
 * Output: true
 * 
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

bool canAttendMeetings(vector<Interval>& intervals) 
{
	if (intervals.empty()) return true;
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });

	res.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); i++)
	{
		if (res.back().end <= intervals[i].start)
		{
			res.push_back(intervals[i]);
		}
		else
		{
			return false;
		}
	}
	return true;
}
};
