#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

void	what_is_init()
{
	Uint32 subsystem_init;

	subsystem_init = SDL_WasInit(SDL_INIT_EVERYTHING);

	printf("------------------------------\n");

	if (subsystem_init & SDL_INIT_VIDEO)
		printf("SDL_VIDEO :          init.\n");
	else
		printf("SDL_VIDEO :          not init.\n");

	if (subsystem_init & SDL_INIT_AUDIO)
		printf("SDL_AUDIO :          init.\n");
	else
		printf("SDL_AUDIO :          not init.\n");

	if (subsystem_init & SDL_INIT_EVENTS)
		printf("SDL_EVENTS :         init.\n");
	else
		printf("SDL_EVENTS :         not init.\n");

	if (subsystem_init & SDL_INIT_TIMER)
		printf("SDL_TIMER :          init.\n");
	else
		printf("SDL_TIMER :          not init.\n");

	if (subsystem_init & SDL_INIT_GAMECONTROLLER)
		printf("SDL_GAMECONTROLLER : init.\n");
	else
		printf("SDL_GAMECONTROLLER : not init.\n");

	if (subsystem_init & SDL_INIT_JOYSTICK)
		printf("SDL_JOYSTICK :       init.\n");
	else
		printf("SDL_JOYSTICK :       not init.\n");

	printf("------------------------------\n");
}

int		main(int argc, char *argv[])
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);

	what_is_init();

	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK);

	what_is_init();

	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	what_is_init();
	SDL_Quit();
	return (0);
}
