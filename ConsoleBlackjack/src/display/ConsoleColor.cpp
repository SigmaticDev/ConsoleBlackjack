#include "ConsoleColor.h"

#include <Windows.h>

using namespace CBJDisplay;

CBJDisplay::ConsoleColor::ConsoleColor(
    bool isRed,
    bool isGreen,
    bool isBlue,
    bool isIntense)
    : m_red(isRed)
    , m_green(isGreen)
    , m_blue(isBlue)
    , m_intense(isIntense)
{}

CBJDisplay::ConsoleColor::ConsoleColor(
    ValidColor color, 
    bool isIntense)
    : m_red(colorIsRed(color))
    , m_green(colorIsGreen(color))
    , m_blue(colorIsBlue(color))
    , m_intense(isIntense)
{}

CBJDisplay::ConsoleColor::ConsoleColor(
    std::string colorName, 
    bool isIntense)
    : m_red(colorIsRed(strToColor(colorName)))
    , m_green(colorIsGreen(strToColor(colorName)))
    , m_blue(colorIsBlue(strToColor(colorName)))
    , m_intense(isIntense)
{}

std::string CBJDisplay::ConsoleColor::colorByName() const
{
    return colorToString(colorByEnum());
}

ValidColor CBJDisplay::ConsoleColor::colorByEnum() const
{
    ValidColor color;

    int colorCode = (m_red << 2) | (m_green << 1) | m_blue;

    switch (colorCode)
    {
    case 0b000:
        color = ValidColor::BLACK;
        break;
    case 0b001:
        color = ValidColor::BLUE;
        break;
    case 0b010:
        color = ValidColor::GREEN;
        break;
    case 0b011:
        color = ValidColor::CYAN;
        break;
    case 0b100:
        color = ValidColor::RED;
        break;
    case 0b101:
        color = ValidColor::PURPLE;
        break;
    case 0b110:
        color = ValidColor::YELLOW;
        break;
    case 0b111:
        color = ValidColor::WHITE;
        break;
    default:
        color = ValidColor::BLACK;
        break;
    }

    return color;
}

void CBJDisplay::ConsoleColor::setColor(
    bool isRed, 
    bool isGreen, 
    bool isBlue, 
    bool isIntense)
{
    m_red = isRed;
    m_green = isGreen;
    m_blue = isBlue;
    m_intense = isIntense;
}

void CBJDisplay::ConsoleColor::setColor(
    ValidColor color, 
    bool isIntense)
{
    m_red = colorIsRed(color);
    m_green = colorIsGreen(color);
    m_blue = colorIsBlue(color);
    m_intense = isIntense;
}

void CBJDisplay::ConsoleColor::setColor(
    std::string colorName, 
    bool isIntense)
{
    m_red = colorIsRed(strToColor(colorName));
    m_green = colorIsGreen(strToColor(colorName));
    m_blue = colorIsBlue(strToColor(colorName));
    m_intense = isIntense;
}

bool CBJDisplay::ConsoleColor::colorIsRed(ValidColor color)
{
	bool result = false;

	switch (color)
	{
	case CBJDisplay::ValidColor::WHITE:
        result = true;
		break;
    case CBJDisplay::ValidColor::RED:
        result = true;
		break;
    case CBJDisplay::ValidColor::YELLOW:
        result = true;
		break;
	case CBJDisplay::ValidColor::PURPLE:
        result = true;
		break;
	default:
		break;
	}

    return result;
}

bool CBJDisplay::ConsoleColor::colorIsGreen(ValidColor color)
{
    bool result = false;
    switch (color)
    {
    case CBJDisplay::ValidColor::WHITE:
        result = true;
        break;
    case CBJDisplay::ValidColor::GREEN:
        result = true;
        break;
    case CBJDisplay::ValidColor::YELLOW:
        result = true;
        break;
    case CBJDisplay::ValidColor::CYAN:
        result = true;
        break;
    default:
        break;
    }
    return result;
}

bool CBJDisplay::ConsoleColor::colorIsBlue(ValidColor color)
{
    bool result = false;
    switch (color)
    {
    case CBJDisplay::ValidColor::WHITE:
        result = true;
        break;
    case CBJDisplay::ValidColor::BLUE:
        result = true;
        break;
    case CBJDisplay::ValidColor::PURPLE:
        result = true;
        break;
    case CBJDisplay::ValidColor::CYAN:
        result = true;
        break;
    default:
        break;
    }
    return result;
}

std::string CBJDisplay::ConsoleColor::colorToString(ValidColor color)
{
    std::string result = "BLACK";
    switch (color)
    {
    case CBJDisplay::ValidColor::WHITE:
        result = "WHITE";
        break;
    case CBJDisplay::ValidColor::RED:
        result = "RED";
        break;
    case CBJDisplay::ValidColor::YELLOW:
        result = "YELLOW";
        break;
    case CBJDisplay::ValidColor::GREEN:
        result = "GREEN";
        break;
    case CBJDisplay::ValidColor::CYAN:
        result = "CYAN";
        break;
    case CBJDisplay::ValidColor::BLUE:
        result = "BLUE";
        break;
    case CBJDisplay::ValidColor::PURPLE:
        result = "PURPLE";
        break;
    default:
        break;
    }
    return result;
}

ValidColor CBJDisplay::ConsoleColor::strToColor(std::string str)
{
    ValidColor result = ValidColor::BLACK;
    if (str == "WHITE")
    {
        result = ValidColor::WHITE;
    }
    else if (str == "RED")
    {
        result = ValidColor::RED;
    }
    else if (str == "YELLOW")
    {
        result = ValidColor::YELLOW;
    }
    else if (str == "GREEN")
    {
        result = ValidColor::GREEN;
    }
    else if (str == "CYAN")
    {
        result = ValidColor::CYAN;
    }
    else if (str == "BLUE")
    {
        result = ValidColor::BLUE;
    }
    else if (str == "PURPLE")
    {
        result = ValidColor::PURPLE;
    }
    return result;
}

unsigned short CBJDisplay::toWindowsTextAttribute(
    const ConsoleColor& backgroundColor, 
    const ConsoleColor& foregroundColor)
{
    unsigned short result = 0;

    result = backgroundColor.isRed() ? BACKGROUND_RED : 0;
    result |= backgroundColor.isGreen() ? BACKGROUND_GREEN : 0;
    result |= backgroundColor.isBlue() ? BACKGROUND_BLUE : 0;
    result |= backgroundColor.isIntense() ? BACKGROUND_INTENSITY : 0;

    result |= foregroundColor.isRed() ? FOREGROUND_RED : 0;
    result |= foregroundColor.isGreen() ? FOREGROUND_GREEN : 0;
    result |= foregroundColor.isBlue() ? FOREGROUND_BLUE : 0;
    result |= foregroundColor.isIntense() ? FOREGROUND_INTENSITY : 0;

    return result;
}
