project(man)

cmake_minimum_required(VERSION 2.4.0)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${DARLING_TOP_DIRECTORY}/src/libc/include/FreeBSD)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc -fwrapv -fPIC -ggdb")
set(CMAKE_SHARED_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")
set(CMAKE_EXE_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

set(man_sources
	src/man.c
	src/manfile.c
	src/manpath.c
	src/man-config.c
	src/man-getopt.c
	src/man-iconv.c
	src/to_cat.c
	src/different.c
	src/gripes.c
	src/glob.c
	src/util.c
	src/msg.c
)

add_darling_executable(man ${man_sources})
target_link_libraries(man system)
