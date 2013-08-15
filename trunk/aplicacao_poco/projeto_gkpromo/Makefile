#
# Makefile
#
# $Id: //poco/1.3/Net/samples/HTTPTimeServer/Makefile#1 $
#
# Makefile for Poco HTTPTimeServer
#

PROJECT_BASE=.
POCO_BASE=/usr/local/poco

include $(POCO_BASE)/build/rules/global

SYSLIBS += -L/usr/local/lib/mysql -lmysqlclient 
INCLUDE += -I$(POCO_BASE)/Data/MySQL/include -I/usr/local/include/mysql

objects = GkPromoServer GkUrls GkSeries GkHandler GkDadosPromocao

target         = GkPromoServer
target_version = 1
target_libs    = PocoUtil PocoNet PocoXML PocoFoundation PocoMySQL PocoData

include $(POCO_BASE)/build/rules/exec
