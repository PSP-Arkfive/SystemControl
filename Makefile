TARGET = systemctrl

OBJS = \
	main.o \
	src/modulemanager.o \
	src/elf.o \
	src/flushcache.o \
	src/loadercore.o \
	src/cryptography.o \
	src/interruptman.o \
	src/kubridge.o \
	src/sctrl.o \
	src/sctrl_se.o \
	src/sctrl_hen.o \
	src/oe_malloc.o \
	src/syspatch.o \
	src/mediasync.o \
	src/hooknids.o \
	src/nidresolver.o \
	src/nid_660_data.o \
	src/missingfunc.o \
	src/rebootex.o \
	src/sysmem.o \
	src/lz4.o \
	src/minilzo.o \
	src/loadexec.o \
	src/exitgame.o \
	src/gameinfo.o \
	src/plugin.o \
	src/leda.o \
	src/psnfix.o \
	src/cpuclock.o   \
	src/msstor_cache.o \
	src/threadman.o \
	src/utility.o \
	src/patches.o \
	src/setlongjmp.o \
	external/src/lowerstring.o \
	external/src/strcasecmp.o \
	
	
all: $(TARGET).prx
INCDIR = include external/include
CFLAGS = -std=c99 -Os -G0 -Wall -fno-pic

ifdef DISABLE_PSID_CHECK
CFLAGS += -DDISABLE_PSID_CHECK=$(DISABLE_PSID_CHECK)
endif

ifdef FLASH_RESTORE
CFLAGS += -DFLASH_RESTORE=$(FLASH_RESTORE)
endif

CFLAGS += -I include -I $(ARKROOT)/common/include/ -I $(ARKROOT)/libs/graphics/

CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PRX_EXPORTS = exports.exp

USE_KERNEL_LIBC=1
USE_KERNEL_LIBS=1

LIBDIR = external/libs
LDFLAGS =  -nostartfiles
LIBS = 

ifdef DEBUG
CFLAGS += -DDEBUG=$(DEBUG)
OBJS += debug/exception.o debug/exception_asm.o debug/printk.o debug/jumper.o
LIBS += -lcolordebugger -lscreenprinter
INCDIR += external/include
else
OBJS += debug/dummy.o
endif

PSP_FW_VERSION = 660

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
