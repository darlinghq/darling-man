project(man)

include(darling_exe)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Hide warnings
add_definitions(
	-Wno-int-conversion
	-Wno-incompatible-library-redeclaration
	-Wno-incompatible-pointer-types-discards-qualifiers
)

add_compile_options(
	-nostdinc
	-fwrapv
)

add_compile_definitions(
	STDC_HEADERS
	TERMIOS_HEADER
	POSIX
	DO_COMPRESS
)

set(man_sources
	man/src/man.c
	man/src/manfile.c
	man/src/manpath.c
	man/src/man-config.c
	man/src/man-getopt.c
	man/src/man-iconv.c
	man/src/to_cat.c
	man/src/different.c
	man/src/gripes.c
	man/src/glob.c
	man/src/util.c
	man/src/msg.c
)

add_darling_executable(man ${man_sources})
target_link_libraries(man system xcselect)

install(TARGETS man DESTINATION libexec/darling/usr/bin)

install(FILES man/src/apropos man/src/whatis
	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	DESTINATION libexec/darling/usr/bin)

install(FILES man/src/man.conf DESTINATION libexec/darling/etc)

install(FILES man/man/en/apropos.1 man/man/en/man.1 man/man/en/whatis.1 DESTINATION libexec/darling/usr/share/man/man1)
install(FILES man/man/en/man.conf.5 DESTINATION libexec/darling/usr/share/man/man5)
