#pragma once

#include "StyledChar.h"

#include <string>
#include <vector>

namespace CBJDisplay {

    class CharMap {
    public:
        CharMap();
        CharMap(
            int width,
            int height,
            StyledChar fillChar = StyledChar(' ')
        );
        CharMap(
            int width,
            int height,
            ConsoleColor defaultForegroundColor,
            ConsoleColor defaultBackgroundColor,
            StyledChar fillChar = StyledChar(' ')
        );
        CharMap(
            std::vector<std::vector<StyledChar>> charMap,
            ConsoleColor defaultForegroundColor,
            ConsoleColor defaultBackgroundColor,
            StyledChar fillChar = StyledChar(' ')
        );
        CharMap(
            std::vector<std::string> charRows,
            ConsoleColor defaultForegroundColor,
            ConsoleColor defaultBackgroundColor,
            StyledChar fillChar = StyledChar(' ')
        );

        int width() const { return m_width; }
        int height() const { return m_height; }
        ConsoleColor defaultForegroundColor() const { 
            return m_defaultForegroundColor; 
        }
        ConsoleColor defaultBackgroundColor() const {
            return m_defaultBackgroundColor;
        }
        unsigned int defaultTextAttribute() const {
            return toWindowsTextAttribute(
                m_defaultBackgroundColor,
                m_defaultForegroundColor
            );
        }
        std::vector<std::vector<StyledChar>> rawChars() const {
            return m_charMap;
        }
        StyledChar at(int x, int y) const;

        void setWidth(int width);
        void setHeight(int height);
        void setDefaultForegroundColor(ConsoleColor color);
        void setDefaultBackgroundColor(ConsoleColor color);
        void setAt(int x, int y, StyledChar sc, bool expand = false);

    private:
        int m_width;
        int m_height;
        ConsoleColor m_defaultForegroundColor;
        ConsoleColor m_defaultBackgroundColor;
        std::vector<std::vector<StyledChar>> m_charMap;
    };

}