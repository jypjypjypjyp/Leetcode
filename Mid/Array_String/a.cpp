#include"main.h"
#include<string>

string preProcess(const string &s);
class Solution {
public:
	string longestPalindrome(string s) {
		const int len = s.size();
		if (len <= 1)return s;
		//Manncher�㷨 ��o��n��
		string str = preProcess(s);
		int n = str.size(), id = 0, mx = 0;
		vector<int>p(n, 0);
		for (int i = 1; i < n - 1; i++)
		{
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			//if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //��������б�岿�ֵ�ע�ͣ������Ҫ�ɲ�Ҫ
			while (str[i + p[i]] == str[i - p[i]])p[i]++;
			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
		}

		//����p��Ѱ�������ĳ���
		int maxLen = 0, index = 0;
		for (int i = 1; i < n - 1; i++)
			if (p[i] > maxLen)
			{
				maxLen = p[i];
				index = i;
			}
		return s.substr((index - maxLen) / 2, maxLen - 1);
	}
	//Ԥ�����ַ�����abcԤ�������$#a#b#c#^
	string preProcess(const string &s)
	{
		int n = s.size();
		string res;
		res.push_back('$');//��$�ŵ��ַ���ͷ��
		res.push_back('#');//��#��Ϊԭ���ַ�����ÿ���ַ��ļ��
		for (int i = 0; i < n; i++)
		{
			res.push_back(s[i]);
			res.push_back('#');
		}
		res.push_back('^');//��^��Ϊ�ַ����Ľ�β
		return res;
	}
};