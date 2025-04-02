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
    : m_width(
        (width <= CHARMAP_MAX_WIDTH) ? 
        ((width >= 0) ? width : 0) :
        CHARMAP_MAX_WIDTH)
    , m_height(
        (height <= CHARMAP_MAX_HEIGHT) ?
        ((height >= 0) ? height : 0) :
        CHARMAP_MAX_HEIGHT)
    , m_defaultForegroundColor("WHITE", true)
    , m_defaultBackgroundColor("BLACK", false)
    , m_charMap()
{
    m_charMap = std::vector<std::vector<StyledChar>>(
        m_height,
        std::vector<StyledChar>(
            m_width,
            fillChar
        )
    );
}

CBJDisplay::CharMap::CharMap(
    int width, 
    int height, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor, 
    StyledChar fillChar)
    : m_width(
        (width <= CHARMAP_MAX_WIDTH) ?
        ((width >= 0) ? width : 0) :
        CHARMAP_MAX_WIDTH)
    , m_height(
        (height <= CHARMAP_MAX_HEIGHT) ?
        ((height >= 0) ? height : 0) :
        CHARMAP_MAX_HEIGHT)
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap()
{
    m_charMap = std::vector<std::vector<StyledChar>>(
        m_height,
        std::vector<StyledChar>(
            m_width,
            fillChar
        )
    );
}

CBJDisplay::CharMap::CharMap(
    std::vector<std::vector<StyledChar>> charMap, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor, 
    StyledChar fillChar)
    : m_width(0)
    , m_height(0)
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap()
{
    if (charMap.size() > CHARMAP_MAX_HEIGHT) {
        m_height = CHARMAP_MAX_HEIGHT;
        charMap.resize(CHARMAP_MAX_HEIGHT);
    }
    else {
        m_height = charMap.size();
    }

    int maxWidth = 0;
    for (auto& row : charMap) {
        if (row.size() > CHARMAP_MAX_WIDTH) {
            row.resize(CHARMAP_MAX_WIDTH);
        }
        if (row.size() > maxWidth) {
            maxWidth = row.size();
        }
    }

    m_width = maxWidth;

    for (auto& row : charMap) {
        while (row.size() < m_width) {
            row.push_back(fillChar);
        }
    }

    m_charMap = charMap;
}

CBJDisplay::CharMap::CharMap(
    std::vector<std::string> charRows, 
    ConsoleColor defaultForegroundColor, 
    ConsoleColor defaultBackgroundColor,
    StyledChar fillChar)
    : m_width(0)
    , m_height(0)
    , m_defaultForegroundColor(defaultForegroundColor)
    , m_defaultBackgroundColor(defaultBackgroundColor)
    , m_charMap()
{
    if (charRows.size() > CHARMAP_MAX_HEIGHT) {
        m_height = CHARMAP_MAX_HEIGHT;
        charRows.resize(CHARMAP_MAX_HEIGHT);
    }
    else {
        m_height = charRows.size();
    }

    int maxWidth = 0;
    for (auto& row : charRows) {
        if (row.size() > CHARMAP_MAX_WIDTH) {
            row.resize(CHARMAP_MAX_WIDTH);
        }
        if (row.size() > maxWidth) {
            maxWidth = row.size();
        }
    }

    m_width = maxWidth;

    for (auto& row : charRows) {
        while (row.size() < m_width) {
            row.push_back(fillChar.character());
        }
    }

    for (const auto& row : charRows) {
        std::vector<StyledChar> styledRow;
        for (char c : row) {
            styledRow.push_back(
                StyledChar(
                    c,
                    defaultForegroundColor,
                    defaultBackgroundColor)
            );
        }
        while (styledRow.size() < m_width) {
            styledRow.push_back(fillChar);
        }
        m_charMap.push_back(styledRow);
    }
}

StyledChar CBJDisplay::CharMap::at(int x, int y) const
{
    auto valid = (
        x >= 0 && x < m_width &&
        y >= 0 && y < m_height
    );
    return valid ? m_charMap[y][x]
        : StyledChar(
            ' ', 
            m_defaultForegroundColor, 
            m_defaultBackgroundColor
        );
}

void CBJDisplay::CharMap::setWidth(int width)
{
    int w = (width <= CHARMAP_MAX_WIDTH) ? width : CHARMAP_MAX_WIDTH;

    if (w == m_width) return;

    if (w > 0 && w < m_width) {
        m_width = w;
        for (auto& row : m_charMap) {
            row.resize(w);
        }
    }
    else if (w > m_width) {
        m_width = w;
        for (auto& row : m_charMap) {
            row.resize(
                w,
                StyledChar(
                    ' ', 
                    m_defaultForegroundColor, 
                    m_defaultBackgroundColor)
            );
        }
    }
    else {
        shrinkToZero();
    }
}

void CBJDisplay::CharMap::setHeight(int height)
{
    int h = (height <= CHARMAP_MAX_HEIGHT) ? height : CHARMAP_MAX_HEIGHT;

    if (h == m_height) return;

    if (h > 0 && h < m_height) {
        m_height = h;
        m_charMap.resize(h);
    }
    else if (h > m_height) {
        m_height = h;
        m_charMap.resize(
            h,
            std::vector<StyledChar>(
                m_width,
                StyledChar(
                    ' ',
                    m_defaultForegroundColor,
                    m_defaultBackgroundColor)
            )
        );
    }
    else {
        shrinkToZero();
    }
}

void CBJDisplay::CharMap::setAt(
    int x, 
    int y, 
    StyledChar sc, 
    bool expand)
{
    if (x < 0 || y < 0) return;

    if (x >= m_width && expand) {
        setWidth(x + 1);
    }

    if (y >= m_height && expand) {
        setHeight(y + 1);
    }

    if (x < m_width && y < m_height) {
        m_charMap[y][x] = sc;
    }

    return;
}

void CBJDisplay::CharMap::setAt(
    int x, 
    int y, 
    char c, 
    bool expand)
{
    setAt(
        x,
        y,
        StyledChar(
            c,
            m_defaultForegroundColor,
            m_defaultBackgroundColor
        ),
        expand
    );
}

void CBJDisplay::CharMap::setAt(
    int x, 
    int y, 
    char c, 
    ConsoleColor foregroundColor, 
    ConsoleColor backgroundColor, 
    bool expand)
{
    setAt(
        x,
        y,
        StyledChar(
            c,
            foregroundColor,
            backgroundColor
        ),
        expand
    );
}

void CBJDisplay::CharMap::fill(StyledChar sc)
{
    for (auto& row : m_charMap) {
        std::fill(row.begin(), row.end(), sc);
    }
}

void CBJDisplay::CharMap::fill(char c)
{
    fill(
        StyledChar(
            c,
            m_defaultForegroundColor,
            m_defaultBackgroundColor
        )
    );
}

void CBJDisplay::CharMap::fill(
    char c, 
    ConsoleColor foregroundColor, 
    ConsoleColor backgroundColor)
{
    fill(
        StyledChar(
            c,
            foregroundColor,
            backgroundColor
        )
    );
}

void CBJDisplay::CharMap::clear()
{
    fill(
        StyledChar(
            ' ',
            m_defaultForegroundColor,
            m_defaultBackgroundColor
        )
    );
}

void CBJDisplay::CharMap::shrinkToZero()
{
    m_width = 0;
    m_height = 0;
    m_charMap.clear();
}

void CBJDisplay::CharMap::overlay(
    const CharMap& other,
    int xOffset,
    int yOffset,
    bool expand)
{
    OverlayBounds bounds = prepareOverlay(
        other, 
        xOffset, 
        yOffset, 
        expand);

    for (int y = 0; y < bounds.effectiveHeight; y++) {
        for (int x = 0; x < bounds.effectiveWidth; x++) {
            setAt(
                x + bounds.thisX1,
                y + bounds.thisY1,
                other.at(x + bounds.otherX1, y + bounds.otherY1)
            );
        }
    }
}

void CBJDisplay::CharMap::overlay(
    const CharMap& other, 
    int xOffset, 
    int yOffset, 
    StyledChar transparencyKey, 
    bool expand)
{
    OverlayBounds bounds = prepareOverlay(
        other,
        xOffset,
        yOffset,
        expand);
    for (int y = 0; y < bounds.effectiveHeight; y++) {
        for (int x = 0; x < bounds.effectiveWidth; x++) {
            StyledChar sc = other.at(x + bounds.otherX1, y + bounds.otherY1);
            if (sc != transparencyKey) {
                setAt(
                    x + bounds.thisX1,
                    y + bounds.thisY1,
                    sc
                );
            }
        }
    }
}

CharMap::OverlayBounds CBJDisplay::CharMap::prepareOverlay(
    const CharMap& other, 
    int xOffset, 
    int yOffset, 
    bool expand)
{
    OverlayBounds bounds = {};

    int otherX1, otherX2, otherY1, otherY2;
    int thisX1, thisX2, thisY1, thisY2;

    int otherWidth = other.width();
    int otherHeight = other.height();

    if (xOffset < 0) {
        otherX1 = -xOffset;
        thisX1 = 0;
    }
    else {
        otherX1 = 0;
        thisX1 = xOffset;
    }

    if (yOffset < 0) {
        otherY1 = -yOffset;
        thisY1 = 0;
    }
    else {
        otherY1 = 0;
        thisY1 = yOffset;
    }

    if ((xOffset + otherWidth) > m_width) {
        if (expand) {
            setWidth(xOffset + otherWidth);

            otherX2 = otherWidth - 1;
            thisX2 = m_width - 1;
        }
        else {
            otherX2 = m_width - xOffset - 1;
            thisX2 = m_width - 1;
        }
    }
    else {
        otherX2 = otherWidth - 1;
        thisX2 = xOffset + otherWidth - 1;
    }

    if ((yOffset + otherHeight) > m_height) {
        if (expand) {
            setHeight(yOffset + otherHeight);

            otherY2 = otherHeight - 1;
            thisY2 = m_height - 1;
        }
        else {
            otherY2 = m_height - yOffset - 1;
            thisY2 = m_height - 1;
        }
    }
    else {
        otherY2 = otherHeight - 1;
        thisY2 = yOffset + otherHeight - 1;
    }

    bounds.thisX1 = thisX1;
    bounds.otherX1 = otherX1;
    bounds.effectiveWidth = thisX2 - thisX1 + 1;
    bounds.thisY1 = thisY1;
    bounds.otherY1 = otherY1;
    bounds.effectiveHeight = thisY2 - thisY1 + 1;

    return bounds;
}

std::ostream& CBJDisplay::operator<<(std::ostream& os, const CharMap& cm)
{
    for (const auto& row : cm.rawChars()) {
        for (const auto& sc : row) {
            os << sc;
        }
        os << std::endl;
    }
    return os;
}
