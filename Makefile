#############################################################################
# Makefile for building: TradingPlatform
# Generated by qmake (3.1) (Qt 5.12.8)
# Project:  TradingPlatform.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile TradingPlatform.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = TradingPlatform1.0.0
DISTDIR = /home/mugi/TradingPlatform/.tmp/TradingPlatform1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = adminWindow.cpp \
		calculator.cpp \
		calculatorWindow.cpp \
		charge.cpp \
		chargeManager.cpp \
		commodity.cpp \
		commodityManager.cpp \
		commodityModifyWidget.cpp \
		expressionGenerator.cpp \
		instructionDecoder.cpp \
		instructionGenerator.cpp \
		login.cpp \
		main.cpp \
		message.cpp \
		messageManager.cpp \
		newCommodityWidget.cpp \
		order.cpp \
		orderManager.cpp \
		registerWindow.cpp \
		user.cpp \
		userManager.cpp \
		userWindow.cpp moc_adminWindow.cpp \
		moc_calculatorWindow.cpp \
		moc_commodityModifyWidget.cpp \
		moc_login.cpp \
		moc_newCommodityWidget.cpp \
		moc_registerWindow.cpp \
		moc_userWindow.cpp
OBJECTS       = adminWindow.o \
		calculator.o \
		calculatorWindow.o \
		charge.o \
		chargeManager.o \
		commodity.o \
		commodityManager.o \
		commodityModifyWidget.o \
		expressionGenerator.o \
		instructionDecoder.o \
		instructionGenerator.o \
		login.o \
		main.o \
		message.o \
		messageManager.o \
		newCommodityWidget.o \
		order.o \
		orderManager.o \
		registerWindow.o \
		user.o \
		userManager.o \
		userWindow.o \
		moc_adminWindow.o \
		moc_calculatorWindow.o \
		moc_commodityModifyWidget.o \
		moc_login.o \
		moc_newCommodityWidget.o \
		moc_registerWindow.o \
		moc_userWindow.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		TradingPlatform.pro adminWindow.h \
		calculator.h \
		calculatorWindow.h \
		charge.h \
		chargeManager.h \
		commodity.h \
		commodityManager.h \
		commodityModifyWidget.h \
		expressionGenerator.h \
		instructionDecoder.h \
		instructionGenerator.h \
		login.h \
		message.h \
		messageManager.h \
		newCommodityWidget.h \
		order.h \
		orderManager.h \
		registerWindow.h \
		ui_adminWindow.h \
		ui_calculatorWindow.h \
		ui_commodityModifyWidget.h \
		ui_login.h \
		ui_newCommodityWidget.h \
		ui_registerWindow.h \
		ui_userWindow.h \
		user.h \
		userManager.h \
		userWindow.h adminWindow.cpp \
		calculator.cpp \
		calculatorWindow.cpp \
		charge.cpp \
		chargeManager.cpp \
		commodity.cpp \
		commodityManager.cpp \
		commodityModifyWidget.cpp \
		expressionGenerator.cpp \
		instructionDecoder.cpp \
		instructionGenerator.cpp \
		login.cpp \
		main.cpp \
		message.cpp \
		messageManager.cpp \
		newCommodityWidget.cpp \
		order.cpp \
		orderManager.cpp \
		registerWindow.cpp \
		user.cpp \
		userManager.cpp \
		userWindow.cpp
QMAKE_TARGET  = TradingPlatform
DESTDIR       = 
TARGET        = TradingPlatform


first: all
####### Build rules

TradingPlatform: ui_adminWindow.h ui_calculatorWindow.h ui_commodityModifyWidget.h ui_login.h ui_newCommodityWidget.h ui_registerWindow.h ui_userWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: TradingPlatform.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		TradingPlatform.pro
	$(QMAKE) -o Makefile TradingPlatform.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
TradingPlatform.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile TradingPlatform.pro

qmake_all: FORCE


all: Makefile TradingPlatform

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents adminWindow.h calculator.h calculatorWindow.h charge.h chargeManager.h commodity.h commodityManager.h commodityModifyWidget.h expressionGenerator.h instructionDecoder.h instructionGenerator.h login.h message.h messageManager.h newCommodityWidget.h order.h orderManager.h registerWindow.h ui_adminWindow.h ui_calculatorWindow.h ui_commodityModifyWidget.h ui_login.h ui_newCommodityWidget.h ui_registerWindow.h ui_userWindow.h user.h userManager.h userWindow.h $(DISTDIR)/
	$(COPY_FILE) --parents adminWindow.cpp calculator.cpp calculatorWindow.cpp charge.cpp chargeManager.cpp commodity.cpp commodityManager.cpp commodityModifyWidget.cpp expressionGenerator.cpp instructionDecoder.cpp instructionGenerator.cpp login.cpp main.cpp message.cpp messageManager.cpp newCommodityWidget.cpp order.cpp orderManager.cpp registerWindow.cpp user.cpp userManager.cpp userWindow.cpp $(DISTDIR)/
	$(COPY_FILE) --parents adminWindow.ui calculatorWindow.ui commodityModifyWidget.ui login.ui newCommodityWidget.ui registerWindow.ui userWindow.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_adminWindow.cpp moc_calculatorWindow.cpp moc_commodityModifyWidget.cpp moc_login.cpp moc_newCommodityWidget.cpp moc_registerWindow.cpp moc_userWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_adminWindow.cpp moc_calculatorWindow.cpp moc_commodityModifyWidget.cpp moc_login.cpp moc_newCommodityWidget.cpp moc_registerWindow.cpp moc_userWindow.cpp
moc_adminWindow.cpp: adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include adminWindow.h -o moc_adminWindow.cpp

moc_calculatorWindow.cpp: calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include calculatorWindow.h -o moc_calculatorWindow.cpp

moc_commodityModifyWidget.cpp: commodityModifyWidget.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		ui_commodityModifyWidget.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include commodityModifyWidget.h -o moc_commodityModifyWidget.cpp

moc_login.cpp: login.h \
		ui_login.h \
		adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		registerWindow.h \
		ui_registerWindow.h \
		calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		userWindow.h \
		ui_userWindow.h \
		login.h \
		commodityModifyWidget.h \
		ui_commodityModifyWidget.h \
		newCommodityWidget.h \
		ui_newCommodityWidget.h \
		expressionGenerator.h \
		chargeManager.h \
		charge.h \
		messageManager.h \
		message.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include login.h -o moc_login.cpp

moc_newCommodityWidget.cpp: newCommodityWidget.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		ui_newCommodityWidget.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include newCommodityWidget.h -o moc_newCommodityWidget.cpp

moc_registerWindow.cpp: registerWindow.h \
		userManager.h \
		user.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		ui_registerWindow.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include registerWindow.h -o moc_registerWindow.cpp

moc_userWindow.cpp: userWindow.h \
		ui_userWindow.h \
		login.h \
		ui_login.h \
		adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		registerWindow.h \
		ui_registerWindow.h \
		calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		userWindow.h \
		commodityModifyWidget.h \
		ui_commodityModifyWidget.h \
		newCommodityWidget.h \
		ui_newCommodityWidget.h \
		expressionGenerator.h \
		chargeManager.h \
		charge.h \
		messageManager.h \
		message.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/mugi/TradingPlatform/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/mugi/TradingPlatform -I/home/mugi/TradingPlatform -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include userWindow.h -o moc_userWindow.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_adminWindow.h ui_calculatorWindow.h ui_commodityModifyWidget.h ui_login.h ui_newCommodityWidget.h ui_registerWindow.h ui_userWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_adminWindow.h ui_calculatorWindow.h ui_commodityModifyWidget.h ui_login.h ui_newCommodityWidget.h ui_registerWindow.h ui_userWindow.h
ui_adminWindow.h: adminWindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic adminWindow.ui -o ui_adminWindow.h

ui_calculatorWindow.h: calculatorWindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic calculatorWindow.ui -o ui_calculatorWindow.h

ui_commodityModifyWidget.h: commodityModifyWidget.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic commodityModifyWidget.ui -o ui_commodityModifyWidget.h

ui_login.h: login.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic login.ui -o ui_login.h

ui_newCommodityWidget.h: newCommodityWidget.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic newCommodityWidget.ui -o ui_newCommodityWidget.h

ui_registerWindow.h: registerWindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic registerWindow.ui -o ui_registerWindow.h

ui_userWindow.h: userWindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic userWindow.ui -o ui_userWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

adminWindow.o: adminWindow.cpp adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o adminWindow.o adminWindow.cpp

calculator.o: calculator.cpp calculator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculator.o calculator.cpp

calculatorWindow.o: calculatorWindow.cpp calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculatorWindow.o calculatorWindow.cpp

charge.o: charge.cpp charge.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o charge.o charge.cpp

chargeManager.o: chargeManager.cpp chargeManager.h \
		charge.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o chargeManager.o chargeManager.cpp

commodity.o: commodity.cpp commodity.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commodity.o commodity.cpp

commodityManager.o: commodityManager.cpp commodityManager.h \
		commodity.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commodityManager.o commodityManager.cpp

commodityModifyWidget.o: commodityModifyWidget.cpp commodityModifyWidget.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		ui_commodityModifyWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commodityModifyWidget.o commodityModifyWidget.cpp

expressionGenerator.o: expressionGenerator.cpp expressionGenerator.h \
		orderManager.h \
		order.h \
		chargeManager.h \
		charge.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressionGenerator.o expressionGenerator.cpp

instructionDecoder.o: instructionDecoder.cpp instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o instructionDecoder.o instructionDecoder.cpp

instructionGenerator.o: instructionGenerator.cpp instructionGenerator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o instructionGenerator.o instructionGenerator.cpp

login.o: login.cpp login.h \
		ui_login.h \
		adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		registerWindow.h \
		ui_registerWindow.h \
		calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		userWindow.h \
		ui_userWindow.h \
		commodityModifyWidget.h \
		ui_commodityModifyWidget.h \
		newCommodityWidget.h \
		ui_newCommodityWidget.h \
		expressionGenerator.h \
		chargeManager.h \
		charge.h \
		messageManager.h \
		message.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o login.o login.cpp

main.o: main.cpp login.h \
		ui_login.h \
		adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		registerWindow.h \
		ui_registerWindow.h \
		calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		userWindow.h \
		ui_userWindow.h \
		commodityModifyWidget.h \
		ui_commodityModifyWidget.h \
		newCommodityWidget.h \
		ui_newCommodityWidget.h \
		expressionGenerator.h \
		chargeManager.h \
		charge.h \
		messageManager.h \
		message.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

message.o: message.cpp message.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o message.o message.cpp

messageManager.o: messageManager.cpp messageManager.h \
		message.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o messageManager.o messageManager.cpp

newCommodityWidget.o: newCommodityWidget.cpp newCommodityWidget.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		ui_newCommodityWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newCommodityWidget.o newCommodityWidget.cpp

order.o: order.cpp order.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o order.o order.cpp

orderManager.o: orderManager.cpp orderManager.h \
		order.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o orderManager.o orderManager.cpp

registerWindow.o: registerWindow.cpp registerWindow.h \
		userManager.h \
		user.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		ui_registerWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o registerWindow.o registerWindow.cpp

user.o: user.cpp user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o user.o user.cpp

userManager.o: userManager.cpp userManager.h \
		user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o userManager.o userManager.cpp

userWindow.o: userWindow.cpp userWindow.h \
		ui_userWindow.h \
		login.h \
		ui_login.h \
		adminWindow.h \
		ui_adminWindow.h \
		instructionGenerator.h \
		instructionDecoder.h \
		commodityManager.h \
		commodity.h \
		orderManager.h \
		order.h \
		userManager.h \
		user.h \
		registerWindow.h \
		ui_registerWindow.h \
		calculatorWindow.h \
		ui_calculatorWindow.h \
		calculator.h \
		commodityModifyWidget.h \
		ui_commodityModifyWidget.h \
		newCommodityWidget.h \
		ui_newCommodityWidget.h \
		expressionGenerator.h \
		chargeManager.h \
		charge.h \
		messageManager.h \
		message.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o userWindow.o userWindow.cpp

moc_adminWindow.o: moc_adminWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_adminWindow.o moc_adminWindow.cpp

moc_calculatorWindow.o: moc_calculatorWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_calculatorWindow.o moc_calculatorWindow.cpp

moc_commodityModifyWidget.o: moc_commodityModifyWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_commodityModifyWidget.o moc_commodityModifyWidget.cpp

moc_login.o: moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_login.o moc_login.cpp

moc_newCommodityWidget.o: moc_newCommodityWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newCommodityWidget.o moc_newCommodityWidget.cpp

moc_registerWindow.o: moc_registerWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_registerWindow.o moc_registerWindow.cpp

moc_userWindow.o: moc_userWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_userWindow.o moc_userWindow.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

