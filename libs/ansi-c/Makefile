TARGET_LIB=libansic.a

C_OBJS = \
  memmove.o \
  memcmp.o \
  memcpy.o \
  memset.o \
  strcpy.o \
  strlen.o \
  strchr.o \
  strcmp.o \
  strstr.o \
  memfind.o \
  strhex32.o \
  strsafe.o \
  strbeginswith.o \
  strreplaceall.o \
  strcasecmp.o \
  lowerstring.o

OBJS = $(C_OBJS)

all: $(TARGET_LIB)


CC=psp-gcc
INCDIR = ../../include
CFLAGS = -std=c99 -Wall -Os -G0 -fno-pic
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
