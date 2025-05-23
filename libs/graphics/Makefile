PSPSDK=$(shell psp-config --pspsdk-path)
PSPDIR=$(shell psp-config --psp-prefix)
TARGET_LIB = libgraphics.a
OBJS = lib.o graphics.o font.o

all: $(TARGET_LIB)
CFLAGS = -std=c99 -O2 -G0 -Wall -s -lstdc++ -I ../../include -L ../colordebugger
LDFLAGS = -lcolordebugger
CXXFLAGS = $(CFLAGS) -fexceptions -fno-rtti
PSP_FW_VERSION=660

include $(PSPSDK)/lib/build.mak
