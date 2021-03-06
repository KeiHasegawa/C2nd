TESTS = $(wildcard *.c)
LOFS = $(TESTS:.c=.lof)
DIFF = diff
TOUCH = touch
DOS2UNIX = dos2unix.csh

all:$(LOFS) test054/ok.log

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
LINK_CMD = vs_wrapper
LINK_CMD2 = $(LINK_CMD)
RUN =

DOGV = wdog.exe -v

%.i : %.c
	$(DOGV) $(CPP) $(CPP_FLAG) $< | vs_header_conv.pl  > $@

%.asm : %.i
	$(DOGV) $(CC1) -o $@ $< $(CC1_FLAG)

%.exe : %.asm
	$(DOGV) $(LINK_CMD) -o $@ $<

%.log : %.exe
	$(DOGV) $(RUN) ./$< > $@
	$(DOS2UNIX) $@

%.lof : %.log
	$(DOGV) $(DIFF) $< $@
	$(TOUCH) $@

clean:
	$(RM) *.log *.exe *.asm *.i *.stackdump core.* a.out core *~
	cd test054 ; make clean

test006.log:test006.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test006.lof:test006.log
	$(DOGV) $(DIFF) $< $(basename $<).c
	touch $@

test007.log:test007.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test007.lof:test007.log
	$(DOGV) $(DIFF) $< $(basename $<).c
	touch $@

test008.log:test008.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test009.log:test009.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test010.log:test010.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test011.log:test011.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test012.log:test012.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test016.log:test016.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test017.log:test017.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test041.log:test041.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test050.log:test050.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test052.log:test052.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test054/ok.log:
	cd test054 ; make all

test079.log:test079.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test094.log:test094.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test095.log:test095.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test102.exe:test102.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<
	
test102.log:test102.exe
	$(DOGV) $(RUN) ./$< aaa bbb ccc > $@
	$(DOS2UNIX) $@

test103.exe:test103.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test103.log:test103.exe
	$(DOGV) $(RUN) ./$< ddd eee fff > $@
	$(DOS2UNIX) $@

test104.exe:test103.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test104.log:test104.exe
	$(DOGV) $(RUN) ./$< ggg hhh iii > $@
	$(DOS2UNIX) $@

test105.exe:test105.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test105.log:test105.exe
	$(DOGV) $(RUN) ./$< int < $(basename $<).c > $@
	$(DOS2UNIX) $@

test106.exe:test106.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test106.log:test106.exe
	$(DOGV) $(RUN) ./$< -n int < $(basename $<).c > $@
	$(DOGV) $(RUN) ./$< -x -n = < $(basename $<).c >> $@
	$(DOS2UNIX) $@

test107.exe:test107.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test107.log:test107.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOGV) $(RUN) ./$< -n < $(basename $<).data >> $@
	$(DOS2UNIX) $@

test108.log:test108.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test109.log:test109.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test123.log:test123.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test124.log:test124.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test125.log:test125.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test126.log:test126.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test128.log:test128.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test135.log:test135.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test138.log:test138.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test139.log:test139.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).data > $@
	$(DOS2UNIX) $@

test140.exe:test140.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test140.log:test140.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOGV) $(RUN) ./$< test000.c test001.c test002.c >> $@
	-$(DOG) $(RUN) ./$< not_exist >> $@
	$(DOS2UNIX) $@

test141.exe:test141.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test141.log:test141.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOGV) $(RUN) ./$< test000.c test001.c test002.c >> $@
	-$(DOG) $(RUN) ./$< not_exist 2>> $@
	$(DOS2UNIX) $@

test142.log:test142.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test143.log:test143.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test144.log:test144.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test145.log:test145.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test146.log:test146.exe
	$(DOGV) $(RUN) ./$< < $(basename $<).c > $@
	$(DOS2UNIX) $@

test147.exe:test147.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test147.log:test147.exe
	$(DOGV) $(RUN) ./$< $(basename $<).c $@
	-$(DOG) $(RUN) ./$< $(basename $<).c 2>> $@
	$(DOS2UNIX) $@

test148.exe:test148.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test148.log:test148.exe
	$(DOGV) $(RUN) ./$< $(basename $<).c > $@
	$(DOS2UNIX) $@

test149.exe:test149.asm
	$(DOGV) $(LINK_CMD2) -o $@ $<

test149.log:test149.exe
	$(DOGV) $(RUN) ./$< 0 $(basename $<).c > $@
	$(DOGV) $(RUN) ./$< 1 <$(basename $<).c >> $@
	$(DOGV) $(RUN) ./$< 2 2>> $@
	$(DOS2UNIX) $@

test000.lof:test000.log
test000.exe:test000.asm
test000.asm:test000.i
test001.lof:test001.log
test001.exe:test001.asm
test001.asm:test001.i
test002.lof:test002.log
test002.exe:test002.asm
test002.asm:test002.i
test003.lof:test003.log
test003.exe:test003.asm
test003.asm:test003.i
test004.lof:test004.log
test004.exe:test004.asm
test004.asm:test004.i
test005.lof:test005.log
test005.exe:test005.asm
test005.asm:test005.i
test006.lof:test006.log
test006.exe:test006.asm
test006.asm:test006.i
test007.lof:test007.log
test007.exe:test007.asm
test007.asm:test007.i
test008.lof:test008.log
test008.exe:test008.asm
test008.asm:test008.i
test009.lof:test009.log
test009.exe:test009.asm
test009.asm:test009.i

test010.lof:test010.log
test010.exe:test010.asm
test010.asm:test010.i
test011.lof:test011.log
test011.exe:test011.asm
test011.asm:test011.i
test012.lof:test012.log
test012.exe:test012.asm
test012.asm:test012.i
test013.lof:test013.log
test013.exe:test013.asm
test013.asm:test013.i
test014.lof:test014.log
test014.exe:test014.asm
test014.asm:test014.i
test015.lof:test015.log
test015.exe:test015.asm
test015.asm:test015.i
test016.lof:test016.log
test016.exe:test016.asm
test016.asm:test016.i
test017.lof:test017.log
test017.exe:test017.asm
test017.asm:test017.i
test018.lof:test018.log
test018.exe:test018.asm
test018.asm:test018.i
test019.lof:test019.log
test019.exe:test019.asm
test019.asm:test019.i

test020.lof:test020.log
test020.exe:test020.asm
test020.asm:test020.i
test021.lof:test021.log
test021.exe:test021.asm
test021.asm:test021.i
test022.lof:test022.log
test022.exe:test022.asm
test022.asm:test022.i
test023.lof:test023.log
test023.exe:test023.asm
test023.asm:test023.i
test024.lof:test024.log
test024.exe:test024.asm
test024.asm:test024.i
test025.lof:test025.log
test025.exe:test025.asm
test025.asm:test025.i
test026.lof:test026.log
test026.exe:test026.asm
test026.asm:test026.i
test027.lof:test027.log
test027.exe:test027.asm
test027.asm:test027.i
test028.lof:test028.log
test028.exe:test028.asm
test028.asm:test028.i
test029.lof:test029.log
test029.exe:test029.asm
test029.asm:test029.i

test020.lof:test020.log
test020.exe:test020.asm
test020.asm:test020.i
test021.lof:test021.log
test021.exe:test021.asm
test021.asm:test021.i
test022.lof:test022.log
test022.exe:test022.asm
test022.asm:test022.i
test023.lof:test023.log
test023.exe:test023.asm
test023.asm:test023.i
test024.lof:test024.log
test024.exe:test024.asm
test024.asm:test024.i
test025.lof:test025.log
test025.exe:test025.asm
test025.asm:test025.i
test026.lof:test026.log
test026.exe:test026.asm
test026.asm:test026.i
test027.lof:test027.log
test027.exe:test027.asm
test027.asm:test027.i
test028.lof:test028.log
test028.exe:test028.asm
test028.asm:test028.i
test029.lof:test029.log
test029.exe:test029.asm
test029.asm:test029.i

test030.lof:test030.log
test030.exe:test030.asm
test030.asm:test030.i
test031.lof:test031.log
test031.exe:test031.asm
test031.asm:test031.i
test032.lof:test032.log
test032.exe:test032.asm
test032.asm:test032.i
test033.lof:test033.log
test033.exe:test033.asm
test033.asm:test033.i
test034.lof:test034.log
test034.exe:test034.asm
test034.asm:test034.i
test035.lof:test035.log
test035.exe:test035.asm
test035.asm:test035.i
test036.lof:test036.log
test036.exe:test036.asm
test036.asm:test036.i
test037.lof:test037.log
test037.exe:test037.asm
test037.asm:test037.i
test038.lof:test038.log
test038.exe:test038.asm
test038.asm:test038.i
test039.lof:test039.log
test039.exe:test039.asm
test039.asm:test039.i

test040.lof:test040.log
test040.exe:test040.asm
test040.asm:test040.i
test041.lof:test041.log
test041.exe:test041.asm
test041.asm:test041.i
test042.lof:test042.log
test042.exe:test042.asm
test042.asm:test042.i
test043.lof:test043.log
test043.exe:test043.asm
test043.asm:test043.i
test044.lof:test044.log
test044.exe:test044.asm
test044.asm:test044.i
test045.lof:test045.log
test045.exe:test045.asm
test045.asm:test045.i
test046.lof:test046.log
test046.exe:test046.asm
test046.asm:test046.i
test047.lof:test047.log
test047.exe:test047.asm
test047.asm:test047.i
test048.lof:test048.log
test048.exe:test048.asm
test048.asm:test048.i
test049.lof:test049.log
test049.exe:test049.asm
test049.asm:test049.i

test050.lof:test050.log
test050.exe:test050.asm
test050.asm:test050.i
test051.lof:test051.log
test051.exe:test051.asm
test051.asm:test051.i
test052.lof:test052.log
test052.exe:test052.asm
test052.asm:test052.i
test053.lof:test053.log
test053.exe:test053.asm
test053.asm:test053.i
test054.lof:test054.log
test054.exe:test054.asm
test054.asm:test054.i
test055.lof:test055.log
test055.exe:test055.asm
test055.asm:test055.i
test056.lof:test056.log
test056.exe:test056.asm
test056.asm:test056.i
test057.lof:test057.log
test057.exe:test057.asm
test057.asm:test057.i
test058.lof:test058.log
test058.exe:test058.asm
test058.asm:test058.i
test059.lof:test059.log
test059.exe:test059.asm
test059.asm:test059.i

test060.lof:test060.log
test060.exe:test060.asm
test060.asm:test060.i
test061.lof:test061.log
test061.exe:test061.asm
test061.asm:test061.i
test062.lof:test062.log
test062.exe:test062.asm
test062.asm:test062.i
test063.lof:test063.log
test063.exe:test063.asm
test063.asm:test063.i
test064.lof:test064.log
test064.exe:test064.asm
test064.asm:test064.i
test065.lof:test065.log
test065.exe:test065.asm
test065.asm:test065.i
test066.lof:test066.log
test066.exe:test066.asm
test066.asm:test066.i
test067.lof:test067.log
test067.exe:test067.asm
test067.asm:test067.i
test068.lof:test068.log
test068.exe:test068.asm
test068.asm:test068.i
test069.lof:test069.log
test069.exe:test069.asm
test069.asm:test069.i

test070.lof:test070.log
test070.exe:test070.asm
test070.asm:test070.i
test071.lof:test071.log
test071.exe:test071.asm
test071.asm:test071.i
test072.lof:test072.log
test072.exe:test072.asm
test072.asm:test072.i
test073.lof:test073.log
test073.exe:test073.asm
test073.asm:test073.i
test074.lof:test074.log
test074.exe:test074.asm
test074.asm:test074.i
test075.lof:test075.log
test075.exe:test075.asm
test075.asm:test075.i
test076.lof:test076.log
test076.exe:test076.asm
test076.asm:test076.i
test077.lof:test077.log
test077.exe:test077.asm
test077.asm:test077.i
test078.lof:test078.log
test078.exe:test078.asm
test078.asm:test078.i
test079.lof:test079.log
test079.exe:test079.asm
test079.asm:test079.i

test080.lof:test080.log
test080.exe:test080.asm
test080.asm:test080.i
test081.lof:test081.log
test081.exe:test081.asm
test081.asm:test081.i
test082.lof:test082.log
test082.exe:test082.asm
test082.asm:test082.i
test083.lof:test083.log
test083.exe:test083.asm
test083.asm:test083.i
test084.lof:test084.log
test084.exe:test084.asm
test084.asm:test084.i
test085.lof:test085.log
test085.exe:test085.asm
test085.asm:test085.i
test086.lof:test086.log
test086.exe:test086.asm
test086.asm:test086.i
test087.lof:test087.log
test087.exe:test087.asm
test087.asm:test087.i
test088.lof:test088.log
test088.exe:test088.asm
test088.asm:test088.i
test089.lof:test089.log
test089.exe:test089.asm
test089.asm:test089.i

test090.lof:test090.log
test090.exe:test090.asm
test090.asm:test090.i
test091.lof:test091.log
test091.exe:test091.asm
test091.asm:test091.i
test092.lof:test092.log
test092.exe:test092.asm
test092.asm:test092.i
test093.lof:test093.log
test093.exe:test093.asm
test093.asm:test093.i
test094.lof:test094.log
test094.exe:test094.asm
test094.asm:test094.i
test095.lof:test095.log
test095.exe:test095.asm
test095.asm:test095.i
test096.lof:test096.log
test096.exe:test096.asm
test096.asm:test096.i
test097.lof:test097.log
test097.exe:test097.asm
test097.asm:test097.i
test098.lof:test098.log
test098.exe:test098.asm
test098.asm:test098.i
test099.lof:test099.log
test099.exe:test099.asm
test099.asm:test099.i

test100.lof:test100.log
test100.exe:test100.asm
test100.asm:test100.i
test101.lof:test101.log
test101.exe:test101.asm
test101.asm:test101.i
test102.lof:test102.log
test102.exe:test102.asm
test102.asm:test102.i
test103.lof:test103.log
test103.exe:test103.asm
test103.asm:test103.i
test104.lof:test104.log
test104.exe:test104.asm
test104.asm:test104.i
test105.lof:test105.log
test105.exe:test105.asm
test105.asm:test105.i
test106.lof:test106.log
test106.exe:test106.asm
test106.asm:test106.i
test107.lof:test107.log
test107.exe:test107.asm
test107.asm:test107.i
test108.lof:test108.log
test108.exe:test108.asm
test108.asm:test108.i
test109.lof:test109.log
test109.exe:test109.asm
test109.asm:test109.i

test110.lof:test110.log
test110.exe:test110.asm
test110.asm:test110.i
test111.lof:test111.log
test111.exe:test111.asm
test111.asm:test111.i
test112.lof:test112.log
test112.exe:test112.asm
test112.asm:test112.i
test113.lof:test113.log
test113.exe:test113.asm
test113.asm:test113.i
test114.lof:test114.log
test114.exe:test114.asm
test114.asm:test114.i
test115.lof:test115.log
test115.exe:test115.asm
test115.asm:test115.i
test116.lof:test116.log
test116.exe:test116.asm
test116.asm:test116.i
test117.lof:test117.log
test117.exe:test117.asm
test117.asm:test117.i
test118.lof:test118.log
test118.exe:test118.asm
test118.asm:test118.i
test119.lof:test119.log
test119.exe:test119.asm
test119.asm:test119.i

test120.lof:test120.log
test120.exe:test120.asm
test120.asm:test120.i
test121.lof:test121.log
test121.exe:test121.asm
test121.asm:test121.i
test122.lof:test122.log
test122.exe:test122.asm
test122.asm:test122.i
test123.lof:test123.log
test123.exe:test123.asm
test123.asm:test123.i
test124.lof:test124.log
test124.exe:test124.asm
test124.asm:test124.i
test125.lof:test125.log
test125.exe:test125.asm
test125.asm:test125.i
test126.lof:test126.log
test126.exe:test126.asm
test126.asm:test126.i
test127.lof:test127.log
test127.exe:test127.asm
test127.asm:test127.i
test128.lof:test128.log
test128.exe:test128.asm
test128.asm:test128.i
test129.lof:test129.log
test129.exe:test129.asm
test129.asm:test129.i

test120.lof:test120.log
test120.exe:test120.asm
test120.asm:test120.i
test121.lof:test121.log
test121.exe:test121.asm
test121.asm:test121.i
test122.lof:test122.log
test122.exe:test122.asm
test122.asm:test122.i
test123.lof:test123.log
test123.exe:test123.asm
test123.asm:test123.i
test124.lof:test124.log
test124.exe:test124.asm
test124.asm:test124.i
test125.lof:test125.log
test125.exe:test125.asm
test125.asm:test125.i
test126.lof:test126.log
test126.exe:test126.asm
test126.asm:test126.i
test127.lof:test127.log
test127.exe:test127.asm
test127.asm:test127.i
test128.lof:test128.log
test128.exe:test128.asm
test128.asm:test128.i
test129.lof:test129.log
test129.exe:test129.asm
test129.asm:test129.i

test130.lof:test130.log
test130.exe:test130.asm
test130.asm:test130.i
test131.lof:test131.log
test131.exe:test131.asm
test131.asm:test131.i
test132.lof:test132.log
test132.exe:test132.asm
test132.asm:test132.i
test133.lof:test133.log
test133.exe:test133.asm
test133.asm:test133.i
test134.lof:test134.log
test134.exe:test134.asm
test134.asm:test134.i
test135.lof:test135.log
test135.exe:test135.asm
test135.asm:test135.i
test136.lof:test136.log
test136.exe:test136.asm
test136.asm:test136.i
test137.lof:test137.log
test137.exe:test137.asm
test137.asm:test137.i
test138.lof:test138.log
test138.exe:test138.asm
test138.asm:test138.i
test139.lof:test139.log
test139.exe:test139.asm
test139.asm:test139.i

test140.lof:test140.log
test140.exe:test140.asm
test140.asm:test140.i
test141.lof:test141.log
test141.exe:test141.asm
test141.asm:test141.i
test142.lof:test142.log
test142.exe:test142.asm
test142.asm:test142.i
test143.lof:test143.log
test143.exe:test143.asm
test143.asm:test143.i
test144.lof:test144.log
test144.exe:test144.asm
test144.asm:test144.i
test145.lof:test145.log
test145.exe:test145.asm
test145.asm:test145.i
test146.lof:test146.log
test146.exe:test146.asm
test146.asm:test146.i
test147.lof:test147.log
test147.exe:test147.asm
test147.asm:test147.i
test148.lof:test148.log
test148.exe:test148.asm
test148.asm:test148.i
test149.lof:test149.log
test149.exe:test149.asm
test149.asm:test149.i

#test150.lof:test150.log
#test150.exe:test150.asm
#test150.asm:test150.i
# There are not opendir, readdiri and closedir at Visual Studio library
test150.lof:test150.c
	touch $@
#test151.lof:test151.log
#test151.exe:test151.asm
#test151.asm:test151.i
# There is not `sbrk' at Visual Studio library
test151.lof:test151.c
	touch $@
test152.lof:test152.log
test152.exe:test152.asm
test152.asm:test152.i
test153.lof:test153.log
test153.exe:test153.asm
test153.asm:test153.i
test154.lof:test154.log
test154.exe:test154.asm
test154.asm:test154.i
test155.lof:test155.log
test155.exe:test155.asm
test155.asm:test155.i
test156.lof:test156.log
test156.exe:test156.asm
test156.asm:test156.i
test157.lof:test157.log
test157.exe:test157.asm
test157.asm:test157.i
test158.lof:test158.log
test158.exe:test158.asm
test158.asm:test158.i
test159.lof:test159.log
test159.exe:test159.asm
test159.asm:test159.i

test160.lof:test160.log
test160.exe:test160.asm
test160.asm:test160.i
test161.lof:test161.log
test161.exe:test161.asm
test161.asm:test161.i
test162.lof:test162.log
test162.exe:test162.asm
test162.asm:test162.i
test163.lof:test163.log
test163.exe:test163.asm
test163.asm:test163.i
test164.lof:test164.log
test164.exe:test164.asm
test164.asm:test164.i
test165.lof:test165.log
test165.exe:test165.asm
test165.asm:test165.i
test166.lof:test166.log
test166.exe:test166.asm
test166.asm:test166.i
test167.lof:test167.log
test167.exe:test167.asm
test167.asm:test167.i
test168.lof:test168.log
test168.exe:test168.asm
test168.asm:test168.i
test169.lof:test169.log
test169.exe:test169.asm
test169.asm:test169.i

test170.lof:test170.log
test170.exe:test170.asm
test170.asm:test170.i
test171.lof:test171.log
test171.exe:test171.asm
test171.asm:test171.i
test172.lof:test172.log
test172.exe:test172.asm
test172.asm:test172.i
test173.lof:test173.log
test173.exe:test173.asm
test173.asm:test173.i
test174.lof:test174.log
test174.exe:test174.asm
test174.asm:test174.i
test175.lof:test175.log
test175.exe:test175.asm
test175.asm:test175.i
test176.lof:test176.log
test176.exe:test176.asm
test176.asm:test176.i
test177.lof:test177.log
test177.exe:test177.asm
test177.asm:test177.i
test178.lof:test178.log
test178.exe:test178.asm
test178.asm:test178.i
test179.lof:test179.log
test179.exe:test179.asm
test179.asm:test179.i

test180.lof:test180.log
test180.exe:test180.asm
test180.asm:test180.i
test181.lof:test181.log
test181.exe:test181.asm
test181.asm:test181.i
test182.lof:test182.log
test182.exe:test182.asm
test182.asm:test182.i
test183.lof:test183.log
test183.exe:test183.asm
test183.asm:test183.i
test184.lof:test184.log
test184.exe:test184.asm
test184.asm:test184.i
test185.lof:test185.log
test185.exe:test185.asm
test185.asm:test185.i
test186.lof:test186.log
test186.exe:test186.asm
test186.asm:test186.i
test187.lof:test187.log
test187.exe:test187.asm
test187.asm:test187.i
test188.lof:test188.log
test188.exe:test188.asm
test188.asm:test188.i
test189.lof:test189.log
test189.exe:test189.asm
test189.asm:test189.i

test190.lof:test190.log
test190.exe:test190.asm
test190.asm:test190.i
test191.lof:test191.log
test191.exe:test191.asm
test191.asm:test191.i
test192.lof:test192.log
test192.exe:test192.asm
test192.asm:test192.i
test193.lof:test193.log
test193.exe:test193.asm
test193.asm:test193.i
test194.lof:test194.log
test194.exe:test194.asm
test194.asm:test194.i
test195.lof:test195.log
test195.exe:test195.asm
test195.asm:test195.i
test196.lof:test196.log
test196.exe:test196.asm
test196.asm:test196.i
test197.lof:test197.log
test197.exe:test197.asm
test197.asm:test197.i
test198.lof:test198.log
test198.exe:test198.asm
test198.asm:test198.i
test199.lof:test199.log
test199.exe:test199.asm
test199.asm:test199.i

test200.lof:test200.log
test200.exe:test200.asm
test200.asm:test200.i
test201.lof:test201.log
test201.exe:test201.asm
test201.asm:test201.i
test202.lof:test202.log
test202.exe:test202.asm
test202.asm:test202.i
test203.lof:test203.log
test203.exe:test203.asm
test203.asm:test203.i
test204.lof:test204.log
test204.exe:test204.asm
test204.asm:test204.i
test205.lof:test205.log
test205.exe:test205.asm
test205.asm:test205.i
test206.lof:test206.log
test206.exe:test206.asm
test206.asm:test206.i
test207.lof:test207.log
test207.exe:test207.asm
test207.asm:test207.i
test208.lof:test208.log
test208.exe:test208.asm
test208.asm:test208.i
test209.lof:test209.log
test209.exe:test209.asm
test209.asm:test209.i

test210.lof:test210.log
test210.exe:test210.asm
test210.asm:test210.i
test211.lof:test211.log
test211.exe:test211.asm
test211.asm:test211.i
test212.lof:test212.log
test212.exe:test212.asm
test212.asm:test212.i
test213.lof:test213.log
test213.exe:test213.asm
test213.asm:test213.i
test214.lof:test214.log
test214.exe:test214.asm
test214.asm:test214.i
test215.lof:test215.log
test215.exe:test215.asm
test215.asm:test215.i
test216.lof:test216.log
test216.exe:test216.asm
test216.asm:test216.i
test217.lof:test217.log
test217.exe:test217.asm
test217.asm:test217.i
test218.lof:test218.log
test218.exe:test218.asm
test218.asm:test218.i
test219.lof:test219.log
test219.exe:test219.asm
test219.asm:test219.i

test220.lof:test220.log
test220.exe:test220.asm
test220.asm:test220.i
test221.lof:test221.log
test221.exe:test221.asm
test221.asm:test221.i
test222.lof:test222.log
test222.exe:test222.asm
test222.asm:test222.i
test223.lof:test223.log
test223.exe:test223.asm
test223.asm:test223.i
test224.lof:test224.log
test224.exe:test224.asm
test224.asm:test224.i
test225.lof:test225.log
test225.exe:test225.asm
test225.asm:test225.i
test226.lof:test226.log
test226.exe:test226.asm
test226.asm:test226.i
test227.lof:test227.log
test227.exe:test227.asm
test227.asm:test227.i
test228.lof:test228.log
test228.exe:test228.asm
test228.asm:test228.i
test229.lof:test229.log
test229.exe:test229.asm
test229.asm:test229.i

test220.lof:test220.log
test220.exe:test220.asm
test220.asm:test220.i
test221.lof:test221.log
test221.exe:test221.asm
test221.asm:test221.i
test222.lof:test222.log
test222.exe:test222.asm
test222.asm:test222.i
test223.lof:test223.log
test223.exe:test223.asm
test223.asm:test223.i
test224.lof:test224.log
test224.exe:test224.asm
test224.asm:test224.i
test225.lof:test225.log
test225.exe:test225.asm
test225.asm:test225.i
test226.lof:test226.log
test226.exe:test226.asm
test226.asm:test226.i
test227.lof:test227.log
test227.exe:test227.asm
test227.asm:test227.i
test228.lof:test228.log
test228.exe:test228.asm
test228.asm:test228.i
test229.lof:test229.log
test229.exe:test229.asm
test229.asm:test229.i

test230.lof:test230.log
test230.exe:test230.asm
test230.asm:test230.i
test231.lof:test231.log
test231.exe:test231.asm
test231.asm:test231.i
test232.lof:test232.log
test232.exe:test232.asm
test232.asm:test232.i
test233.lof:test233.log
test233.exe:test233.asm
test233.asm:test233.i
test234.lof:test234.log
test234.exe:test234.asm
test234.asm:test234.i
test235.lof:test235.log
test235.exe:test235.asm
test235.asm:test235.i
test236.lof:test236.log
test236.exe:test236.asm
test236.asm:test236.i
test237.lof:test237.log
test237.exe:test237.asm
test237.asm:test237.i
test238.lof:test238.log
test238.exe:test238.asm
test238.asm:test238.i
test239.lof:test239.log
test239.exe:test239.asm
test239.asm:test239.i

test240.lof:test240.log
test240.exe:test240.asm
test240.asm:test240.i
test241.lof:test241.log
test241.exe:test241.asm
test241.asm:test241.i
test242.lof:test242.log
test242.exe:test242.asm
test242.asm:test242.i
test243.lof:test243.log
test243.exe:test243.asm
test243.asm:test243.i
test244.lof:test244.log
test244.exe:test244.asm
test244.asm:test244.i
test245.lof:test245.log
test245.exe:test245.asm
test245.asm:test245.i
test246.lof:test246.log
test246.exe:test246.asm
test246.asm:test246.i
test247.lof:test247.log
test247.exe:test247.asm
test247.asm:test247.i
test248.lof:test248.log
test248.exe:test248.asm
test248.asm:test248.i
test249.lof:test249.log
test249.exe:test249.asm
test249.asm:test249.i

test250.lof:test250.log
test250.exe:test250.asm
test250.asm:test250.i
test251.lof:test251.log
test251.exe:test251.asm
test251.asm:test251.i
test252.lof:test252.log
test252.exe:test252.asm
test252.asm:test252.i
test253.lof:test253.log
test253.exe:test253.asm
test253.asm:test253.i
test254.lof:test254.log
test254.exe:test254.asm
test254.asm:test254.i
test255.lof:test255.log
test255.exe:test255.asm
test255.asm:test255.i
test256.lof:test256.log
test256.exe:test256.asm
test256.asm:test256.i
test257.lof:test257.log
test257.exe:test257.asm
test257.asm:test257.i
test258.lof:test258.log
test258.exe:test258.asm
test258.asm:test258.i
test259.lof:test259.log
test259.exe:test259.asm
test259.asm:test259.i

test260.lof:test260.log
test260.exe:test260.asm
test260.asm:test260.i
test261.lof:test261.log
test261.exe:test261.asm
test261.asm:test261.i
test262.lof:test262.log
test262.exe:test262.asm
test262.asm:test262.i
test263.lof:test263.log
test263.exe:test263.asm
test263.asm:test263.i
test264.lof:test264.log
test264.exe:test264.asm
test264.asm:test264.i
test265.lof:test265.log
test265.exe:test265.asm
test265.asm:test265.i
test266.lof:test266.log
test266.exe:test266.asm
test266.asm:test266.i
test267.lof:test267.log
test267.exe:test267.asm
test267.asm:test267.i
test268.lof:test268.log
test268.exe:test268.asm
test268.asm:test268.i
test269.lof:test269.log
test269.exe:test269.asm
test269.asm:test269.i

test270.lof:test270.log
test270.exe:test270.asm
test270.asm:test270.i
test271.lof:test271.log
test271.exe:test271.asm
test271.asm:test271.i
test272.lof:test272.log
test272.exe:test272.asm
test272.asm:test272.i
test273.lof:test273.log
test273.exe:test273.asm
test273.asm:test273.i
test274.lof:test274.log
test274.exe:test274.asm
test274.asm:test274.i
test275.lof:test275.log
test275.exe:test275.asm
test275.asm:test275.i
test276.lof:test276.log
test276.exe:test276.asm
test276.asm:test276.i
test277.lof:test277.log
test277.exe:test277.asm
test277.asm:test277.i
test278.lof:test278.log
test278.exe:test278.asm
test278.asm:test278.i
test279.lof:test279.log
test279.exe:test279.asm
test279.asm:test279.i

test280.lof:test280.log
test280.exe:test280.asm
test280.asm:test280.i
test281.lof:test281.log
test281.exe:test281.asm
test281.asm:test281.i
test282.lof:test282.log
test282.exe:test282.asm
test282.asm:test282.i
test283.lof:test283.log
test283.exe:test283.asm
test283.asm:test283.i
test284.lof:test284.log
test284.exe:test284.asm
test284.asm:test284.i
test285.lof:test285.log
test285.exe:test285.asm
test285.asm:test285.i
test286.lof:test286.log
test286.exe:test286.asm
test286.asm:test286.i
test287.lof:test287.log
test287.exe:test287.asm
test287.asm:test287.i
test288.lof:test288.log
test288.exe:test288.asm
test288.asm:test288.i
test289.lof:test289.log
test289.exe:test289.asm
test289.asm:test289.i

test290.lof:test290.log
test290.exe:test290.asm
test290.asm:test290.i
test291.lof:test291.log
test291.exe:test291.asm
test291.asm:test291.i
test292.lof:test292.log
test292.exe:test292.asm
test292.asm:test292.i
test293.lof:test293.log
test293.exe:test293.asm
test293.asm:test293.i
test294.lof:test294.log
test294.exe:test294.asm
test294.asm:test294.i
test295.lof:test295.log
test295.exe:test295.asm
test295.asm:test295.i
test296.lof:test296.log
test296.exe:test296.asm
test296.asm:test296.i
test297.lof:test297.log
test297.exe:test297.asm
test297.asm:test297.i
test298.lof:test298.log
test298.exe:test298.asm
test298.asm:test298.i
test299.lof:test299.log
test299.exe:test299.asm
test299.asm:test299.i
