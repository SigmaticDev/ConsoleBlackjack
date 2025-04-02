#pragma once

#include "ConsoleColor.h"

#include <iostream>

namespace CBJDisplay {

    class StyledChar {
    public:
        StyledChar();
        StyledChar(char c);
        StyledChar(
            char c,
            ConsoleColor foregroundColor,
            ConsoleColor backgroundColor
        );

        char character() const { return m_char; }
        ConsoleColor foregroundColor() const { return m_foregroundColor; }
        ConsoleColor backgroundColor() const { return m_backgroundColor; }

        void setCharacter(char c) { m_char = c; }
        void setForegroundColor(ConsoleColor color) { 
            m_foregroundColor = color; 
        }
        void setBackgroundColor(ConsoleColor color) {
            m_backgroundColor = color;
        }

        bool operator==(const StyledChar& other) const;

        friend std::ostream& operator<<(
            std::ostream& os, 
            const StyledChar& sc
        );

    private:
        char m_char;
        ConsoleColor m_foregroundColor;
        ConsoleColor m_backgroundColor;
    };
}