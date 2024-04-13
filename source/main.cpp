/*
**	Rulian & Neo weekend experience 2024
**	Cookie clicker nds
**  main
*/
#include "cookie.hpp"
#include "sprite.hpp"
#include <nds/arm9/video.h>

volatile int frame = 0;

static void Vblank() {
	frame++;
}


static void
init_down_screen(void)
{
	//Set Bottom Screen
	videoSetModeSub(MODE_0_2D);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	
	oamInit(&oamSub, SpriteMapping_1D_128, false);
}
static void
init_main_screen(void)
{
	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	oamInit(&oamMain, SpriteMapping_1D_128, false);
}

static void
init_ds(void)
{
	irqSet(IRQ_VBLANK, Vblank);
	//consoleDemoInit();
	init_down_screen();
	init_main_screen();
}


int main(void) {
	cookie::sprite move = cookie::sprite();
	cookie::sprite sprite = cookie::sprite();
	sprite.setColor(ARGB16(1, 255, 0, 0));
	sprite.setSize(SpriteSize_64x64);
	sprite.setColorFormat(SpriteColorFormat_Bmp);
	init_ds();
	int y = 0;

	while(1) {	
		sprite.render(&oamMain, 10, 10);

			scanKeys();
			int keys = keysDown();
			if (keys & KEY_START) {
				sprite.setSprite((u8*) cookie_spriteTiles, cookie_spriteTilesLen, (u8*) cookie_spritePal, cookie_spritePalLen);
				move.setColor(ARGB16(1, 255, 255, 0));
			}

		
		move.render(&oamSub, 80, y++);
		if (y > 100)
			y = 0;


		swiWaitForVBlank(); // clean the screen
		oamUpdate(&oamSub);
		oamUpdate(&oamMain);
	}
	return 0;
}