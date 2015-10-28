include ../Makefile.Conf

all:

static:

install:
	${MKDIR} ${datadir}/lxrad/icons
	${CP} -v icons/* ${datadir}/lxrad/icons
	${CP} -v ../README ../COPYING ../AUTHORS ../ChangeLog ${datadir}/lxrad/
	chmod 644 -R ${datadir}/lxrad/*
	chmod 644 -R ${datadir}/lxrad/icons/*
	chmod 755 ${datadir}/lxrad/icons

uninstall:
	${RM} -R ${datadir}/lxrad

clean:

