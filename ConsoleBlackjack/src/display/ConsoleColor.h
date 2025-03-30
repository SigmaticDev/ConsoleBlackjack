#pragma once

#include <string>

namespace CBJDisplay {

    enum class ValidColor {
        BLACK,
        WHITE,
        RED,
        YELLOW,
        GREEN,
        CYAN,
        BLUE,
        PURPLE
    };

    class ConsoleColor
    {
    public:
        ConsoleColor(
            bool isRed,
            bool isGreen,
            bool isBlue,
            bool isIntense
        );
        ConsoleColor(
            ValidColor color,
            bool isIntense
        );
        ConsoleColor(
            std::string colorName,
            bool isIntense
        );

        std::string colorByName() const;
        ValidColor colorByEnum() const;

        bool isRed() const { return m_red; }
        bool isGreen() const { return m_green; }
        bool isBlue() const { return m_blue; }
        bool isIntense() const { return m_intense; }

        void setColor(
            bool isRed,
            bool isGreen,
            bool isBlue,
            bool isIntense
        );
        void setColor(
            ValidColor color,
            bool isIntense
        );
        void setColor(
            std::string colorName,
            bool isIntense
        );

        void setRed(bool isRed) { m_red = isRed; }
        void setGreen(bool isGreen) { m_green = isGreen; }
        void setBlue(bool isBlue) { m_blue = isBlue; }
        void setIntense(bool isIntense) { m_intense = isIntense; }

    private:
        static bool colorIsRed(ValidColor color);
        static bool colorIsGreen(ValidColor color);
        static bool colorIsBlue(ValidColor color);
        static std::string colorToString(ValidColor color);
        static ValidColor strToColor(std::string str);

        bool m_red;
        bool m_green;
        bool m_blue;
        bool m_intense;
    };

    unsigned short toWindowsTextAttribute(
        const ConsoleColor& backgroundColor,
        const ConsoleColor& foregroundColor
    );
}