## Makefile.am for kerp

# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = kerp kerp_client

# set the include path for X, qt and KDE
INCLUDES         = $(all_includes)

# the library search path. 
kerp_LDFLAGS = $(KDE_RPATH) $(all_libraries)

# the libraries to link against.
kerp_LDADD   = $(LIB_KFILE) $(LIB_KDEPRINT)

# which sources should be compiled for kerp
kerp_SOURCES = main.cpp kerp.cpp kerpview.cpp pref.cpp kerpiface.skel formcity.ui invoiceview.ui test.ui Invoice.h Invoice.cpp invoicecontrol.cpp invoicecontrol.h

# these are the headers for your project
noinst_HEADERS = kerp.h kerpview.h pref.h

# client stuff
kerp_client_LDFLAGS = $(KDE_RPATH) $(all_libraries)
kerp_client_LDADD   = $(LIB_KDECORE)
kerp_client_SOURCES = kerp_client.cpp

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kerp.pot

KDE_ICON = kerp

# this is where the kdelnk file will go 
kdelnkdir   = $(kde_appsdir)/Utilities
kdelnk_DATA = kerp.desktop

# this is where the XML-GUI resource file goes
rcdir = $(kde_datadir)/kerp
rc_DATA = kerpui.rc
