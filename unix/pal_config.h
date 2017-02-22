#ifndef PAL_CONFIG_H
# define PAL_CONFIG_H

# ifndef PAL_HAS_JOYSTICKS
#  define PAL_HAS_JOYSTICKS    1
# endif

# if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION <= 2
#  define PAL_ALLOW_KEYREPEAT   1
#  define PAL_HAS_SDLCD         1
# endif

# define PAL_PREFIX            "./"
# define PAL_SAVE_PREFIX       "./"

# define PAL_DEFAULT_WINDOW_WIDTH   640
# define PAL_DEFAULT_WINDOW_HEIGHT  400
# define PAL_DEFAULT_FULLSCREEN_HEIGHT 480

# if SDL_VERSION_ATLEAST(2,0,0)
#  define PAL_VIDEO_INIT_FLAGS  (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | (gConfig.fFullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0))
# else
#  define PAL_VIDEO_INIT_FLAGS  (SDL_HWSURFACE | SDL_RESIZABLE | (gConfig.fFullScreen ? SDL_FULLSCREEN : 0))
#  define PAL_FATAL_OUTPUT(s)   system(va("beep; xmessage -center \"FATAL ERROR: %s\"", (s)))
# endif

# define PAL_SDL_INIT_FLAGS	(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_CDROM | SDL_INIT_NOPARACHUTE | SDL_INIT_JOYSTICK)

# define PAL_PLATFORM         NULL
# define PAL_CREDIT           NULL
# define PAL_PORTYEAR         NULL

# define PAL_HAS_CONFIG_PAGE  1

#endif
