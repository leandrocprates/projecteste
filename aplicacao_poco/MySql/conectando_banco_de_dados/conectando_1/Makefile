#
# Makefile for GkCarrier based on Poco
#
#


PROJECT_BASE=.
POCO_BASE=/usr/local/poco

include $(POCO_BASE)/build/rules/global

SYSLIBS += -L/usr/lib -lmysqlclient -L/home/leandro/programa/libdebug -lDebug
INCLUDE += -I$(POCO_BASE)/Data/MySQL/include -I/usr/local/include/mysql -I/home/leandro/programa/libdebug 

objects = conexao

target         = conexao
target_version = 1
target_libs    = PocoMySQL PocoData PocoUtil PocoNet PocoXML PocoFoundation

include $(POCO_BASE)/build/rules/exec


