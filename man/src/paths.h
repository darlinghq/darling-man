/*
 * Generated automatically from paths.h.in by the
 * configure script.
 */
/* paths.h - included in man-config.c */
/*
 * Define the absolute path to the configuration file and programs used.
 * (If no configuration file is found then the preset values are used.)
 */
#ifndef CONFIG_FILE
#define CONFIG_FILE "/private/etc/man.conf"
#endif

static struct paths {
    char *name;
    char *path;			/* path plus command options - never NULL */
} paths[] = {
    { "MANBIN",	"" },		/* value unused */
    { "APROPOS",  "/usr/bin/apropos" },
    { "WHATIS",   "/usr/bin/whatis" },
    { "TROFF",	"/usr/bin/groff -Tps -mandoc -c" },
    { "NROFF",	"/usr/bin/groff -Wall -mtty-char -Tascii -mandoc -c" },
    { "JNROFF",	"/usr/bin/groff -Tnippon -mandocj -c" },
    { "EQN",	"/usr/bin/eqn -Tps" },
    { "NEQN",	"/usr/bin/eqn -Tascii" },
    { "JNEQN",	"/usr/bin/eqn -Tnippon" },
    { "TBL",	"/usr/bin/tbl" },
    { "COL",	"" },
    { "REFER",	"/usr/bin/refer" },
    { "PIC",	"/usr/bin/pic" },
    { "VGRIND",	"" },
    { "GRAP",	"" },
    { "PAGER",	"/usr/bin/less -is" },
    { "BROWSER","/usr/bin/less -is" },
    { "HTMLPAGER", "/bin/cat" },
    { "CMP",	"/usr/bin/cmp -s" },
    { "CAT",	"/bin/cat" },
    { "COMPRESS",	"/usr/local/bin/xz" },
    { "COMPRESS_EXT", ".xz" }, /* not a path, just a string variable */
    { "DECOMPRESS",	"/usr/local/bin/unxz -c" },
    { "MANSECT",  "1:1p:8:2:3:3p:4:5:6:7:9:0p:tcl:n:l:p:o"},          /* idem */
    { "MANDEFOPTIONS", ""}                /* idem */
};
