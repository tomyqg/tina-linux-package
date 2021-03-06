include $(TOPDIR)/rules.mk
include $(BUILD_DIR)/kernel.mk

PKG_NAME:=libutils
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(COMPILE_DIR)/$(PKG_NAME)

include $(BUILD_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=utils
  CATEGORY:=Allwinner
  TITLE:=libutils from Android L
  DEPENDS:=+libstdcpp +libcutils
endef

define Package/$(PKG_NAME)/Default
endef

define Package/$(PKG_NAME)/description
  libutils form Android L
endef


define Build/Prepare
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/
	$(CP) ./src $(PKG_BUILD_DIR)/
endef

define Build/Configure
endef

ifeq ($(TARGET_BOARD_PLATFORM), azalea)
TARGET_CFLAGS   += -D__arm__
endif
ifeq ($(TARGET_BOARD_PLATFORM), kylin)
TARGET_CFLAGS   += -D__arm__
endif
ifeq ($(TARGET_BOARD_PLATFORM), astar)
TARGET_CFLAGS   += -D__arm__
endif
ifeq ($(TARGET_BOARD_PLATFORM), octopus)
TARGET_CFLAGS   += -D__arm__
endif
ifeq ($(TARGET_BOARD_PLATFORM), tulip)
TARGET_CFLAGS   += -D__aarch64__
endif

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/src\
		ARCH="$(TARGET_ARCH)" \
		AR="$(TARGET_AR)" \
		CC="$(TARGET_CC)" \
		CXX="$(TARGET_CXX)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
		INSTALL_PREFIX="$(PKG_INSTALL_DIR)" \
		all
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include

	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
