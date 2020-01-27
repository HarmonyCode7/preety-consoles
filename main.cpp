#include <iostream>
#include <vector>
#include <string>
#include "smartconsole.h"
#include "unicode.h"
#include "color.h"

using namespace std;
using namespace COLOR;

std::string operator*(const std::string &s,
		      const int count)
{
  std::string s_copy = s;
  for(int i = 0; i < count; ++i)
    s_copy += s;
  return s_copy;
}

void DisplayMenu()
{
  //SmartConsole smc;
  //	smc << DHL * 50 << NEWLINE << SHADE_SQUARE * 5 << " HELLO WRLD"  << NEWLINE << smc[0];
	//	std::cout << COLOR::CLR_LGREEN <<  smc;
  SmartConsole smc;
       
}

int main()
{
    DisplayMenu();
    return 0;
}

