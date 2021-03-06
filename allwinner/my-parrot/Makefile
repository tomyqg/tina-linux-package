##############################################
# OpenWrt Makefile for smartlinkd program
#
#
# Most of the variables used here are defined in
# the include directives below. We just need to
# specify a basic description of the package,
# where to build our program, where to find
# the source files, and where to install the
# compiled program on the router.
#
# Be very careful of spacing in this file.
# Indents should be tabs, not spaces, and
# there should be no trailing whitespace in
# lines that are not commented.
#
##############################################
include $(TOPDIR)/rules.mk
include $(BUILD_DIR)/package.mk

# Name and release number of this package
PKG_NAME:=my-parrot
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(COMPILE_DIR)/$(PKG_NAME)
HAVE_SOURCE := yes

define Package/$(PKG_NAME)/Default
  SECTION:=utils
  CATEGORY:=Allwinner
  DEPENDS:=+libpthread \
		   +libstdcpp \
		   +libev \
		   +libcurl \
		   +libjson-c \
		   +liballwinner-base \
		   +liballwinner \
		   +wifimanager \
		   +smartlinkd \
		   +tinymp3 \
		   +bluetooth

endef

define Package/$(PKG_NAME)
  $(call Package/$(PKG_NAME)/Default)
  TITLE:=my tina parrot
endef

define Package/$(PKG_NAME)/description
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)/
	$(CP) -r ./src $(PKG_BUILD_DIR)/
endef

define Build/Configure
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/src \
		MAKE="$(MAKE)" \
		ARCH="$(TARGET_ARCH)" \
		AR="$(TARGET_AR)" \
		CC="$(TARGET_CC)" \
		CXX="$(TARGET_CXX)" \
		CFLAGS="$(TARGET_CFLAGS)"\
		LDFLAGS="$(TARGET_LDFLAGS)" \
		CONFIG_PREFIX="$(PKG_INSTALL_DIR)" \
		all
	-unlink $(PKG_NAME)
	ln -s $(PKG_BUILD_DIR)

endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
endef

define Package/$(PKG_NAME)/install

	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/share/$(PKG_NAME)
	$(INSTALL_DIR) $(1)/usr/share/$(PKG_NAME)

	$(INSTALL_BIN) ./my-parrot.init $(1)/etc/init.d/my-parrot
	$(INSTALL_BIN) ./my-parrot-log.sh $(1)/usr/bin/

	$(INSTALL_DATA) ./media/*.mp3 $(1)/usr/share/$(PKG_NAME)
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/my-parrot $(1)/usr/bin

endef

$(eval $(call BuildPackage,$(PKG_NAME)))
