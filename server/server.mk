SERVER_OBJ = \
    server.o \
    monitor.o \
    process.o \
    util/debug.o \
    util/signal.o \
    util/become_daemon.o \
    util/memory.o \
    util/btreemap.o \
    util/service_helpers.o \
    confdb/confdb.o \
    nss/nsssrv.o \
    nss/nsssrv_packet.o \
    nss/nsssrv_cmd.o \
    nss/nsssrv_ldb.o \
    sbus/sssd_dbus_common.o \
    sbus/sssd_dbus_connection.o \
    sbus/sssd_dbus_server.o \
	providers/data_provider.o

CLIENT_OBJ = \
    sbus/sssd_dbus_common.o \
    sbus/sssd_dbus_connection.o \
    util/debug.o

install:: all
	${INSTALLCMD} -d $(DESTDIR)$(sbindir)
	${INSTALLCMD} -m 755 sssd $(DESTDIR)$(sbindir)

sbin/sssd: $(SERVER_OBJ)
	$(CC) -o sbin/sssd $(SERVER_OBJ) $(LDFLAGS) $(LIBS)
