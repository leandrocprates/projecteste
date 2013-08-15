
PROJECT_BASE=.

include $(POCO_BASE)/build/rules/global # global rules: will find libs and include files for us

SHAREDOPT_CXX += -DWITH_NONAMESPACES 
DEBUGOPT_CXX += -g3 -gdwarf-2

objects = aplicacao_poco
target     = aplicacao_poco
target_version = 1
target_libs = PocoFoundation
include $(POCO_BASE)/build/rules/exec #tells the Makefile we want to build an executable

