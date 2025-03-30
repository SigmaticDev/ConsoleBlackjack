#include "StyledChar.h"

#include <Windows.h>

using namespace CBJDisplay;

CBJDisplay::StyledChar::StyledChar(char c)
    : m_char(c)
    , m_foregroundColor("WHITE", true)
    , m_backgroundColor("BLACK", false)
{}

CBJDisplay::StyledChar::StyledChar(
    char c, 
    ConsoleColor foregroundColor, 
    ConsoleColor backgroundColor)
    : m_char(c)
    , m_foregroundColor(foregroundColor)
    , m_backgroundColor(backgroundColor)
{}

std::ostream& CBJDisplay::operator<<(
    std::ostream& os, 
    const StyledChar& sc)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    auto oldForegroundColor = ConsoleColor(
        consoleInfo.wAttributes & FOREGROUND_RED,
        consoleInfo.wAttributes & FOREGROUND_GREEN,
        consoleInfo.wAttributes & FOREGROUND_BLUE,
        consoleInfo.wAttributes & FOREGROUND_INTENSITY
    );

    auto oldBackgroundColor = ConsoleColor(
        consoleInfo.wAttributes & BACKGROUND_RED,
        consoleInfo.wAttributes & BACKGROUND_GREEN,
        consoleInfo.wAttributes & BACKGROUND_BLUE,
        consoleInfo.wAttributes & BACKGROUND_INTENSITY
    );
    
    SetConsoleTextAttribute(
        hConsole,
        toWindowsTextAttribute(
            sc.backgroundColor(),
            sc.foregroundColor()
        )
    );

    os << sc.character();

    SetConsoleTextAttribute(
        hConsole,
        toWindowsTextAttribute(
            oldBackgroundColor,
            oldForegroundColor
        )
    );

    return os;
}
