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
            sprite(int x = 10, int y = 10, int color = ARGB16(1, 55, 12, 55), SpriteSize size = SpriteSize_16x16, SpriteColorFormat _colorFormat = SpriteColorFormat_Bmp);
            ~sprite();
            void
                render(OamState *);
            
        private:
            int _x = 0;
            int _y = 0;
            int _color = ARGB16(1, 55, 12, 55);
        
        public:
            SpriteSize _size = SpriteSize_16x16;
            SpriteColorFormat _colorFormat = SpriteColorFormat_Bmp;
            u16* _gfx = nullptr;

    };

};// namespace cookie

#endif /* !SPRITE_HPP_ */
