CONFIG = ../../makefile.config
include ${CONFIG}

INCLUDEDIRS := include
DEBUG := -g

GCCPARAMS := -m32 $(DEBUG) -I $(INCLUDEDIRS) $(OPTIMIZE_FLAGS) -Wall -fno-omit-frame-pointer -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-exceptions -fno-rtti -fno-leading-underscore -Wno-write-strings -fpermissive -Wno-unknown-pragmas
ASPARAMS := --32

SRCDIR := src
OBJDIR := obj

SRCFILES := $(shell find $(SRCDIR) -type f \( -name \*.cpp -o -name \*.s -o -name \*.asm \)) #Find all the files that end with .cpp/.s/.asm
OBJFILES := $(patsubst %.cpp,%.o,$(patsubst %.s,%.o,$(patsubst %.asm,%.o,$(SRCFILES)))) #Replace the .cpp/.s/.asm extension with .o
OBJFILES := $(subst $(SRCDIR),$(OBJDIR),$(OBJFILES)) #Replace the "src" part with "obj"


####################################
#C++ source files
####################################
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	i686-elf-g++ $(GCCPARAMS) -c -o $@ $<

####################################
#GAS assembly files
####################################
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	mkdir -p $(@D)
	i686-elf-as $(ASPARAMS) -o $@ $<

####################################
#NASM assembly files
####################################
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	mkdir -p $(@D)
	nasm -f elf32 -O0 $< -o $@

Novanix.a: $(OBJFILES)
	i686-elf-ar r Novanix.a $(OBJFILES)

.PHONY: clean filelist
clean:
	rm -rf $(OBJDIR) Novanix.a

filelist:
	@echo "Source Files:"
	@echo -$(SRCFILES)
	@echo "Object Files:"
	@echo -$(OBJFILES)
