#include "main.h"
#include <unordered_map>

int getTotalBits(int num)
{
	if (num == 0) return 0;
	return log(num) / log(10);
}

int intMerge(int num1, int num2, int bits)
{
	return num1 * pow(10, bits + 1) + num2;
}

int subint(int num, int start, int end)
{
	if (start < 0) return 0;
	num %= (int)(pow(10, start + 1));
	num /= (double)(pow(10, end));
	return num;
}

string fractionToDecimalWithoutSign(int numerator, int denominator)
{
	string result = "";
	unordered_map<int, int> map;
	int numBits = getTotalBits(numerator), denBits = getTotalBits(denominator);
	bool hasPoint = false;
	int a = 0, mod = 0, c = 0, start = numBits, indexPoint = 0;
	while (true)
	{
		int end = start - denBits + getTotalBits(mod)+1;
		if (end > start) end = start;
		a = intMerge(mod, subint(numerator, start, end), start - end);
		while (a < denominator)
		{
			end--;
			a = intMerge(mod, subint(numerator, start, end), start - end);
		}
		c = a / denominator;
		mod = a % denominator;
		if (hasPoint)
		{
			result += string(start - end, '0');
			if (map.find(a) != map.end())
			{
				int recycleStart = map[a];
				string recycle = result.substr(recycleStart, result.size() - recycleStart);
				result.erase(result.begin() + recycleStart, result.end());
				result += '(' + recycle + ')';
				break;
			}
			else
			{
				map[a] = result.size();
			}
		}
		else if (end < 0)
		{
			hasPoint = true;
			if (result == "")
				result += "0." + string(-end - 1, '0');
			else
				result += string(start + 1, '0') + '.' + string(-end - 1, '0');
			map[a] = result.size();
		}
		else if (result != "")
		{
			result += string(start - end, '0');
		}
		result += (char)('0' + c);
		if (mod == 0) break;
		start = end - 1;
	}
	return result;
}

string fractionToDecimal(int numerator, int denominator)
{
	//get denominator's bits & numerator's bits
	if (denominator == 0) return "";
	if (numerator == 0) return "0";
	if (numerator < 0 ^ denominator < 0) 
		return '-' + fractionToDecimalWithoutSign(abs(numerator), abs(denominator));
	else
		return fractionToDecimalWithoutSign(abs(numerator), abs(denominator));
}