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
        dmaFillHalfWords(this->_color, this->_gfx, SPRITE_SIZE_PIXELS(this->_size) );
		oamSet(screen_info, //screen info
                1,  //id
                this->_x, this->_y, //position
                0, //priority
                15, //palette
                this->_size, //
                SpriteColorFormat_Bmp, //color format
                this->_gfx, //gfx
                0, //affine
                false, //rotated sprite's size doubling
                false, //hiding
                false, false, // v / h flip
                true); //mosaic
        return;
    }

    void
    sprite::setColor(int color)
    {
        this->_color = color;
    }
    void
    sprite::setXposition(int x)
    {
        this->_x = x;
    }
    void
    sprite::setYposition(int y)
    {
        this->_y = y;
    }

    void
    sprite::setSize(SpriteSize size)
    {
        this->_size = size;
    }
    void
    sprite::setColorFormat(SpriteColorFormat colorFormat)
    {
        this->_colorFormat = colorFormat;
    }


}; //namespace cookie