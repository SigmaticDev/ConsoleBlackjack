#pragma once

#include "StyledChar.h"

#include <string>
#include <vector>

namespace CBJDisplay {

    static const int CHARMAP_MAX_WIDTH = 80;
    static const int CHARMAP_MAX_HEIGHT = 60;

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
        void setDefaultForegroundColor(ConsoleColor color) {
            m_defaultForegroundColor = color;
        }
        void setDefaultBackgroundColor(ConsoleColor color) {
            m_defaultBackgroundColor = color;
        }
        void setAt(int x, int y, StyledChar sc, bool expand = false);
        void setAt(int x, int y, char c, bool expand = false);
        void setAt(
            int x,
            int y,
            char c,
            ConsoleColor foregroundColor,
            ConsoleColor backgroundColor,
            bool expand = false
        );

        void fill(StyledChar sc);
        void fill(char c);
        void fill(
            char c,
            ConsoleColor foregroundColor,
            ConsoleColor backgroundColor
        );

        void clear();
        void shrinkToZero();

        void overlay(
            const CharMap& other,
            int xOffset = 0,
            int yOffset = 0,
            bool expand = false
        );
        void overlay(
            const CharMap& other,
            int xOffset,
            int yOffset,
            StyledChar transparencyKey,
            bool expand = false
        );

        friend std::ostream& operator<<(
            std::ostream& os,
            const CharMap& cm
        );

    private:
        struct OverlayBounds {
            int thisX1;
            int otherX1;
            int effectiveWidth;
            int thisY1;
            int otherY1;
            int effectiveHeight;
        };

        OverlayBounds prepareOverlay(
            const CharMap& other,
            int xOffset,
            int yOffset,
            bool expand
        );

        int m_width;
        int m_height;
        ConsoleColor m_defaultForegroundColor;
        ConsoleColor m_defaultBackgroundColor;
        std::vector<std::vector<StyledChar>> m_charMap;
    };

}