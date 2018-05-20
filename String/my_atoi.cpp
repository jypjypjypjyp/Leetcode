#include"main.h"

int MyAtoi(string str) {
	string s = "";
	bool is_sign = false;
	bool hasStarted = false;
	for (char c : str) {
		if (!hasStarted && !isspace(c)) hasStarted = true;
		if (hasStarted) {
			if (!is_sign) {
				if(c == '+' || c == '-' || isdigit(c))
					is_sign = true;
				else break;
			}
			else if (!isdigit(c)) break;
			s += c;
		}
	}
	int sign, n;
	if (isdigit(s[0])) { n = s.size(); sign = 1; }
	else if (s[0] == '-') { n = s.size() - 1; sign = -1; }
	else { n = s.size() - 1; sign = 1; }
	if (n > 10) return sign == -1 ? INT_MIN : INT_MAX;
	int64_t result = 0;
	for (int i = s.size() - n; i < s.size(); i++) {
		result += (int)(s[i] - '0')*pow(10, n - 1);
		n--;
	}
	result *= sign;
	if (result > INT_MAX) return INT_MAX;
	else if (result < INT_MIN) return INT_MIN;
	else return result;
}

/*
char space=' ';
char plus='+';
char minus='-';
bool started=false;
bool isPositive=true;
long res=0;
for(int i=0;i<str.size();i++){
if(str.at(i)==space){
if(started)
break;
else
continue;
}

if(str.at(i)==minus){
if(!started){
started=true;
isPositive=false;
continue;
}else{
res=0;
break;
}
}
if(str.at(i)==plus){
if(!started){
started=true;
isPositive=true;
continue;
}else{
res=0;
break;
}
}
if(str.at(i) > '9' || str.at(i) < '0' ){
if(!started){
res=0;
break;
}else{
break;
}
}else{
if(!started)
started=true;
res=res*10+(str.at(i)-'0');
if(isPositive){
if(res>INT_MAX)
return INT_MAX;
}else{
if(-res<INT_MIN)
return INT_MIN;
}
}
}
return isPositive?res:-res;
*/