#pragma once 
#ifndef COLOR_H
#define COLOR_H
//Unix colors for the console

/*
    Black        0;30     Dark Gray     1;30
    Red          0;31     Light Red     1;31
    Green        0;32     Light Green   1;32
    Brown/Orange 0;33     Yellow        1;33
    Blue         0;34     Light Blue    1;34
    Purple       0;35     Light Purple  1;35
    Cyan         0;36     Light Cyan    1;36
    Light Gray   0;37     White         1;37
*/

namespace COLOR {
	static std::string CLR_RESET      = "\e[0m";

	static std::string CLR_BLACK      = "\e[0;30m";
	static std::string CLR_RED        = "\e[0;31m";
	static std::string CLR_GREEN      = "\e[0;32m";
	static std::string CLR_ORANGE     = "\e[0;33m";
	static std::string CLR_BLUE       = "\e[0;34m";
	static std::string CLR_PURPLE     = "\e[0;35m";
	static std::string CLR_CYAN       = "\e[0;36m";
	static std::string CLR_LGRAY      = "\e[0;37m";

	static std::string CLR_DGRAY      = "\e[1;30m";
	static std::string CLR_LRED       = "\e[1;31m";
	static std::string CLR_LGREEN     = "\e[1;32m";
	static std::string CLR_YELLOW     = "\e[1;33m";
	static std::string CLR_LBLUE      = "\e[1;34m";
	static std::string CLR_LPURPLE    = "\e[1;35m";
	static std::string CLR_LCYAN      = "\e[1;36m";
	static std::string CLR_WHITE      = "\e[1;37m";
}

//END OF UNIX CMD LINE 
#endif //COLOR_H
