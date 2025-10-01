cmake_minimum_required(VERSION 3.28)

project(systemcontrol VERSION 1.0 LANGUAGES C ASM)

set(DEBUG "" CACHE STRING "Debug level (1,2,3)")
message(STATUS "DEBUG LEVEL = ${DEBUG}")

include(FetchContent)

FetchContent_Declare(
    ark-dev-sdk
    GIT_REPOSITORY https://github.com/PSP-Arkfive/ark-dev-sdk.git
    GIT_TAG main
    EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(ark-dev-sdk)

set(ARKSDK ${ark-dev-sdk_SOURCE_DIR})

add_prx_module(systemctrl exports.exp)

target_sources(systemctrl PRIVATE 
   main.c
	src/modulemanager.c
	src/elf.c
	src/flushcache.c
	src/loadercore.c
	src/cryptography.c
	src/interruptman.c
	src/kubridge.c
	src/sctrl.c
	src/sctrl_se.c
	src/sctrl_hen.c
	src/oe_malloc.c
	src/syspatch.c
	src/mediasync.c
	src/hooknids.c
	src/nidresolver.c
	src/nid_660_data.c
	src/missingfunc.c
	src/rebootex.c
	src/sysmem.c
	src/lz4.c
	src/minilzo.c
	src/loadexec.c
	src/exitgame.c
	src/gameinfo.c
	src/plugin.c
	src/leda.c
	src/psnfix.c
	src/cpuclock.c  
	src/msstor_cache.c
	src/threadman.c
	src/utility.c
	src/patches.c
	src/setlongjmp.S
   ${ARKSDK}/src/ansi-c/lowerstring.c
	${ARKSDK}/src/ansi-c/strcasecmp.c
)

remove_definitions("-D_PSP_FW_VERSION=600")
add_definitions("-D_PSP_FW_VERSION=660")

target_compile_options(systemctrl PRIVATE -std=c99 -Os -G0 -Wall -fno-pic)
target_include_directories(systemctrl PRIVATE include ${ARKSDK}/include)
target_link_directories(systemctrl PRIVATE ${ARKSDK}/libs)
target_link_libraries(systemctrl PRIVATE
   -nostartfiles
   -nostdlib
   pspsemaphore_660
   pspinit_kernel_660
   pspsysmem_kernel_660
   pspsysclib_kernel_660
   psploadcore_kernel_660
   pspmodulemgr_kernel_660
   pspthreadman_kernel_660
   pspinterruptmanager_kernel_660
   pspsdk
   pspmodinfo
   pspkernel
)
add_dependencies(systemctrl CopyPrebuiltSdkLibs)

if(DEBUG)
   target_compile_definitions(systemctrl PRIVATE -DDEBUG=${DEBUG})
   target_link_libraries(systemctrl PRIVATE colordebugger)
else()
   target_sources(systemctrl PRIVATE debug/dummy.c)
endif()
