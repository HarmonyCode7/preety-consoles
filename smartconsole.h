#pragma once
#ifndef SMARTCONSOLE_H
#define SMARTCONSOLE_H
#include <string>
#include <vector>
#include <iostream>

class SmartConsole
{
    // the public interface
    public:
        SmartConsole();
        SmartConsole(const std::string & printable);
        SmartConsole(const SmartConsole & smc);
        SmartConsole & operator=(SmartConsole & smc);
        int GetLineLength()const;
        void AddToLine(const std::string & printable);
        std::vector<std::string> GetPrintables()const;
        SmartConsole & operator<<(const SmartConsole & smc);
        std::string& operator[](int index);
        //std::string& operator[](std::string identifier);
    private:
    //private helper methods
    void UpdateLineLength();
    void CopyToPrintables(const SmartConsole & sml);
    //properties
    int _lineLength;
    std::vector<std::string> _printables;

};

//other necessary functions
SmartConsole & operator<<(SmartConsole& lhs, const std::string & rhs );
std::string & operator<<(std::string & s, const char * c_string);
std::ostream& operator<<(std::ostream & lhs, SmartConsole & rhs);
SmartConsole & operator<<(std::string & lhs, SmartConsole & rhs);
#endif // SMARTCONSOLE_H
