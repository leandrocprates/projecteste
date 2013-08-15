#
# Makefile for gerar_log based on Poco
#
#


PROJECT_BASE=.

include $(POCO_BASE)/build/rules/global

#SYSLIBS += -L/usr/local/lib/mysql -lmysqlclient -L${HOME}/okto/lib 
INCLUDE += -I$(POCO_BASE)Foundation/include/Poco

objects = gera_log

target         = gera_log
target_version = 1
target_libs    = PocoFoundation

include $(POCO_BASE)/build/rules/exec


