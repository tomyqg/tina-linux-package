target			= libwifimg.so

INCLUDES        += -I. -I./include
LIBS            += -lpthread -ldl

SRCS =wifimanager.c wifi_event.c wifi_state_machine.c network_manager.c \
      wifi.c wpa_supplicant_conf.c udhcpc_thread.c

install:
	-@mkdir -p $(CONFIG_PREFIX)/usr/lib
	-@mkdir -p $(CONFIG_PREFIX)/usr/include
	@cp ./include/wifi_intf.h $(CONFIG_PREFIX)/usr/include

#libwifimg.so
$(target): $(SRCS) libwpa_client.a
	$(CC) -fPIC -shared $(INCLUDES) $(LDFLAGS) $^ -o $@ $(LIBS)
	@cp $@ $(CONFIG_PREFIX)/usr/lib

####################################################################
all: install $(target)
clean:
	rm -rf $(target)
