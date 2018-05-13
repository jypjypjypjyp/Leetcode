#include"main.h"

int* Next( string needle)
{
	int* next = new int[needle.size()];
	if (needle.size() == 0) return next;
	next[0] = -1;
	if (needle.size() < 2)
	{
		return next;
	}
	next[1] = 0;
	int i = 2;
	int j = 0;
	while (i < needle.size())
	{
		if (needle[i - 1] == needle[j])
		{
			next[i++] = ++j;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{

				next[i++] = ++j;
			}
		}
	}
	return next;
}
int StrStr(string haystack, string needle)
{
	int* next = Next(needle);
	int i = 0;
	int j = 0;
	while (j < needle.size() && i < haystack.size())
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	return j < needle.size() ? -1 : i - j;
}