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

add_definitions(
	-DSTDC_HEADERS
)

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
target_link_libraries(man system xcselect)

install(TARGETS man DESTINATION libexec/darling/usr/bin)

install(FILES src/apropos src/whatis
	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	DESTINATION libexec/darling/usr/bin)

# Now done by a C program in doc_cmds
#install(FILES src/makewhatis
#	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#	DESTINATION libexec/darling/usr/libexec)

install(FILES src/man.conf DESTINATION libexec/darling/etc)

install(FILES man/en/apropos.1 man/en/man.1 man/en/whatis.1 DESTINATION libexec/darling/usr/share/man/man1)
install(FILES man/en/man.conf.5 DESTINATION libexec/darling/usr/share/man/man5)
#install(FILES man/en/makewhatis.8 DESTINATION libexec/darling/usr/share/man/man8)
