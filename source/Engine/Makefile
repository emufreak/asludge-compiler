# Makefile.in generated by automake 1.16.5 from Makefile.am.
# source/Engine/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2021 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.





am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/sludge
pkgincludedir = $(includedir)/sludge
pkglibdir = $(libdir)/sludge
pkglibexecdir = $(libexecdir)/sludge
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-pc-linux-gnu
host_triplet = x86_64-pc-linux-gnu
bin_PROGRAMS = sludge-engine$(EXEEXT)
#am__append_1 = eglport/eglport.cpp eglport/eglport.h
#am__append_2 = -DHAVE_GLES2 -DUSE_EGL_SDL -DUSE_GLES2
am__append_3 =  
am__append_4 =  -L/usr/lib64 -lGLEW -lGL -lX11 -lGLU
#am__append_5 = -DPANDORA
#am__append_6 = -liconv
#am__append_7 = -DRPI
#am__append_8 = -DODROID
subdir = source/Engine
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(dist_pkgdata_DATA) \
	$(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
am__installdirs = "$(DESTDIR)$(bindir)" "$(DESTDIR)$(pkgdatadir)"
PROGRAMS = $(bin_PROGRAMS)
am__sludge_engine_SOURCES_DIST = backdrop.cpp bg_effects.cpp \
	builtin.cpp cursors.cpp debug.cpp fileset.cpp floor.cpp \
	fonttext.cpp freeze.cpp graphics.cpp helpers.cpp language.cpp \
	line.cpp linuxstuff.cpp loadsave.cpp main.cpp memwatch.cpp \
	moreio.cpp movie.cpp newfatal.cpp objtypes.cpp people.cpp \
	region.cpp savedata.cpp shaders.cpp sludger.cpp sprbanks.cpp \
	sprites.cpp statusba.cpp stringy.cpp talk.cpp thumbnail.cpp \
	timing.cpp transition.cpp variable.cpp zbuffer.cpp \
	sound_openal.cpp allfiles.h backdrop.h bg_effects.h builtin.h \
	colours.h csludge.h cursors.h debug.h errors.h fileset.h \
	floor.h fonttext.h freeze.h graphics.h helpers.h language.h \
	line.h loadsave.h memwatch.h moreio.h movie.h newfatal.h \
	objtypes.h people.h region.h savedata.h shaders.h sludger.h \
	sound.h sprbanks.h sprites.h statusba.h stringy.h talk.h \
	thumbnail.h timing.h transition.h variable.h \
	platform-dependent.h linuxstuff.h zbuffer.h \
	../CommonCode/utf8.cpp ../CommonCode/utf8.h \
	../CommonCode/functionlist.h ../CommonCode/specialsettings.h \
	../CommonCode/version.h libvorbis/vorbis_misc.h \
	libvorbis/vorbis_os.h libwebm/mkvparser.cpp \
	libwebm/mkvparser.hpp libwebm/mkvreader.cpp \
	libwebm/mkvreader.hpp eglport/eglport.cpp eglport/eglport.h
am__dirstamp = $(am__leading_dot)dirstamp
#am__objects_1 = eglport/eglport.$(OBJEXT)
am_sludge_engine_OBJECTS = backdrop.$(OBJEXT) bg_effects.$(OBJEXT) \
	builtin.$(OBJEXT) cursors.$(OBJEXT) debug.$(OBJEXT) \
	fileset.$(OBJEXT) floor.$(OBJEXT) fonttext.$(OBJEXT) \
	freeze.$(OBJEXT) graphics.$(OBJEXT) helpers.$(OBJEXT) \
	language.$(OBJEXT) line.$(OBJEXT) linuxstuff.$(OBJEXT) \
	loadsave.$(OBJEXT) main.$(OBJEXT) memwatch.$(OBJEXT) \
	moreio.$(OBJEXT) movie.$(OBJEXT) newfatal.$(OBJEXT) \
	objtypes.$(OBJEXT) people.$(OBJEXT) region.$(OBJEXT) \
	savedata.$(OBJEXT) shaders.$(OBJEXT) sludger.$(OBJEXT) \
	sprbanks.$(OBJEXT) sprites.$(OBJEXT) statusba.$(OBJEXT) \
	stringy.$(OBJEXT) talk.$(OBJEXT) thumbnail.$(OBJEXT) \
	timing.$(OBJEXT) transition.$(OBJEXT) variable.$(OBJEXT) \
	zbuffer.$(OBJEXT) sound_openal.$(OBJEXT) \
	../CommonCode/utf8.$(OBJEXT) libwebm/mkvparser.$(OBJEXT) \
	libwebm/mkvreader.$(OBJEXT) $(am__objects_1)
sludge_engine_OBJECTS = $(am_sludge_engine_OBJECTS)
sludge_engine_LDADD = $(LDADD)
am__DEPENDENCIES_1 =
sludge_engine_DEPENDENCIES = $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1)
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I. -I$(top_builddir)
depcomp = $(SHELL) $(top_srcdir)/depcomp
am__maybe_remake_depfiles = depfiles
am__depfiles_remade = ../CommonCode/$(DEPDIR)/utf8.Po \
	./$(DEPDIR)/backdrop.Po ./$(DEPDIR)/bg_effects.Po \
	./$(DEPDIR)/builtin.Po ./$(DEPDIR)/cursors.Po \
	./$(DEPDIR)/debug.Po ./$(DEPDIR)/fileset.Po \
	./$(DEPDIR)/floor.Po ./$(DEPDIR)/fonttext.Po \
	./$(DEPDIR)/freeze.Po ./$(DEPDIR)/graphics.Po \
	./$(DEPDIR)/helpers.Po ./$(DEPDIR)/language.Po \
	./$(DEPDIR)/line.Po ./$(DEPDIR)/linuxstuff.Po \
	./$(DEPDIR)/loadsave.Po ./$(DEPDIR)/main.Po \
	./$(DEPDIR)/memwatch.Po ./$(DEPDIR)/moreio.Po \
	./$(DEPDIR)/movie.Po ./$(DEPDIR)/newfatal.Po \
	./$(DEPDIR)/objtypes.Po ./$(DEPDIR)/people.Po \
	./$(DEPDIR)/region.Po ./$(DEPDIR)/savedata.Po \
	./$(DEPDIR)/shaders.Po ./$(DEPDIR)/sludger.Po \
	./$(DEPDIR)/sound_openal.Po ./$(DEPDIR)/sprbanks.Po \
	./$(DEPDIR)/sprites.Po ./$(DEPDIR)/statusba.Po \
	./$(DEPDIR)/stringy.Po ./$(DEPDIR)/talk.Po \
	./$(DEPDIR)/thumbnail.Po ./$(DEPDIR)/timing.Po \
	./$(DEPDIR)/transition.Po ./$(DEPDIR)/variable.Po \
	./$(DEPDIR)/zbuffer.Po eglport/$(DEPDIR)/eglport.Po \
	libwebm/$(DEPDIR)/mkvparser.Po libwebm/$(DEPDIR)/mkvreader.Po
am__mv = mv -f
CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
AM_V_CXX = $(am__v_CXX_$(V))
am__v_CXX_ = $(am__v_CXX_$(AM_DEFAULT_VERBOSITY))
am__v_CXX_0 = @echo "  CXX     " $@;
am__v_CXX_1 = 
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS) \
	-o $@
AM_V_CXXLD = $(am__v_CXXLD_$(V))
am__v_CXXLD_ = $(am__v_CXXLD_$(AM_DEFAULT_VERBOSITY))
am__v_CXXLD_0 = @echo "  CXXLD   " $@;
am__v_CXXLD_1 = 
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
AM_V_CC = $(am__v_CC_$(V))
am__v_CC_ = $(am__v_CC_$(AM_DEFAULT_VERBOSITY))
am__v_CC_0 = @echo "  CC      " $@;
am__v_CC_1 = 
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CCLD = $(am__v_CCLD_$(V))
am__v_CCLD_ = $(am__v_CCLD_$(AM_DEFAULT_VERBOSITY))
am__v_CCLD_0 = @echo "  CCLD    " $@;
am__v_CCLD_1 = 
SOURCES = $(sludge_engine_SOURCES)
DIST_SOURCES = $(am__sludge_engine_SOURCES_DIST)
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
DATA = $(dist_pkgdata_DATA)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
am__DIST_COMMON = $(srcdir)/Makefile.in $(top_srcdir)/depcomp
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} '/home/uersu/opensludge/missing' aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 0
AUTOCONF = ${SHELL} '/home/uersu/opensludge/missing' autoconf
AUTOHEADER = ${SHELL} '/home/uersu/opensludge/missing' autoheader
AUTOMAKE = ${SHELL} '/home/uersu/opensludge/missing' automake-1.16
AWK = gawk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O2
CPPFLAGS = 
CSCOPE = cscope
CTAGS = ctags
CXX = g++
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -g -O2
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
ECHO_C = 
ECHO_N = -n
ECHO_T = 
ENGINE_CFLAGS = 
ENGINE_LIBS = 
ETAGS = etags
EXEEXT = 
GLEW_CFLAGS = 
GLEW_LIBS = -L/usr/lib64 -lGLEW -lGL -lX11 -lGLU
GLIB_CFLAGS = -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
GLIB_LIBS = -lglib-2.0
GL_CFLAGS = 
GL_LIBS = 
GTK_CFLAGS = -pthread -I/usr/include/gtkglext-1.0 -I/usr/lib/x86_64-linux-gnu/gtkglext-1.0/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/x86_64-linux-gnu -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
GTK_LIBS = -lgthread-2.0 -pthread -lgtkglext-x11-1.0 -lgdkglext-x11-1.0 -lGLU -lGL -lXmu -lXt -lSM -lICE -lgdk-x11-2.0 -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lharfbuzz -lfontconfig -lfreetype -Wl,--export-dynamic -lgmodule-2.0 -pthread -lglib-2.0
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS = 
LIBOBJS = 
LIBPNG_CFLAGS = -I/usr/include/libpng16
LIBPNG_LIBS = -lpng16 -lz
LIBS = 
LTLIBOBJS = 
MAKEINFO = ${SHELL} '/home/uersu/opensludge/missing' makeinfo
MKDIR_P = /usr/bin/mkdir -p
OBJEXT = o
PACKAGE = sludge
PACKAGE_BUGREPORT = tobias.han@gmx.de
PACKAGE_NAME = SLUDGE
PACKAGE_STRING = SLUDGE 2.2.2
PACKAGE_TARNAME = sludge
PACKAGE_URL = http://opensludge.github.io/
PACKAGE_VERSION = 2.2.2
PATH_SEPARATOR = :
PKG_CONFIG = /usr/bin/pkg-config
PKG_CONFIG_LIBDIR = 
PKG_CONFIG_PATH = 
SET_MAKE = 
SHELL = /bin/bash
STRIP = 
VERSION = 2.2.2
abs_builddir = /home/uersu/opensludge/source/Engine
abs_srcdir = /home/uersu/opensludge/source/Engine
abs_top_builddir = /home/uersu/opensludge
abs_top_srcdir = /home/uersu/opensludge
ac_ct_CC = gcc
ac_ct_CXX = g++
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-pc-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = pc
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-pc-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/uersu/opensludge/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
runstatedir = ${localstatedir}/run
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../../
top_builddir = ../..
top_srcdir = ../..
sludge_engine_SOURCES = backdrop.cpp bg_effects.cpp builtin.cpp \
	cursors.cpp debug.cpp fileset.cpp floor.cpp fonttext.cpp \
	freeze.cpp graphics.cpp helpers.cpp language.cpp line.cpp \
	linuxstuff.cpp loadsave.cpp main.cpp memwatch.cpp moreio.cpp \
	movie.cpp newfatal.cpp objtypes.cpp people.cpp region.cpp \
	savedata.cpp shaders.cpp sludger.cpp sprbanks.cpp sprites.cpp \
	statusba.cpp stringy.cpp talk.cpp thumbnail.cpp timing.cpp \
	transition.cpp variable.cpp zbuffer.cpp sound_openal.cpp \
	allfiles.h backdrop.h bg_effects.h builtin.h colours.h \
	csludge.h cursors.h debug.h errors.h fileset.h floor.h \
	fonttext.h freeze.h graphics.h helpers.h language.h line.h \
	loadsave.h memwatch.h moreio.h movie.h newfatal.h objtypes.h \
	people.h region.h savedata.h shaders.h sludger.h sound.h \
	sprbanks.h sprites.h statusba.h stringy.h talk.h thumbnail.h \
	timing.h transition.h variable.h platform-dependent.h \
	linuxstuff.h zbuffer.h ../CommonCode/utf8.cpp \
	../CommonCode/utf8.h ../CommonCode/functionlist.h \
	../CommonCode/specialsettings.h ../CommonCode/version.h \
	libvorbis/vorbis_misc.h libvorbis/vorbis_os.h \
	libwebm/mkvparser.cpp libwebm/mkvparser.hpp \
	libwebm/mkvreader.cpp libwebm/mkvreader.hpp $(am__append_1)
dist_pkgdata_DATA = \
	fixScaleSprite.frag fixScaleSprite.vert \
	scale.frag scale_noaa.frag scale.vert \
	texture.frag texture.vert \
	color.frag color.vert \
	yuv.frag yuv.vert

AM_CPPFLAGS = -std=c++0x -I$(top_srcdir)/source/CommonCode \
	-I$(top_srcdir)/source/Engine/libwebm  \
	-I/usr/include/libpng16 -DDATADIR='"$(pkgdatadir)/"' $(am__append_2) \
	$(am__append_3) $(am__append_5) $(am__append_7) \
	$(am__append_8)
LDADD =  -lpng16 -lz $(am__append_4) $(am__append_6)
EXTRA_DIST = \
	libvorbis/COPYING \
	libwebm/AUTHORS.TXT \
	libwebm/LICENSE.TXT \
	libwebm/PATENTS.TXT

all: all-am

.SUFFIXES:
.SUFFIXES: .cpp .o .obj
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu source/Engine/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu source/Engine/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(bindir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(bindir)" || exit 1; \
	fi; \
	for p in $$list; do echo "$$p $$p"; done | \
	sed 's/$(EXEEXT)$$//' | \
	while read p p1; do if test -f $$p \
	  ; then echo "$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n;h' \
	    -e 's|.*|.|' \
	    -e 'p;x;s,.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/' | \
	sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1 } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) files[d] = files[d] " " $$1; \
	    else { print "f", $$3 "/" $$4, $$1; } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	    if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	    test -z "$$files" || { \
	      echo " $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	      $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	    } \
	; done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	files=`for p in $$list; do echo "$$p"; done | \
	  sed -e 'h;s,^.*/,,;s/$(EXEEXT)$$//;$(transform)' \
	      -e 's/$$/$(EXEEXT)/' \
	`; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)
../CommonCode/$(am__dirstamp):
	@$(MKDIR_P) ../CommonCode
	@: > ../CommonCode/$(am__dirstamp)
../CommonCode/$(DEPDIR)/$(am__dirstamp):
	@$(MKDIR_P) ../CommonCode/$(DEPDIR)
	@: > ../CommonCode/$(DEPDIR)/$(am__dirstamp)
../CommonCode/utf8.$(OBJEXT): ../CommonCode/$(am__dirstamp) \
	../CommonCode/$(DEPDIR)/$(am__dirstamp)
libwebm/$(am__dirstamp):
	@$(MKDIR_P) libwebm
	@: > libwebm/$(am__dirstamp)
libwebm/$(DEPDIR)/$(am__dirstamp):
	@$(MKDIR_P) libwebm/$(DEPDIR)
	@: > libwebm/$(DEPDIR)/$(am__dirstamp)
libwebm/mkvparser.$(OBJEXT): libwebm/$(am__dirstamp) \
	libwebm/$(DEPDIR)/$(am__dirstamp)
libwebm/mkvreader.$(OBJEXT): libwebm/$(am__dirstamp) \
	libwebm/$(DEPDIR)/$(am__dirstamp)
eglport/$(am__dirstamp):
	@$(MKDIR_P) eglport
	@: > eglport/$(am__dirstamp)
eglport/$(DEPDIR)/$(am__dirstamp):
	@$(MKDIR_P) eglport/$(DEPDIR)
	@: > eglport/$(DEPDIR)/$(am__dirstamp)
eglport/eglport.$(OBJEXT): eglport/$(am__dirstamp) \
	eglport/$(DEPDIR)/$(am__dirstamp)

sludge-engine$(EXEEXT): $(sludge_engine_OBJECTS) $(sludge_engine_DEPENDENCIES) $(EXTRA_sludge_engine_DEPENDENCIES) 
	@rm -f sludge-engine$(EXEEXT)
	$(AM_V_CXXLD)$(CXXLINK) $(sludge_engine_OBJECTS) $(sludge_engine_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)
	-rm -f ../CommonCode/*.$(OBJEXT)
	-rm -f eglport/*.$(OBJEXT)
	-rm -f libwebm/*.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ../CommonCode/$(DEPDIR)/utf8.Po # am--include-marker
include ./$(DEPDIR)/backdrop.Po # am--include-marker
include ./$(DEPDIR)/bg_effects.Po # am--include-marker
include ./$(DEPDIR)/builtin.Po # am--include-marker
include ./$(DEPDIR)/cursors.Po # am--include-marker
include ./$(DEPDIR)/debug.Po # am--include-marker
include ./$(DEPDIR)/fileset.Po # am--include-marker
include ./$(DEPDIR)/floor.Po # am--include-marker
include ./$(DEPDIR)/fonttext.Po # am--include-marker
include ./$(DEPDIR)/freeze.Po # am--include-marker
include ./$(DEPDIR)/graphics.Po # am--include-marker
include ./$(DEPDIR)/helpers.Po # am--include-marker
include ./$(DEPDIR)/language.Po # am--include-marker
include ./$(DEPDIR)/line.Po # am--include-marker
include ./$(DEPDIR)/linuxstuff.Po # am--include-marker
include ./$(DEPDIR)/loadsave.Po # am--include-marker
include ./$(DEPDIR)/main.Po # am--include-marker
include ./$(DEPDIR)/memwatch.Po # am--include-marker
include ./$(DEPDIR)/moreio.Po # am--include-marker
include ./$(DEPDIR)/movie.Po # am--include-marker
include ./$(DEPDIR)/newfatal.Po # am--include-marker
include ./$(DEPDIR)/objtypes.Po # am--include-marker
include ./$(DEPDIR)/people.Po # am--include-marker
include ./$(DEPDIR)/region.Po # am--include-marker
include ./$(DEPDIR)/savedata.Po # am--include-marker
include ./$(DEPDIR)/shaders.Po # am--include-marker
include ./$(DEPDIR)/sludger.Po # am--include-marker
include ./$(DEPDIR)/sound_openal.Po # am--include-marker
include ./$(DEPDIR)/sprbanks.Po # am--include-marker
include ./$(DEPDIR)/sprites.Po # am--include-marker
include ./$(DEPDIR)/statusba.Po # am--include-marker
include ./$(DEPDIR)/stringy.Po # am--include-marker
include ./$(DEPDIR)/talk.Po # am--include-marker
include ./$(DEPDIR)/thumbnail.Po # am--include-marker
include ./$(DEPDIR)/timing.Po # am--include-marker
include ./$(DEPDIR)/transition.Po # am--include-marker
include ./$(DEPDIR)/variable.Po # am--include-marker
include ./$(DEPDIR)/zbuffer.Po # am--include-marker
include eglport/$(DEPDIR)/eglport.Po # am--include-marker
include libwebm/$(DEPDIR)/mkvparser.Po # am--include-marker
include libwebm/$(DEPDIR)/mkvreader.Po # am--include-marker

$(am__depfiles_remade):
	@$(MKDIR_P) $(@D)
	@echo '# dummy' >$@-t && $(am__mv) $@-t $@

am--depfiles: $(am__depfiles_remade)

.cpp.o:
	$(AM_V_CXX)depbase=`echo $@ | sed 's|[^/]*$$|$(DEPDIR)/&|;s|\.o$$||'`;\
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $$depbase.Tpo -c -o $@ $< &&\
	$(am__mv) $$depbase.Tpo $$depbase.Po
#	$(AM_V_CXX)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXXCOMPILE) -c -o $@ $<

.cpp.obj:
	$(AM_V_CXX)depbase=`echo $@ | sed 's|[^/]*$$|$(DEPDIR)/&|;s|\.obj$$||'`;\
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $$depbase.Tpo -c -o $@ `$(CYGPATH_W) '$<'` &&\
	$(am__mv) $$depbase.Tpo $$depbase.Po
#	$(AM_V_CXX)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXXCOMPILE) -c -o $@ `$(CYGPATH_W) '$<'`
install-dist_pkgdataDATA: $(dist_pkgdata_DATA)
	@$(NORMAL_INSTALL)
	@list='$(dist_pkgdata_DATA)'; test -n "$(pkgdatadir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(pkgdatadir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(pkgdatadir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(pkgdatadir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(pkgdatadir)" || exit $$?; \
	done

uninstall-dist_pkgdataDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(dist_pkgdata_DATA)'; test -n "$(pkgdatadir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(pkgdatadir)'; $(am__uninstall_files_from_dir)

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags
distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(PROGRAMS) $(DATA)
installdirs:
	for dir in "$(DESTDIR)$(bindir)" "$(DESTDIR)$(pkgdatadir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)
	-rm -f ../CommonCode/$(DEPDIR)/$(am__dirstamp)
	-rm -f ../CommonCode/$(am__dirstamp)
	-rm -f eglport/$(DEPDIR)/$(am__dirstamp)
	-rm -f eglport/$(am__dirstamp)
	-rm -f libwebm/$(DEPDIR)/$(am__dirstamp)
	-rm -f libwebm/$(am__dirstamp)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-binPROGRAMS clean-generic mostlyclean-am

distclean: distclean-am
		-rm -f ../CommonCode/$(DEPDIR)/utf8.Po
	-rm -f ./$(DEPDIR)/backdrop.Po
	-rm -f ./$(DEPDIR)/bg_effects.Po
	-rm -f ./$(DEPDIR)/builtin.Po
	-rm -f ./$(DEPDIR)/cursors.Po
	-rm -f ./$(DEPDIR)/debug.Po
	-rm -f ./$(DEPDIR)/fileset.Po
	-rm -f ./$(DEPDIR)/floor.Po
	-rm -f ./$(DEPDIR)/fonttext.Po
	-rm -f ./$(DEPDIR)/freeze.Po
	-rm -f ./$(DEPDIR)/graphics.Po
	-rm -f ./$(DEPDIR)/helpers.Po
	-rm -f ./$(DEPDIR)/language.Po
	-rm -f ./$(DEPDIR)/line.Po
	-rm -f ./$(DEPDIR)/linuxstuff.Po
	-rm -f ./$(DEPDIR)/loadsave.Po
	-rm -f ./$(DEPDIR)/main.Po
	-rm -f ./$(DEPDIR)/memwatch.Po
	-rm -f ./$(DEPDIR)/moreio.Po
	-rm -f ./$(DEPDIR)/movie.Po
	-rm -f ./$(DEPDIR)/newfatal.Po
	-rm -f ./$(DEPDIR)/objtypes.Po
	-rm -f ./$(DEPDIR)/people.Po
	-rm -f ./$(DEPDIR)/region.Po
	-rm -f ./$(DEPDIR)/savedata.Po
	-rm -f ./$(DEPDIR)/shaders.Po
	-rm -f ./$(DEPDIR)/sludger.Po
	-rm -f ./$(DEPDIR)/sound_openal.Po
	-rm -f ./$(DEPDIR)/sprbanks.Po
	-rm -f ./$(DEPDIR)/sprites.Po
	-rm -f ./$(DEPDIR)/statusba.Po
	-rm -f ./$(DEPDIR)/stringy.Po
	-rm -f ./$(DEPDIR)/talk.Po
	-rm -f ./$(DEPDIR)/thumbnail.Po
	-rm -f ./$(DEPDIR)/timing.Po
	-rm -f ./$(DEPDIR)/transition.Po
	-rm -f ./$(DEPDIR)/variable.Po
	-rm -f ./$(DEPDIR)/zbuffer.Po
	-rm -f eglport/$(DEPDIR)/eglport.Po
	-rm -f libwebm/$(DEPDIR)/mkvparser.Po
	-rm -f libwebm/$(DEPDIR)/mkvreader.Po
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-dist_pkgdataDATA

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-binPROGRAMS

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
		-rm -f ../CommonCode/$(DEPDIR)/utf8.Po
	-rm -f ./$(DEPDIR)/backdrop.Po
	-rm -f ./$(DEPDIR)/bg_effects.Po
	-rm -f ./$(DEPDIR)/builtin.Po
	-rm -f ./$(DEPDIR)/cursors.Po
	-rm -f ./$(DEPDIR)/debug.Po
	-rm -f ./$(DEPDIR)/fileset.Po
	-rm -f ./$(DEPDIR)/floor.Po
	-rm -f ./$(DEPDIR)/fonttext.Po
	-rm -f ./$(DEPDIR)/freeze.Po
	-rm -f ./$(DEPDIR)/graphics.Po
	-rm -f ./$(DEPDIR)/helpers.Po
	-rm -f ./$(DEPDIR)/language.Po
	-rm -f ./$(DEPDIR)/line.Po
	-rm -f ./$(DEPDIR)/linuxstuff.Po
	-rm -f ./$(DEPDIR)/loadsave.Po
	-rm -f ./$(DEPDIR)/main.Po
	-rm -f ./$(DEPDIR)/memwatch.Po
	-rm -f ./$(DEPDIR)/moreio.Po
	-rm -f ./$(DEPDIR)/movie.Po
	-rm -f ./$(DEPDIR)/newfatal.Po
	-rm -f ./$(DEPDIR)/objtypes.Po
	-rm -f ./$(DEPDIR)/people.Po
	-rm -f ./$(DEPDIR)/region.Po
	-rm -f ./$(DEPDIR)/savedata.Po
	-rm -f ./$(DEPDIR)/shaders.Po
	-rm -f ./$(DEPDIR)/sludger.Po
	-rm -f ./$(DEPDIR)/sound_openal.Po
	-rm -f ./$(DEPDIR)/sprbanks.Po
	-rm -f ./$(DEPDIR)/sprites.Po
	-rm -f ./$(DEPDIR)/statusba.Po
	-rm -f ./$(DEPDIR)/stringy.Po
	-rm -f ./$(DEPDIR)/talk.Po
	-rm -f ./$(DEPDIR)/thumbnail.Po
	-rm -f ./$(DEPDIR)/timing.Po
	-rm -f ./$(DEPDIR)/transition.Po
	-rm -f ./$(DEPDIR)/variable.Po
	-rm -f ./$(DEPDIR)/zbuffer.Po
	-rm -f eglport/$(DEPDIR)/eglport.Po
	-rm -f libwebm/$(DEPDIR)/mkvparser.Po
	-rm -f libwebm/$(DEPDIR)/mkvreader.Po
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-binPROGRAMS uninstall-dist_pkgdataDATA

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am am--depfiles check check-am clean \
	clean-binPROGRAMS clean-generic cscopelist-am ctags ctags-am \
	distclean distclean-compile distclean-generic distclean-tags \
	distdir dvi dvi-am html html-am info info-am install \
	install-am install-binPROGRAMS install-data install-data-am \
	install-dist_pkgdataDATA install-dvi install-dvi-am \
	install-exec install-exec-am install-html install-html-am \
	install-info install-info-am install-man install-pdf \
	install-pdf-am install-ps install-ps-am install-strip \
	installcheck installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic pdf pdf-am ps ps-am tags tags-am uninstall \
	uninstall-am uninstall-binPROGRAMS uninstall-dist_pkgdataDATA

.PRECIOUS: Makefile


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
