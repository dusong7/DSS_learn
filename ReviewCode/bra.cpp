///##
///## Code for BracketMatch_Begin 12/25/2016_dusong7/////
/*
#include <iostram>
#include <stack>

using namespace std;

bool isLeft(char c)
{
	if(c =="(")
	{
		return true;
	}
	
	if(c == "{")
	{
		return true;
	}
}

bool isMatched(char right, char left)
{
	if(right == "{" && left == "}")
	{
		return true;
	}
	
	if(right == "(" &&left == ")")
	{
		return true;
	}
}

bool BracketMatch(char *str)
{
	char c;
	stack<char> stcChar;
	
	while(*str)
	{
		c = *str;
		if(isLeft(c))
		{
			stcChar.push(c);
		}
		else
		{
			if(stcChar.empty() || !isMatched(c, stcChar.top()))
			{
				return false;
			}
			stcChar.pop();
		}
		str++;
	}
	
	if(!stcChar.empty())
	{
		return false;
	}
	return true;
}

int main()
{
	char str[10000];
	cin>>str;
	cout<<BracketMatch(str);
	
	return 0;
}
*/
// /## Code for BracketMatch_End/////


