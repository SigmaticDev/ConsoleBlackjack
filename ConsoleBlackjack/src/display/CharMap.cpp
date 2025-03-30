#include "CharMap.h"

#include <algorithm>

using namespace CBJDisplay;

CBJDisplay::CharMap::CharMap()
    : m_width(0)
    , m_height(0)
    , m_defaultForegroundColor("WHITE", true)
    , m_defaultBackgroundColor("BLACK", false)
    , m_charMap()
{}

CBJDisplay::CharMap::CharMap(
    int width,
    int height,
    StyledChar fillChar
)
    : m_width(width)
    , m_height(height)
    , m_defaultForegroundColor("WHITE", true)
    , m_defaultBackgroundColor("BLACK", false)
    , m_charMap(height, std::vector<StyledChar>(width, fillChar))
{}

CBJDisplay::CharMap::CharMap(
    int width, 
    int height, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor, 
    StyledChar fillChar)
    : m_width(width)
    , m_height(height)
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap(height, std::vector<StyledChar>(width, fillChar))
{}

CBJDisplay::CharMap::CharMap(
    std::vector<std::vector<StyledChar>> charMap, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor, 
    StyledChar fillChar)
    : m_width(
        std::max_element(
            charMap.begin(),
            charMap.end(),
            [](
                const std::vector<StyledChar>& a, 
                const std::vector<StyledChar>& b
            ) {
                return a.size() < b.size();
            }
        )->size()
    )
    , m_height(charMap.size())
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap(charMap)
{
    for (auto& row : m_charMap) {
        while (row.size() < m_width) {
            row.push_back(fillChar);
        }
    }
}

CBJDisplay::CharMap::CharMap(
    std::vector<std::string> charRows, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor,
    StyledChar fillChar)
    : m_width(
        std::max_element(
            charRows.begin(),
            charRows.end(),
            [](
                const std::string& a, 
                const std::string& b
            ) {
                return a.size() < b.size();
            }
        )->size()
    )
    , m_height(charRows.size())
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap()
{
    for (const auto& row : charRows) {
        std::vector<StyledChar> styledRow;
        for (char c : row) {
            styledRow.push_back(StyledChar(c, defaultForegroundColor, defaultBackgroundColor));
        }
        while (styledRow.size() < m_width) {
            styledRow.push_back(fillChar);
        }
        m_charMap.push_back(styledRow);
    }
}
