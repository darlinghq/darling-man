#
# Generated automatically from Makefile.in by the
# configure script.
#
# only executed from a subdir
MAN1 = man whatis apropos
MAN5 = man.conf
ALL = man.1 whatis.1 apropos.1 man.conf.5
MAYBE8 = makewhatis

.SUFFIXES: .man .1 .5 .8

.man.1:
	@cp $< $@.in; ../../conf_script $@; rm $@.in

.man.5:
	@cp $< $@.in; ../../conf_script $@; rm $@.in

.man.8:
	@cp $< $@.in; ../../conf_script $@; rm $@.in

INSTALL = install -c -m 644

# Where to put the manual pages.
mandir = $(DESTDIR)$(PREFIX)/usr/share/man$(SLANG)

all:	$(ALL)
	for i in $(MAYBE8); \
		do if test -f $$i.man; then make -f ../Makefile $$i.8; fi; done

install: $(ALL)
	mkdir -p $(mandir)/man1 $(mandir)/man5 $(mandir)/man8
	for i in $(MAN1); \
		do $(INSTALL) $$i.1 $(mandir)/man1/$$i.1; done
	for i in $(MAN5); \
		do $(INSTALL) $$i.5 $(mandir)/man5/$$i.5; done
	for i in $(MAN8); \
		do if test -f $$i.8; then $(INSTALL) $$i.8 $(mandir)/man8/$$i.8; fi; done

clean:
	rm -f core *.in *.1 *.5 *.8 *~

spotless:

subdirs:
	@for i in en; do if test -d $$i; then echo; \
		echo "==== Making the `cat $$i.txt` man pages. ===="; \
		cd $$i; make -f ../Makefile; cd ..; \
		else echo "==== No $$i man pages found. ===="; fi; done

installsubdirs:
	@for i in en; do if test -d $$i; then echo; \
		echo "==== Installing the `cat $$i.txt` man pages. ===="; \
		cd $$i; SLANG=/$$i; if test $$SLANG = /en; then SLANG= ; fi; \
		export SLANG; make -f ../Makefile install; cd ..; \
		else echo "==== No $$i man pages found. ===="; fi; done

cleansubdirs:
	@for i in ??; do cd $$i; make -f ../Makefile clean; cd ..; done
	rm -f core *~

spotlesssubdirs:
	for i in ??; do cd $$i; make -f ../Makefile spotless; cd ..; done
	rm -f Makefile
