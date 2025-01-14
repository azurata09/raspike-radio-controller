APPL_COBJS +=

APPL_CXXOBJS += Driver.o Receiver.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile

endif
