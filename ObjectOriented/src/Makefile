##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Sun Nov  8 22:58:50 2009
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f
CC= g++
DEFS=
PROGNAME= iitmdatabase
INCLUDES=  -I.
LIBS=


DEFINES= $(INCLUDES) $(DEFS) -DSYS_UNIX=1
CFLAGS= -g $(DEFINES)

SRCS = admin.cpp course.cpp coursewrapper.cpp faculty.cpp financeWrapper.cpp iitm.cpp main.cpp person.cpp staff.cpp student.cpp utils.cpp 

OBJS = admin.o course.o coursewrapper.o faculty.o financeWrapper.o iitm.o main.o person.o staff.o student.o utils.o 

.c.o:
	$(rm) $@
	$(CC) $(CFLAGS) -c $*.c

all: $(PROGNAME)
	mv *.o ../obj/
	mv iitmdatabase ../bin/

$(PROGNAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)

clean:
	$(rm) $(OBJS) $(PROGNAME) core *~
