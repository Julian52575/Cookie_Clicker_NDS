/*
** EPITECH PROJECT, 2024
** CookieClickerNDS
** File description:
** sprite
*/

#include "sprite.hpp"

namespace cookie {
    static u8 SPRITE_SET_COUNT = 0;

    sprite::sprite(int color, SpriteSize size, SpriteColorFormat colorFormat) : _color(color), _size(size), _colorFormat(colorFormat)
    {
        SPRITE_SET_COUNT += 1;
        this->_id = SPRITE_SET_COUNT;
    }

    sprite::~sprite()
    {
    }

    void
    sprite::setSprite(u8 *tilePtr, unsigned int tileLenght, u8 *palettePtr, unsigned int paletteLen)
    {
        this->_holdSprite = true;
        this->_spriteTiles = tilePtr;
        this->_tilesLen = tileLenght;
        this->_spritePalette = palettePtr;
        this->_paletteLen = paletteLen;
    }

    void
    sprite::render(OamState *screen_info, int x, int y)
    {
        if (this->_gfx == nullptr) {
            this->_gfx = oamAllocateGfx(screen_info, this->_size, this->_colorFormat);
        }
        if (this->_holdSprite == false) {
            dmaFillHalfWords(this->_color, this->_gfx, SPRITE_SIZE_PIXELS(this->_size) );
        } else {
            //      Load palette
            dmaCopy(this->_spritePalette, SPRITE_PALETTE, 512);
            //      Copy sprite data into gfx
            dmaCopy(this->_spriteTiles, this->_gfx, SPRITE_SIZE_PIXELS(this->_size));
        }
		oamSet(screen_info, //screen info
                this->_id,  //id
                x, y, //position
                0, //priority
                15, //palette
                this->_size, //
                this->_colorFormat, //color format
                this->_gfx, //gfx
                0, //affine
                false, //rotated sprite's size doubling
                false, //hiding
                false, false, // v / h flip
                false); //mosaic
    }

    void
    sprite::setColor(int color)
    {
        this->_color = color;
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