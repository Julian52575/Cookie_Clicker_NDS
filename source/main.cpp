/*
**	Rulian & Neo weekend experience 2024
**	Cookie clicker nds
**  main
*/
#include "cookie.hpp"
#include "sprite.hpp"

#include <cookie_sprite.h>

int main(void) {

	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_SPRITE);
	oamInit(&oamMain, SpriteMapping_1D_128, false);

	u16 *gfx1 = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	u8 *gfx_frame1 = (u8*)cookie_spriteTiles;

	dmaCopy(cookie_spritePal, SPRITE_PALETTE, 64*64);

	while(1) {
		dmaCopy(gfx_frame1, gfx1, 64*64);

		oamSet(
			&oamMain,
			0,
			32, 32,
			0, 16,
			SpriteSize_64x64, SpriteColorFormat_256Color,
			gfx1,
			-1, false, false, false, false, false);

		swiWaitForVBlank(); // clean the screen
		oamUpdate(&oamMain);
	}
	return 0;
}
