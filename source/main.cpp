/*
**	Rulian & Neo weekend experience 2024
**	Cookie clicker nds
**  main
*/
#include "cookie.hpp"
#include "sprite.hpp"

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

int main(void) {
	cookie::sprite sprite = cookie::sprite();
	sprite.setColor(ARGB16(1, 255, 0, 0));
	sprite.setSize(SpriteSize_16x32);
	touchPosition touchXY;
	irqSet(IRQ_VBLANK, Vblank);
	consoleDemoInit();
	init_down_screen();

	while(1) {	
		sprite.render(&oamSub);

		swiWaitForVBlank(); // clean the screen
		oamUpdate(&oamSub);
	}
	return 0;
}
