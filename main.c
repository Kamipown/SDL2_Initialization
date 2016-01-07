#include <stdlib.h>
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

static void	print_init_video(void)
{
	if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
		printf("SDL_VIDEO :          init.\n");
	else
		printf("SDL_VIDEO :          not init.\n");
}

static void	print_init_audio(void)
{
	if (SDL_WasInit(SDL_INIT_AUDIO) != 0)
		printf("SDL_AUDIO :          init.\n");
	else
		printf("SDL_AUDIO :          not init.\n");
}

static void	print_init_events(void)
{
	if (SDL_WasInit(SDL_INIT_EVENTS) != 0)
		printf("SDL_EVENTS :         init.\n");
	else
		printf("SDL_EVENTS :         not init.\n");
}

static void	print_init_timer(void)
{
	if (SDL_WasInit(SDL_INIT_TIMER) != 0)
		printf("SDL_TIMER :          init.\n");
	else
		printf("SDL_TIMER :          not init.\n");
}

static void	print_init_gamecontroller(void)
{
	if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) != 0)
		printf("SDL_GAMECONTROLLER : init.\n");
	else
		printf("SDL_GAMECONTROLLER : not init.\n");
}

static void	print_init_joystick(void)
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) != 0)
		printf("SDL_JOYSTICK :       init.\n");
	else
		printf("SDL_JOYSTICK :       not init.\n");
}

static void	what_is_init(void)
{
	printf("------------------------------\n");
	print_init_video();
	print_init_audio();
	print_init_events();
	print_init_timer();
	print_init_gamecontroller();
	print_init_joystick();
	printf("------------------------------\n");
}

int			main(int argc, char *argv[])
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	what_is_init();
	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
	what_is_init();
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	what_is_init();
	SDL_Quit();
	return (EXIT_SUCCESS);
}

/*
	Functions used :

	void SDL_SetMainReady(void)
	int SDL_Init(Uint32 flags)
	int SDL_InitSubSystem(Uint32 flags)
	Uint32 SDL_WasInit(Uint32 flags)
	void SDL_QuitSubSystem(Uint32 flags)
	void SDL_Quit(void)

	SDL_SetMainReady is used to circumvent failure of SDL_Init() when not using SDL_main() as an entry point.
	SDL_Init is used to initialize the SDL library.
	SDL_InitSubSystem is used to initialize specific SDL subsystems.
	SDL_WasInit returns a mask of the specified subsystems which have previously been initialized.
	SDL_QuitSubSystem is used to shut down specific SDL subsystems.
	SDL_Quit to clean up all initialized subsystems.
	
	Notes :
	- SDL_Init must be called before using any other SDL function.
		- You can use SDL_Init(0) followed by SDL_InitSubSystem() with the desired subsystem flag to initialize subsystems separately.
	- Init SDL_INIT_VIDEO will init SDL_INIT_EVENTS too.
	- Init SDL_INIT_TIMER will init SDL_INIT_EVENTS too.
	- Init SDL_INIT_JOYSTICK will init SDL_INIT_EVENTS too.
	- Init SDL_INIT_GAMECONTROLLER will init SDL_INIT_EVENTS and SDL_INIT_JOYSTICK too.
	- SDL_Quit should be called upon all exit conditions.
*/