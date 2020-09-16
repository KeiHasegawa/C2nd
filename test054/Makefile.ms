TESTS = $(wildcard *.data)
LOFS = $(TESTS:.data=.lof)

SRCS = getch.c getop.c main.c stack.c
ASMS = $(SRCS:.c=.asm)

all:ok.log

DIFF = diff
TOUCH = touch
DOGV = wdog.exe -v
DOS2UNIX = dos2unix.csh

CPP=hcpp.exe
ifeq ($(INTEL_DLL_EXTRA_OPTION),--x86)
CPP_FLAG = -D_MSC_VER \
-D_M_IX86 \
-DWIN32 \
-U_WIN64 \
-D__int64='long long' \
-D__cdecl= \
-D__pragma='\#pragma' \
-D_Bool=int \
-D__declspec\(a\)= \
-D__inline=inline \
-D__fastcall= \
-Dmain=_test_main \
-W 0 $(EXTRA_CPP_FLAG)
else
CPP_FLAG = -D_MSC_VER \
-U_M_IX86 \
-D_M_X64 \
-D_WIN64 \
-D__int64='long long' \
-D__cdecl= \
-D__pragma='\#pragma' \
-D_Bool=int \
-D__declspec\(a\)= \
-D__inline=inline \
-Dmain=_test_main \
-W 0 $(EXTRA_CPP_FLAG)
endif

CC1 = hcc1.exe
ifeq ($(INTEL_DLL_EXTRA_OPTION),--x86)
CC1_FLAG = --generator-option \( --debug --ms --x86 \)
else
CC1_FLAG = --generator-option \( --debug --ms \)
endif

ifeq ($(INTEL_DLL_EXTRA_OPTION),--x86)
calc.exe:$(ASMS)
	$(DOGV) MSBuild.exe '/p:Configuration=Debug;Platform=x86' /t:Rebuild
	mv x64/Debug/calc.exe .
else
calc.exe:$(ASMS)
	$(DOGV) MSBuild.exe '/p:Configuration=Debug;Platform=x64' /t:Rebuild
	mv x64/Debug/calc.exe .
endif

%.i : %.c
	$(DOGV) $(CPP) $(CPP_FLAG) $< | vs_header_conv.pl > $@

%.asm : %.i
	$(DOGV) $(CC1) -o $@ $< $(CC1_FLAG)

%.log:%.data
	$(DOGV) ./calc.exe < $< > $@
	$(DOGV) $(DOS2UNIX) $@

%.lof : %.log
	$(DOGV) $(DIFF) $< $@
	$(TOUCH) $@

ok.log:$(LOFS)
	ls $(LOFS) > $@
	$(DOS2UNIX) $@
	$(TOUCH) $@

clean:
	$(RM) *.log *.exe *.s *.asm *.i *.stackdump core.* a.out core *~
	$(RM) -r .vs x64 Debug Release

getch.asm:getch.i
getop.asm:getop.i
main.asm:main.i
stack.asm:stack.i

test000.lof:test000.log
test000.log:calc.exe
test001.lof:test001.log
test001.log:calc.exe
test002.lof:test002.log
test002.log:calc.exe
test003.lof:test003.log
test003.log:calc.exe
test004.lof:test004.log
test004.log:calc.exe
test005.lof:test005.log
test005.log:calc.exe
test006.lof:test006.log
test006.log:calc.exe
