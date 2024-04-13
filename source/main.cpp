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
	vramSetBankA( (VRAM_A_TYPE) (VRAM_A_MAIN_SPRITE | VRAM_A_MAIN_BG));
	oamInit(&oamMain, SpriteMapping_1D_128, false);
}

static void
init_ds(void)
{
	//irqSet(IRQ_VBLANK, Vblank);
	//consoleDemoInit();
	init_down_screen();
	init_main_screen();
}


int main(void) {
	cookie::sprite move = cookie::sprite();

	cookie::sprite sprite = cookie::sprite();
	sprite.setColor(ARGB16(1, 255, 0, 0));
	sprite.setSize(SpriteSize_16x16);
	sprite.setColorFormat(SpriteColorFormat_256Color);
	sprite.setSprite((u8*) character16x16Tiles, character16x16TilesLen, (u8*) character16x16Pal, character16x16PalLen);

	cookie::sprite cookie = cookie::sprite();
	cookie.setColor(ARGB16(1, 222, 222, 0));
	cookie.setSize(SpriteSize_16x16);
	cookie.setColorFormat(SpriteColorFormat_256Color);
	init_ds();
	int y = 0;

	while(1) {	
		sprite.render(&oamMain, 80, 50);
		cookie.render(&oamMain, 10, 10);

			scanKeys();
			int keys = keysDown();
			if (keys & KEY_START) {
				cookie.setSprite((u8*) cookie_sprite16Tiles, cookie_sprite16TilesLen, (u8*) cookie_sprite16Pal, cookie_sprite16PalLen);
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