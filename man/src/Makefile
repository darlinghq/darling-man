#
# Generated automatically from Makefile.in by the
# configure script.
#
#
# Master Makefile for man, apropos, whatis, and makewhatis
#
# Copyright (c) 1990, 1991, John W. Eaton.
# Copyright (c) 1994-2001, Andries E. Brouwer
#
# You may distribute under the terms of the GNU General Public
# License as specified in the README file that comes with the man 1.0
# distribution.  
#
# various changes - aeb, March 1994
# use of catalogs - aeb, June 1994

CC = /Users/ariel/private-bin/clang
BUILD_CC = /Users/ariel/private-bin/clang
INSTALL = install
EXEEXT = 

pager = /usr/bin/less -is

DEFS =  -DSTDC_HEADERS -DTERMIOS_HEADER -DPOSIX -DDO_COMPRESS
CWARN = -Wall -Wstrict-prototypes -Wmissing-prototypes
CWARNNP = -Wall

.c.o:
	$(CC) -c $(CWARN) $(CFLAGS) -I. $(DEFS) $<

# LDFLAGS = -g
LDFLAGS ?= -s

LIBOBJS = 

all: man$(EXEEXT) man.conf apropos whatis

MANOBJS = man.o manfile.o manpath.o man-config.o man-getopt.o \
	man-iconv.o to_cat.o different.o gripes.o glob.o util.o msg.o

man$(EXEEXT): $(MANOBJS) $(LIBOBJS)
	$(CC) $(LDFLAGS) -o man$(EXEEXT) $(MANOBJS) $(LIBOBJS) $(LIBS)

# CC may be a cross compiler, but BUILD_CC must compile for
# the present machine.
makemsg:
	$(BUILD_CC) -o makemsg makemsg.c

msg.c gripedefs.h: ../msgs/mess.en makemsg
	./makemsg ../msgs/mess.en gripedefs.h msg.c

# glob.c does not have prototypes
glob.o: glob.c ndir.h
	$(CC) -c $(CWARNNP) $(CFLAGS) $(DEFS) glob.c

man-config.o man-getopt.o man.o manpath.o to_cat.o: defs.h
different.o man.o: different.h
man.o manfile.o: glob.h
different.o gripes.o man-config.o man-getopt.o man.o manfile.o manpath.o util.o: gripes.h gripedefs.h
different.o man-config.o man-getopt.o man.o manpath.o: man-config.h
gripes.o man-config.o man-getopt.o man.o manpath.o util.o: man.h
man-getopt.o man.o manpath.o: man-getopt.h
man.o manfile.o to_cat.o: manfile.h
man.o man-iconv.o: man-iconv.h
man.o manpath.o: manpath.h
man-config.o: paths.h
different.o man-config.o man-getopt.o man.o manpath.o util.o: util.h
man-getopt.o: version.h
msg.o: msg.c
gripes.o: ../catopen/catopen.c

man.conf:	man.conf.in ../conf_script
	../conf_script man.conf

paths.h:	paths.h.in ../conf_script
	../conf_script paths.h

version.h: ../version Makefile
	vers=`sed -e s/man-// ../version`; \
	echo "static char version[] = \"$$vers\";" > version.h

apropos: apropos.sh Makefile
	rm -f apropos
	sed -e 's,%apropos_or_whatis%,apropos,' \
	    -e 's,%version%,man-1.6g,' \
	    -e 's,%manpathoption%,--path,' \
		apropos.sh > apropos
	chmod +x apropos

whatis: apropos.sh Makefile
	rm -f whatis
	sed -e 's,%apropos_or_whatis%,whatis,' \
	    -e 's,%version%,man-1.6g,' \
	    -e 's,%manpathoption%,--path,' \
		apropos.sh > whatis
	chmod +x whatis

makewhatis: makewhatis.sh Makefile
	rm -f makewhatis
	cp makewhatis.sh makewhatis.in
	../conf_script makewhatis
	chmod +x makewhatis

MANCONFIG=$(DESTDIR)$(PREFIX)/private/etc/man.conf

install: all apropos whatis
	mkdir -p $(DESTDIR)$(PREFIX)/usr/bin
	$(INSTALL) -c  man$(EXEEXT) $(DESTDIR)$(PREFIX)/usr/bin/man
	$(INSTALL) -c -m 755 apropos $(DESTDIR)$(PREFIX)/usr/bin/apropos
	$(INSTALL) -c -m 755 whatis $(DESTDIR)$(PREFIX)/usr/bin/whatis
	mkdir -p $(DESTDIR)$(PREFIX)/private/etc
	if [ -f $(MANCONFIG) ]; then mv $(MANCONFIG) $(MANCONFIG).orig; fi
	$(INSTALL) -c -m 644 man.conf $(MANCONFIG)

clean:
	rm -f *.o *~ core man$(EXEEXT) apropos whatis makewhatis makemsg

spotless: clean
	rm -f Makefile config.status paths.h version.h man.conf
	rm -f gripedefs.h msg.c mess.*.cat
