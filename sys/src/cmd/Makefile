ARCH=`uname -m`
CROSS_COMPILE=$(ARCH)-ros-
CC	    := $(CROSS_COMPILE)gcc 
CPP	    := $(CROSS_COMPILE)g++
AS	    := $(CROSS_COMPILE)as
AR	    := $(CROSS_COMPILE)ar
LD	    := $(CROSS_COMPILE)ld
OBJCOPY	:= $(CROSS_COMPILE)objcopy
OBJDUMP	:= $(CROSS_COMPILE)objdump
NM	    := $(CROSS_COMPILE)nm
STRIP   := $(CROSS_COMPILE)strip
NOSTDINC_FLAGS += -nostdinc -isystem \
                  $(shell $(CC) -print-file-name=include 2>/dev/null)
CFLAGS+= $(NOSTDINC_FLAGS) -I $(AKAROS)/include -I ../../include -I ../../../$(ARCH)/include -O2 -std=gnu99 -fno-stack-protector -fgnu89-inline

cat: cat.c
