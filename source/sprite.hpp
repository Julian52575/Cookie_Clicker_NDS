/*
** EPITECH PROJECT, 2024
** CookieClickerNDS
** File description:
** sprite
*/
#include "cookie.hpp"

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

namespace cookie {

    class sprite {
        public:
            sprite(int color = ARGB16(1, 55, 12, 55), SpriteSize size = SpriteSize_16x16, SpriteColorFormat _colorFormat = SpriteColorFormat_Bmp);
            ~sprite();

        public:
            void
                render(OamState *screen, int x, int y);
        public:
            void
                disableSprite(void);
            void
                setSprite(u8 *tilePtr, unsigned int tileLenght, u8 *palettePtr, unsigned int paletteLen);

        public:
            void
                setColor(int color);
            void
                setSize(SpriteSize size);
            void
                setColorFormat(SpriteColorFormat colorFormat);
        
        private:
            SpriteColorFormat _colorFormat = SpriteColorFormat_Bmp;
            int _color = ARGB16(1, 55, 12, 55);
        
        private:
            SpriteSize _size = SpriteSize_16x16;
            u16* _gfx = nullptr;

        private:
            u8 _id = 0;

        private:
            bool _holdSprite = false;
            u8 *_spriteTiles = nullptr;
            unsigned int _tilesLen = 0;
            u8 *_spritePalette = nullptr;
            unsigned int _paletteLen = 0;
    };

};// namespace cookie

#endif /* !SPRITE_HPP_ */
