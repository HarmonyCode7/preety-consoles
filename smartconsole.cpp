#include "smartconsole.h"
#include <stdexcept>

void SmartConsole::UpdateLineLength()
{
    int len = 0;
    for(std::vector<std::string>::iterator it = _printables.begin(); it != _printables.end(); ++it)
    {
        int itLen = it->length();
        len += itLen;
    }
    _lineLength = len;
}

void SmartConsole::CopyToPrintables(const SmartConsole& smc)
{
      //insert the copy smc's printables to the end of the current object's printables
        //example _printables ={ "hey ther", "fellas"} smc.GetLineLength() = {" hi  there", "gents"} =>
        // RESULT:  _printables = {"hey ther", "fellas"," hi  there", "gents"};
        std::vector<std::string>::iterator rhs_beginning = smc.GetPrintables().begin();
        std::vector<std::string>::iterator rhs_end = smc.GetPrintables().end();
        std::vector<std::string>::iterator currentObjEnd = _printables.end();
        _printables.insert(currentObjEnd, rhs_beginning, rhs_end);
        UpdateLineLength();
}

SmartConsole::SmartConsole():_lineLength(0), _printables(0)
{}

SmartConsole::SmartConsole(const std::string & printable)
{
    _printables.push_back(printable);
    UpdateLineLength();
}

SmartConsole::SmartConsole(const SmartConsole & smc)
{
    _lineLength = smc.GetLineLength();
    CopyToPrintables(smc);
}

SmartConsole & SmartConsole::operator=(SmartConsole & smc)
{
    if(this != &smc)
    {
        _lineLength = smc.GetLineLength();
        _printables = GetPrintables();
        UpdateLineLength();
    }
    return *this;
}

std::vector<std::string> SmartConsole::GetPrintables()const
{
    return _printables;
}
int SmartConsole::GetLineLength()const
{
    return _lineLength;
}
void SmartConsole::AddToLine(const std::string & printable)
{
    _printables.push_back(printable);
    UpdateLineLength();
}
//
SmartConsole & SmartConsole::operator<<(const SmartConsole & smc)
{
    CopyToPrintables(smc);
    return *this;
}
SmartConsole & operator<<(SmartConsole& lhs, const std::string & rhs )
{
    lhs.AddToLine(rhs);
    return lhs;
}

std::string & operator<<(std::string & s, const char * c_string)
{
    //convert a c (i.e 'char * ') string into a std::string
    std::string s_cstring(c_string);
    s+= s_cstring;
    return s;
}

std::ostream & operator<<(std::ostream& lhs, SmartConsole & rhs)
{
    for(auto s:rhs.GetPrintables())
    {
        lhs << s;
    }
    return lhs;
}

std::string& SmartConsole::operator[](int index)
{

    return (index >= 0 && index < _printables.size() )? _printables[index]: 
    throw std::out_of_range(" indexing out of range line component");
}

SmartConsole & operator<<(std::string & lhs, SmartConsole & rhs)
{
    rhs.AddToLine(lhs);
    return rhs;
}
