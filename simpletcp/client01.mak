###################################################################################
PRGOBJS = \
	client01.o \

PRGTARG = \
	client01

PRGLIBS =

PRGDEFS =

###################################################################################
CC	= cc
RM	= rm -f
ECHO	= @echo

DBFLG   = -g
OPFLG   = -O3
MODE	= $(OPFLG) 
MODE	= $(DBFLG) 

EXTARG	= ./$(PRGTARG)

INCPS	= -I/usr/include -I.
LIBPS	= -L/usr/lib
UXLIBS  = -lm -lc

CCFLGS	= $(CCFLG) $(DEFS) $(OSDEF) $(BITDEF) $(INCPS) $(LIBPS)

all: $(EXTARG)

$(EXTARG): $(PRGOBJS)
	$(ECHO) "Linking  [$(EXTARG)] ......"
	$(CC) -o $@ $(CCFLGS) $(PRGOBJS) $(PRGLIBS) $(UXLIBS)
	$(ECHO) "Program [$(PRGTARG)] BUILD OK..."

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(ECHO) "Compiling [$@] ......"
	$(CC) -o $@ $(MODE) $(CCFLGS) -c $<

clean: cleanup
	@$(RM) $(EXTARG)

cleanup:
	@$(RM) $(PRGOBJS)
###################################################################################
