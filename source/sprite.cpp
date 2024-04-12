/*
** EPITECH PROJECT, 2024
** CookieClickerNDS
** File description:
** sprite
*/

#include "sprite.hpp"

namespace cookie {

    sprite::sprite(int x, int y, int color, SpriteSize size, SpriteColorFormat colorFormat) : _x(x), _y(y), _color(color), _size(size), _colorFormat(colorFormat)
    {
    }

    sprite::~sprite()
    {
    }

    void
    sprite::render(OamState *screen_info)
    {
        if (this->_gfx == nullptr) {
            this->_gfx = oamAllocateGfx(screen_info, this->_size, this->_colorFormat);
        }
        dmaFillHalfWords(this->_color, this->_gfx, 16*16*2);
		oamSet(screen_info, //screen info
                1,  //id
                this->_x, this->_y, //position
                0, //priority
                15,
                SpriteSize_16x16,
                SpriteColorFormat_Bmp,
                this->_gfx,
                0,
                false,
                false,
                false,
                false,
                true);
        return;
    }


}; //namespace cookie