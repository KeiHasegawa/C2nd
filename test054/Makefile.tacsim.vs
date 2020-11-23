TESTS = $(wildcard *.data)
LOFS = $(TESTS:.data=.lof)
CPP = hcpp.exe
ifeq ($(BATCH_BUILD_VS_X86),1)
CPP_FLAG = \
$(EXTRA_CPP_FLAG_TACSIM_VS) \
-D_MSC_VER \
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
-W 0
else
CPP_FLAG = \
$(EXTRA_CPP_FLAG_TACSIM_VS) \
-D_MSC_VER \
-U_M_IX86 \
-D_M_X64 \
-D_WIN64 \
-D__int64='long long' \
-D__cdecl= \
-D__pragma='\#pragma' \
-D_Bool=int \
-D__declspec\(a\)= \
-D__inline=inline \
-W 0
endif

CC1 = hcc1.exe
CC1_FLAG =
DIFF = diff
DOS2UNIX = dos2unix.csh
TOUCH = touch
DOGV = wdog.exe -v

SRCS = getch.c getop.c main.c stack.c

all:ok.log

a.c:$(SRCS)
	cat $(SRCS) > $@

%.i : %.c
	$(DOGV) $(CPP) $(CPP_FLAG) $< | vs_header_conv.pl > $@

%.log:%.data
	$(DOGV) $(CC1) $(CC1_FLAG) a.i < $< > $@
	$(DOGV) $(DOS2UNIX) $@

%.lof:%.log
	$(DOGV) $(DIFF) $< $@
	$(TOUCH) $@

ok.log:$(LOFS)
	ls $(LOFS) > $@
	$(DOS2UNIX) $@
	$(TOUCH) $@

clean:
	$(RM) *.i *.s *.asm *.exe *.log a.c *~
	$(RM) -r .vs x64 Debug Release

test000.lof:test000.log
test000.log:a.i
test001.lof:test001.log
test001.log:a.i
test002.lof:test002.log
test002.log:a.i
test003.lof:test003.log
test003.log:a.i
test004.lof:test004.log
test004.log:a.i
test005.lof:test005.log
test005.log:a.i
test006.lof:test006.log
test006.log:a.i
