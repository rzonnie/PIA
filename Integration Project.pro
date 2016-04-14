######################################################################
# Automatically generated by qmake (3.0) wo apr. 13 12:42:52 2016
######################################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = "Integration Project"
INCLUDEPATH += . examples include

LIBS += \
    -lboost_program_options\
    -lboost_serialization
CONFIG += c++11


# Input
HEADERS += \
           include/Announcement.h \
           include/BlockingQueue.h \
           include/ChatHistory.h \
           include/chatmessage.h \
           include/DynamicQueue.h \
           include/functions.h \
           include/guicontroller.h \
           include/main.h \
           include/mainwindow.h \
           include/PIA.h \
           include/PIAEngine.h \
           include/QueueController.h \
           include/ReceivingSocket.h \
           include/RoutingTable.h \
           include/RoutingTableStruct.h \
           include/SendSocket.h \
           include/Settings.h \
           include/Socket.h \
           include/TerminalGUI.h \
           include/ThreadRunner.h \
    include/Crypto++/aes.h \
    include/Crypto++/algparam.h \
    include/Crypto++/argnames.h \
    include/Crypto++/authenc.h \
    include/Crypto++/basecode.h \
    include/Crypto++/BasicCryptoPPWrap.h \
    include/Crypto++/config.h \
    include/Crypto++/config.recommend \
    include/Crypto++/cpu.h \
    include/Crypto++/cryptlib.h \
    include/Crypto++/files.h \
    include/Crypto++/filters.h \
    include/Crypto++/fips140.h \
    include/Crypto++/hex.h \
    include/Crypto++/integer.h \
    include/Crypto++/iterhash.h \
    include/Crypto++/misc.h \
    include/Crypto++/modes.h \
    include/Crypto++/osrng.h \
    include/Crypto++/pch.h \
    include/Crypto++/queue.h \
    include/Crypto++/randpool.h \
    include/Crypto++/rijndael.h \
    include/Crypto++/rng.h \
    include/Crypto++/secblock.h \
    include/Crypto++/seckey.h \
    include/Crypto++/sha.h \
    include/Crypto++/simple.h \
    include/Crypto++/smartptr.h \
    include/Crypto++/stdcpp.h \
    include/Crypto++/strciphr.h \
    include/Crypto++/algebra.h \
    include/Crypto++/asn.h \
    include/Crypto++/des.h \
    include/Crypto++/eprecomp.h \
    include/Crypto++/fltrimpl.h \
    include/Crypto++/hrtimer.h \
    include/Crypto++/modarith.h \
    include/Crypto++/nbtheory.h \
    include/Crypto++/oids.h \
    include/Crypto++/pubkey.h \
    include/Crypto++/trdlocal.h \
    include/Crypto++/words.h \
    include/Crypto++/adhoc.cpp.proto \
    include/Crypto++/adler32.h \
    include/Crypto++/arc4.h \
    include/Crypto++/base32.h \
    include/Crypto++/base64.h \
    include/Crypto++/cast.h \
    include/Crypto++/cbcmac.h \
    include/Crypto++/ccm.h \
    include/Crypto++/channels.h \
    include/Crypto++/cmac.h \
    include/Crypto++/crc.h \
    include/Crypto++/default.h \
    include/Crypto++/dh.h \
    include/Crypto++/dh2.h \
    include/Crypto++/dll.h \
    include/Crypto++/dmac.h \
    include/Crypto++/dsa.h \
    include/Crypto++/eax.h \
    include/Crypto++/ec2n.h \
    include/Crypto++/eccrypto.h \
    include/Crypto++/ecp.h \
    include/Crypto++/elgamal.h \
    include/Crypto++/emsa2.h \
    include/Crypto++/esign.h \
    include/Crypto++/factory.h \
    include/Crypto++/gcm.h \
    include/Crypto++/gf2_32.h \
    include/Crypto++/gf2n.h \
    include/Crypto++/gf256.h \
    include/Crypto++/gfpcrypt.h \
    include/Crypto++/gost.h \
    include/Crypto++/gzip.h \
    include/Crypto++/hkdf.h \
    include/Crypto++/hmac.h \
    include/Crypto++/ida.h \
    include/Crypto++/idea.h \
    include/Crypto++/lubyrack.h \
    include/Crypto++/luc.h \
    include/Crypto++/mars.h \
    include/Crypto++/md2.h \
    include/Crypto++/md4.h \
    include/Crypto++/md5.h \
    include/Crypto++/mdc.h \
    include/Crypto++/mersenne.h \
    include/Crypto++/modexppc.h \
    include/Crypto++/mqueue.h \
    include/Crypto++/mqv.h \
    include/Crypto++/network.h \
    include/Crypto++/nr.h \
    include/Crypto++/oaep.h \
    include/Crypto++/panama.h \
    include/Crypto++/pkcspad.h \
    include/Crypto++/polynomi.h \
    include/Crypto++/pssr.h \
    include/Crypto++/pwdbased.h \
    include/Crypto++/rabin.h \
    include/Crypto++/rc2.h \
    include/Crypto++/rc5.h \
    include/Crypto++/rc6.h \
    include/Crypto++/rdrand.h \
    include/Crypto++/resource.h \
    include/Crypto++/ripemd.h \
    include/Crypto++/rsa.h \
    include/Crypto++/rw.h \
    include/Crypto++/safer.h \
    include/Crypto++/salsa.h \
    include/Crypto++/seal.h \
    include/Crypto++/seed.h \
    include/Crypto++/serpent.h \
    include/Crypto++/serpentp.h \
    include/Crypto++/sha3.h \
    include/Crypto++/shacal2.h \
    include/Crypto++/shark.h \
    include/Crypto++/skipjack.h \
    include/Crypto++/socketft.h \
    include/Crypto++/sosemanuk.h \
    include/Crypto++/square.h \
    include/Crypto++/tea.h \
    include/Crypto++/tiger.h \
    include/Crypto++/trunhash.h \
    include/Crypto++/ttmac.h \
    include/Crypto++/validate.h \
    include/Crypto++/vmac.h \
    include/Crypto++/wait.h \
    include/Crypto++/wake.h \
    include/Crypto++/whrlpool.h \
    include/Crypto++/winpipes.h \
    include/Crypto++/xtr.h \
    include/Crypto++/xtrcrypt.h \
    include/Crypto++/zdeflate.h \
    include/Crypto++/zinflate.h \
    include/Crypto++/zlib.h \
    include/Crypto++/3way.h \
    include/Crypto++/bench.h \
    include/Crypto++/blowfish.h \
    include/Crypto++/blumshub.h \
    include/Crypto++/camellia.h \
    include/Crypto++/twofish.h

FORMS += mainwindow.ui
SOURCES += \
           src/Announcement.cpp \
           src/ChatHistory.cpp \
           src/DynamicQueue.cpp \
           src/functions.cpp \
           src/guicontroller.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/PIA.cpp \
           src/PIAEngine.cpp \
           src/QueueController.cpp \
           src/ReceivingSocket.cpp \
           src/RoutingTable.cpp \
           src/SendSocket.cpp \
           src/Settings.cpp \
           src/Socket.cpp \
           src/TerminalGUI.cpp \
           src/ThreadRunner.cpp \
    include/Crypto++/algparam.cpp \
    include/Crypto++/authenc.cpp \
    include/Crypto++/basecode.cpp \
    include/Crypto++/cpu.cpp \
    include/Crypto++/fips140.cpp \
    include/Crypto++/integer.cpp \
    include/Crypto++/iterhash.cpp \
    include/Crypto++/misc.cpp \
    include/Crypto++/modes.cpp \
    include/Crypto++/osrng.cpp \
    include/Crypto++/pch.cpp \
    include/Crypto++/queue.cpp \
    include/Crypto++/randpool.cpp \
    include/Crypto++/rijndael.cpp \
    include/Crypto++/rng.cpp \
    include/Crypto++/sha.cpp \
    include/Crypto++/simple.cpp \
    include/Crypto++/strciphr.cpp \
    include/Crypto++/algebra.cpp \
    include/Crypto++/asn.cpp \
    include/Crypto++/des.cpp \
    include/Crypto++/eprecomp.cpp \
    include/Crypto++/hrtimer.cpp \
    include/Crypto++/nbtheory.cpp \
    include/Crypto++/pubkey.cpp \
    include/Crypto++/trdlocal.cpp \
    include/Crypto++/adler32.cpp \
    include/Crypto++/arc4.cpp \
    include/Crypto++/base32.cpp \
    include/Crypto++/base64.cpp \
    include/Crypto++/cast.cpp \
    include/Crypto++/casts.cpp \
    include/Crypto++/cbcmac.cpp \
    include/Crypto++/ccm.cpp \
    include/Crypto++/channels.cpp \
    include/Crypto++/cmac.cpp \
    include/Crypto++/crc.cpp \
    include/Crypto++/cryptlib.cpp \
    include/Crypto++/cryptlib_bds.cpp \
    include/Crypto++/default.cpp \
    include/Crypto++/dessp.cpp \
    include/Crypto++/dh.cpp \
    include/Crypto++/dh2.cpp \
    include/Crypto++/dll.cpp \
    include/Crypto++/dsa.cpp \
    include/Crypto++/eax.cpp \
    include/Crypto++/ec2n.cpp \
    include/Crypto++/eccrypto.cpp \
    include/Crypto++/ecp.cpp \
    include/Crypto++/elgamal.cpp \
    include/Crypto++/emsa2.cpp \
    include/Crypto++/esign.cpp \
    include/Crypto++/files.cpp \
    include/Crypto++/filters.cpp \
    include/Crypto++/fipsalgt.cpp \
    include/Crypto++/fipstest.cpp \
    include/Crypto++/gcm.cpp \
    include/Crypto++/gf2_32.cpp \
    include/Crypto++/gf2n.cpp \
    include/Crypto++/gf256.cpp \
    include/Crypto++/gfpcrypt.cpp \
    include/Crypto++/gost.cpp \
    include/Crypto++/gzip.cpp \
    include/Crypto++/hex.cpp \
    include/Crypto++/hmac.cpp \
    include/Crypto++/ida.cpp \
    include/Crypto++/idea.cpp \
    include/Crypto++/luc.cpp \
    include/Crypto++/mars.cpp \
    include/Crypto++/marss.cpp \
    include/Crypto++/md2.cpp \
    include/Crypto++/md4.cpp \
    include/Crypto++/md5.cpp \
    include/Crypto++/mqueue.cpp \
    include/Crypto++/mqv.cpp \
    include/Crypto++/network.cpp \
    include/Crypto++/oaep.cpp \
    include/Crypto++/panama.cpp \
    include/Crypto++/pkcspad.cpp \
    include/Crypto++/polynomi.cpp \
    include/Crypto++/pssr.cpp \
    include/Crypto++/rabin.cpp \
    include/Crypto++/rc2.cpp \
    include/Crypto++/rc5.cpp \
    include/Crypto++/rc6.cpp \
    include/Crypto++/rdrand.cpp \
    include/Crypto++/rdtables.cpp \
    include/Crypto++/regtest.cpp \
    include/Crypto++/ripemd.cpp \
    include/Crypto++/rsa.cpp \
    include/Crypto++/rw.cpp \
    include/Crypto++/safer.cpp \
    include/Crypto++/salsa.cpp \
    include/Crypto++/seal.cpp \
    include/Crypto++/seed.cpp \
    include/Crypto++/serpent.cpp \
    include/Crypto++/sha3.cpp \
    include/Crypto++/shacal2.cpp \
    include/Crypto++/shark.cpp \
    include/Crypto++/sharkbox.cpp \
    include/Crypto++/skipjack.cpp \
    include/Crypto++/socketft.cpp \
    include/Crypto++/sosemanuk.cpp \
    include/Crypto++/square.cpp \
    include/Crypto++/squaretb.cpp \
    include/Crypto++/tea.cpp \
    include/Crypto++/tftables.cpp \
    include/Crypto++/tiger.cpp \
    include/Crypto++/tigertab.cpp \
    include/Crypto++/ttmac.cpp \
    include/Crypto++/vmac.cpp \
    include/Crypto++/wait.cpp \
    include/Crypto++/wake.cpp \
    include/Crypto++/whrlpool.cpp \
    include/Crypto++/winpipes.cpp \
    include/Crypto++/xtr.cpp \
    include/Crypto++/xtrcrypt.cpp \
    include/Crypto++/zdeflate.cpp \
    include/Crypto++/zinflate.cpp \
    include/Crypto++/zlib.cpp \
    include/Crypto++/3way.cpp \
    include/Crypto++/bfinit.cpp \
    include/Crypto++/blowfish.cpp \
    include/Crypto++/blumshub.cpp \
    include/Crypto++/camellia.cpp \
    include/Crypto++/twofish.cpp

OTHER_FILES += \
    include/Crypto++/vs2010.zip \
    include/Crypto++/cryptest.sh \
    include/Crypto++/rdrand-nasm.sh \
    include/Crypto++/cryptopp.rc \
    include/Crypto++/cryptdll.dsp \
    include/Crypto++/cryptdll.vcproj \
    include/Crypto++/cryptest.dsp \
    include/Crypto++/cryptest.dsw \
    include/Crypto++/cryptest.sln \
    include/Crypto++/cryptest.vcproj \
    include/Crypto++/cryptest_bds.bdsgroup \
    include/Crypto++/cryptest_bds.bdsproj \
    include/Crypto++/cryptest_bds.bpf \
    include/Crypto++/cryptlib.dsp \
    include/Crypto++/cryptlib.vcproj \
    include/Crypto++/cryptlib_bds.bdsproj \
    include/Crypto++/dlltest.dsp \
    include/Crypto++/dlltest.vcproj \
    include/Crypto++/Doxyfile \
    include/Crypto++/Filelist.txt \
    include/Crypto++/GNUmakefile \
    include/Crypto++/GNUmakefile-cross \
    include/Crypto++/Install.txt \
    include/Crypto++/License.txt \
    include/Crypto++/rdrand.S \
    include/Crypto++/rdrand-masm.cmd \
    include/Crypto++/Readme.txt \
    include/Crypto++/cryptopp563.diff \
    include/Crypto++/rdrand.asm \
    include/Crypto++/x64dll.asm \
    include/Crypto++/x64masm.asm
