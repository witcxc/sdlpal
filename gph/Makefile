BUILD_GP2XWIZ = NO
BUILD_CAANOO = YES

TARGET = sdlpal.gpe

ifeq ($(BUILD_GP2XWIZ), YES)
HOST = arm-open2x-linux-
DEVICE = -DGP2XWIZ
else
ifeq ($(BUILD_CAANOO), YES)
HOST = arm-gph-linux-gnueabi-
DEVICE = -DCAANOO
endif
endif

SOURCES = . .. ../adplug
CFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.cpp))
OFILES = $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

CFLAGS = -g -Wall -O2 `sdl-config --cflags` -DGPH $(DEVICE) -DPAL_HAS_PLATFORM_SPECIFIC_UTILS -I.
CXXFLAGS = $(CFLAGS)
LDFLAGS = `sdl-config --libs`

$(TARGET): $(OFILES)
	$(HOST)g++ $(OFILES) -o $@ $(LDFLAGS)

%.o: %.c
	$(HOST)gcc $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(HOST)g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OFILES)
