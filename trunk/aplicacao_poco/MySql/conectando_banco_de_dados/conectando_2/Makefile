#
# Makefile for GkCarrier based on Poco
#
#


PROJECT_BASE=.
POCO_BASE=/usr/local/poco

include $(POCO_BASE)/build/rules/global

SYSLIBS += -L/usr/local/lib/mysql -lmysqlclient 
INCLUDE += -I$(POCO_BASE)/Data/MySQL/include -I/usr/include/mysql

objects = conexao

target         = conexao
target_version = 1
target_libs    = PocoMySQL PocoData PocoUtil PocoNet PocoXML PocoFoundation

include $(POCO_BASE)/build/rules/exec


