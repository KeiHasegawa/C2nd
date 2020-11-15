TESTS = $(wildcard *.c)
LOFS = $(TESTS:.c=.lof)
DIFF = diff
TOUCH = touch
DOS2UNIX = dos2unix.csh

all:$(LOFS) test054/ok.log

CPP=hcpp.exe
ifeq ($(BATCH_BUILD_VS_X86),1)
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
-D_WCHAR_T_DEFINED \
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
DOGV = wdog.exe -v

CMATHLIB = -lm
UNAME := $(shell uname)
ifneq (,$(findstring CYGWIN,$(UNAME)))
	CMATHLIB =
endif


%.i : %.c
	$(DOGV) $(CPP) $(CPP_FLAG) $< | vs_header_conv.pl > $@

%.log : %.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) > $@
	$(DOS2UNIX) $@

%.lof : %.log
	$(DOGV) $(DIFF) $< $@
	$(TOUCH) $@

clean:
	$(RM) *.log *.exe *.i *.s *.stackdump core.* *~
	cd test054 ; make clean

test006.log:test006.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test006.lof:test006.log
	$(DOGV) $(DIFF) $< $(basename $<).c
	touch $@

test007.log:test007.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test007.lof:test007.log
	$(DOGV) $(DIFF) $< $(basename $<).c
	touch $@

test008.log:test008.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test009.log:test009.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test010.log:test010.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test011.log:test011.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test012.log:test012.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test016.log:test016.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test017.log:test017.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test041.log:test041.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test050.log:test050.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test052.log:test052.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test054/ok.log:
	cd test054 ; make all

test079.log:test079.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test094.log:test094.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test095.log:test095.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test102.log:test102.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< aaa bbb ccc ] \) > $@
	$(DOS2UNIX) $@

test103.log:test103.i
	$(DOGV) $(CC1) $< $(CC1_FLAG)  --generator-option \( --arg \[ $< ddd eee fff ] \) > $@
	$(DOS2UNIX) $@

test104.log:test104.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< ggg hhh iii ] \) > $@
	$(DOS2UNIX) $@

test105.log:test105.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< int ] \) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test106.log:test106.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< -n int < $(basename $<).c ] \) > $@
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< -x -n = ] \) < $(basename $<).c >> $@
	$(DOS2UNIX) $@

test107.log:test107.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< -n ] \) < $(basename $<).data >> $@
	$(DOS2UNIX) $@

test108.log:test108.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test109.log:test109.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test123.log:test123.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test124.log:test124.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test125.log:test125.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test126.log:test126.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test127.log:test127.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) > $@
	$(DOS2UNIX) $@

test128.log:test128.i
	$(DOGV) --alarm 300 $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test135.log:test135.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test138.log:test138.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test139.log:test139.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).data > $@
	$(DOS2UNIX) $@

test140.log:test140.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< test000.c test001.c test002.c ] \) >> $@
	-$(DOG) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< not_exist ] \) >> $@
	$(DOS2UNIX) $@

test141.log:test141.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< test000.c test001.c test002.c ] \) >> $@
	-$(DOG) $(CC1) $< --generator-option \( --arg \[ ./$(basename $<) not_exist ] \) 2>> $@
	$(DOS2UNIX) $@

test142.log:test142.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test143.log:test143.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test144.log:test144.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test145.log:test145.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test146.log:test146.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) < $(basename $<).c > $@
	$(DOS2UNIX) $@

test147.log:test147.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< $(basename $<).c $@ ] \)
	-$(DOG) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< $(basename $<).c ] \) 2>> $@
	$(DOS2UNIX) $@

test148.log:test148.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< $(basename $<).c ] \) > $@
	$(DOS2UNIX) $@

test149.log:test149.i
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< 0 $(basename $<).c ] \) > $@
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< 1 ] \) <$(basename $<).c >> $@
	$(DOGV) $(CC1) $< $(CC1_FLAG) --generator-option \( --arg \[ $< 2 ] \) 2>> $@
	$(DOS2UNIX) $@

test000.lof:test000.log
test000.exe:test000.s
test000.s:test000.i
test001.lof:test001.log
test001.exe:test001.s
test001.s:test001.i
test002.lof:test002.log
test002.exe:test002.s
test002.s:test002.i
test003.lof:test003.log
test003.exe:test003.s
test003.s:test003.i
test004.lof:test004.log
test004.exe:test004.s
test004.s:test004.i
test005.lof:test005.log
test005.exe:test005.s
test005.s:test005.i
test006.lof:test006.log
test006.exe:test006.s
test006.s:test006.i
test007.lof:test007.log
test007.exe:test007.s
test007.s:test007.i
test008.lof:test008.log
test008.exe:test008.s
test008.s:test008.i
test009.lof:test009.log
test009.exe:test009.s
test009.s:test009.i

test010.lof:test010.log
test010.exe:test010.s
test010.s:test010.i
test011.lof:test011.log
test011.exe:test011.s
test011.s:test011.i
test012.lof:test012.log
test012.exe:test012.s
test012.s:test012.i
test013.lof:test013.log
test013.exe:test013.s
test013.s:test013.i
test014.lof:test014.log
test014.exe:test014.s
test014.s:test014.i
test015.lof:test015.log
test015.exe:test015.s
test015.s:test015.i
test016.lof:test016.log
test016.exe:test016.s
test016.s:test016.i
test017.lof:test017.log
test017.exe:test017.s
test017.s:test017.i
test018.lof:test018.log
test018.exe:test018.s
test018.s:test018.i
test019.lof:test019.log
test019.exe:test019.s
test019.s:test019.i

test020.lof:test020.log
test020.exe:test020.s
test020.s:test020.i
test021.lof:test021.log
test021.exe:test021.s
test021.s:test021.i
test022.lof:test022.log
test022.exe:test022.s
test022.s:test022.i
test023.lof:test023.log
test023.exe:test023.s
test023.s:test023.i
test024.lof:test024.log
test024.exe:test024.s
test024.s:test024.i
test025.lof:test025.log
test025.exe:test025.s
test025.s:test025.i
test026.lof:test026.log
test026.exe:test026.s
test026.s:test026.i
test027.lof:test027.log
test027.exe:test027.s
test027.s:test027.i
test028.lof:test028.log
test028.exe:test028.s
test028.s:test028.i
test029.lof:test029.log
test029.exe:test029.s
test029.s:test029.i

test030.lof:test030.log
test030.exe:test030.s
test030.s:test030.i
test031.lof:test031.log
test031.exe:test031.s
test031.s:test031.i
test032.lof:test032.log
test032.exe:test032.s
test032.s:test032.i
test033.lof:test033.log
test033.exe:test033.s
test033.s:test033.i
test034.lof:test034.log
test034.exe:test034.s
test034.s:test034.i
test035.lof:test035.log
test035.exe:test035.s
test035.s:test035.i
test036.lof:test036.log
test036.exe:test036.s
test036.s:test036.i
test037.lof:test037.log
test037.exe:test037.s
test037.s:test037.i
test038.lof:test038.log
test038.exe:test038.s
test038.s:test038.i
test039.lof:test039.log
test039.exe:test039.s
test039.s:test039.i

test040.lof:test040.log
test040.exe:test040.s
test040.s:test040.i
test041.lof:test041.log
test041.exe:test041.s
test041.s:test041.i
test042.lof:test042.log
test042.exe:test042.s
test042.s:test042.i
test043.lof:test043.log
test043.exe:test043.s
test043.s:test043.i
test044.lof:test044.log
test044.exe:test044.s
test044.s:test044.i
test045.lof:test045.log
test045.exe:test045.s
test045.s:test045.i
test046.lof:test046.log
test046.exe:test046.s
test046.s:test046.i
test047.lof:test047.log
test047.exe:test047.s
test047.s:test047.i
test048.lof:test048.log
test048.exe:test048.s
test048.s:test048.i
test049.lof:test049.log
test049.exe:test049.s
test049.s:test049.i

test050.lof:test050.log
test050.exe:test050.s
test050.s:test050.i
test051.lof:test051.log
test051.exe:test051.s
test051.s:test051.i
test052.lof:test052.log
test052.exe:test052.s
test052.s:test052.i
test053.lof:test053.log
test053.exe:test053.s
test053.s:test053.i
test054.lof:test054.log
test054.exe:test054.s
test054.s:test054.i
test055.lof:test055.log
test055.exe:test055.s
test055.s:test055.i
test056.lof:test056.log
test056.exe:test056.s
test056.s:test056.i
test057.lof:test057.log
test057.exe:test057.s
test057.s:test057.i
test058.lof:test058.log
test058.exe:test058.s
test058.s:test058.i
test059.lof:test059.log
test059.exe:test059.s
test059.s:test059.i

test060.lof:test060.log
test060.exe:test060.s
test060.s:test060.i
test061.lof:test061.log
test061.exe:test061.s
test061.s:test061.i
test062.lof:test062.log
test062.exe:test062.s
test062.s:test062.i
test063.lof:test063.log
test063.exe:test063.s
test063.s:test063.i
test064.lof:test064.log
test064.exe:test064.s
test064.s:test064.i
test065.lof:test065.log
test065.exe:test065.s
test065.s:test065.i
test066.lof:test066.log
test066.exe:test066.s
test066.s:test066.i
test067.lof:test067.log
test067.exe:test067.s
test067.s:test067.i
test068.lof:test068.log
test068.exe:test068.s
test068.s:test068.i
test069.lof:test069.log
test069.exe:test069.s
test069.s:test069.i

test070.lof:test070.log
test070.exe:test070.s
test070.s:test070.i
test071.lof:test071.log
test071.exe:test071.s
test071.s:test071.i
test072.lof:test072.log
test072.exe:test072.s
test072.s:test072.i
test073.lof:test073.log
test073.exe:test073.s
test073.s:test073.i
test074.lof:test074.log
test074.exe:test074.s
test074.s:test074.i
test075.lof:test075.log
test075.exe:test075.s
test075.s:test075.i
test076.lof:test076.log
test076.exe:test076.s
test076.s:test076.i
test077.lof:test077.log
test077.exe:test077.s
test077.s:test077.i
test078.lof:test078.log
test078.exe:test078.s
test078.s:test078.i
test079.lof:test079.log
test079.exe:test079.s
test079.s:test079.i

test080.lof:test080.log
test080.exe:test080.s
test080.s:test080.i
test081.lof:test081.log
test081.exe:test081.s
test081.s:test081.i
test082.lof:test082.log
test082.exe:test082.s
test082.s:test082.i
test083.lof:test083.log
test083.exe:test083.s
test083.s:test083.i
test084.lof:test084.log
test084.exe:test084.s
test084.s:test084.i
test085.lof:test085.log
test085.exe:test085.s
test085.s:test085.i
test086.lof:test086.log
test086.exe:test086.s
test086.s:test086.i
test087.lof:test087.log
test087.exe:test087.s
test087.s:test087.i
test088.lof:test088.log
test088.exe:test088.s
test088.s:test088.i
test089.lof:test089.log
test089.exe:test089.s
test089.s:test089.i

test090.lof:test090.log
test090.exe:test090.s
test090.s:test090.i
test091.lof:test091.log
test091.exe:test091.s
test091.s:test091.i
test092.lof:test092.log
test092.exe:test092.s
test092.s:test092.i
test093.lof:test093.log
test093.exe:test093.s
test093.s:test093.i
test094.lof:test094.log
test094.exe:test094.s
test094.s:test094.i
test095.lof:test095.log
test095.exe:test095.s
test095.s:test095.i
test096.lof:test096.log
test096.exe:test096.s
test096.s:test096.i
test097.lof:test097.log
test097.exe:test097.s
test097.s:test097.i
test098.lof:test098.log
test098.exe:test098.s
test098.s:test098.i
test099.lof:test099.log
test099.exe:test099.s
test099.s:test099.i

test100.lof:test100.log
test100.exe:test100.s
test100.s:test100.i
test101.lof:test101.log
test101.exe:test101.s
test101.s:test101.i
test102.lof:test102.log
test102.exe:test102.s
test102.s:test102.i
test103.lof:test103.log
test103.exe:test103.s
test103.s:test103.i
test104.lof:test104.log
test104.exe:test104.s
test104.s:test104.i
test105.lof:test105.log
test105.exe:test105.s
test105.s:test105.i
test106.lof:test106.log
test106.exe:test106.s
test106.s:test106.i
test107.lof:test107.log
test107.exe:test107.s
test107.s:test107.i
test108.lof:test108.log
test108.exe:test108.s
test108.s:test108.i
test109.lof:test109.log
test109.exe:test109.s
test109.s:test109.i

test110.lof:test110.log
test110.exe:test110.s
test110.s:test110.i
test111.lof:test111.log
test111.exe:test111.s
test111.s:test111.i
test112.lof:test112.log
test112.exe:test112.s
test112.s:test112.i
test113.lof:test113.log
test113.exe:test113.s
test113.s:test113.i
test114.lof:test114.log
test114.exe:test114.s
test114.s:test114.i
test115.lof:test115.log
test115.exe:test115.s
test115.s:test115.i
test116.lof:test116.log
test116.exe:test116.s
test116.s:test116.i
test117.lof:test117.log
test117.exe:test117.s
test117.s:test117.i
test118.lof:test118.log
test118.exe:test118.s
test118.s:test118.i
test119.lof:test119.log
test119.exe:test119.s
test119.s:test119.i

test120.lof:test120.log
test120.exe:test120.s
test120.s:test120.i
test121.lof:test121.log
test121.exe:test121.s
test121.s:test121.i
test122.lof:test122.log
test122.exe:test122.s
test122.s:test122.i
test123.lof:test123.log
test123.exe:test123.s
test123.s:test123.i
test124.lof:test124.log
test124.exe:test124.s
test124.s:test124.i
test125.lof:test125.log
test125.exe:test125.s
test125.s:test125.i
test126.lof:test126.log
test126.exe:test126.s
test126.s:test126.i
test127.lof:test127.log
test127.exe:test127.s
test127.s:test127.i
test128.lof:test128.log
test128.exe:test128.s
test128.s:test128.i
test129.lof:test129.log
test129.exe:test129.s
test129.s:test129.i

test130.lof:test130.log
test130.exe:test130.s
test130.s:test130.i
test131.lof:test131.log
test131.exe:test131.s
test131.s:test131.i
test132.lof:test132.log
test132.exe:test132.s
test132.s:test132.i
test133.lof:test133.log
test133.exe:test133.s
test133.s:test133.i
test134.lof:test134.log
test134.exe:test134.s
test134.s:test134.i
test135.lof:test135.log
test135.exe:test135.s
test135.s:test135.i
test136.lof:test136.log
test136.exe:test136.s
test136.s:test136.i
test137.lof:test137.log
test137.exe:test137.s
test137.s:test137.i
test138.lof:test138.log
test138.exe:test138.s
test138.s:test138.i
test139.lof:test139.log
test139.exe:test139.s
test139.s:test139.i

test140.lof:test140.log
test140.exe:test140.s
test140.s:test140.i
test141.lof:test141.log
test141.exe:test141.s
test141.s:test141.i
test142.lof:test142.log
test142.exe:test142.s
test142.s:test142.i
test143.lof:test143.log
test143.exe:test143.s
test143.s:test143.i
test144.lof:test144.log
test144.exe:test144.s
test144.s:test144.i
test145.lof:test145.log
test145.exe:test145.s
test145.s:test145.i
test146.lof:test146.log
test146.exe:test146.s
test146.s:test146.i
test147.lof:test147.log
test147.exe:test147.s
test147.s:test147.i
test148.lof:test148.log
test148.exe:test148.s
test148.s:test148.i
test149.lof:test149.log
test149.exe:test149.s
test149.s:test149.i

test150.lof:test150.c
	touch $@

test151.lof:test151.log
test151.exe:test151.s
test151.s:test151.i
test152.lof:test152.log
test152.exe:test152.s
test152.s:test152.i
test153.lof:test153.log
test153.exe:test153.s
test153.s:test153.i
test154.lof:test154.log
test154.exe:test154.s
test154.s:test154.i
test155.lof:test155.log
test155.exe:test155.s
test155.s:test155.i
test156.lof:test156.log
test156.exe:test156.s
test156.s:test156.i
test157.lof:test157.log
test157.exe:test157.s
test157.s:test157.i
test158.lof:test158.log
test158.exe:test158.s
test158.s:test158.i
test159.lof:test159.log
test159.exe:test159.s
test159.s:test159.i
