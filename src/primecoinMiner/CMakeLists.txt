cmake_minimum_required(VERSION 2.6.0)
project(jhPrimeminer)

find_package(OpenSSL REQUIRED)

set(jhPrimeminer_SOURCES
	./bn2.cpp
	./bn2_div.cpp
	./jhlib/customBuffer.cpp
	./jhlib/streamWrapper.cpp
	./jhlib/fastString.cpp
	./jhlib/fastString_eprintf.cpp
	./jhlib/hashTable_uint32.cpp
	./jhlib/packetBuffer.cpp
	./jhlib/simpleHTTP.cpp
	./jhlib/simpleList.cpp
	./jsonBuilder.cpp
	./jsonClient.cpp
	./jsonObject.cpp
	./jsonParser.cpp
	./jsonrpc.cpp
	./main.cpp
	./miner.cpp
	./prime.cpp
	./transaction.cpp
	./ripemd160.cpp
	./sha256.cpp
	./xptClient.cpp
	./xptClientPacketHandler.cpp
	./xptPacketbuffer.cpp
	./xptServer.cpp
	./xptServerPacketHandler.cpp
	./bignum2.h
	./global.h
	./jhlib/JHLib.h
	./jhlib/customBuffer.h
	./jhlib/fastSorter.h
	./jhlib/fastString.h
	./jhlib/hashTable.h
	./jhlib/packetBuffer.h
	./jhlib/simpleHTTP.h
	./jhlib/simpleList.h
	./jsonrpc.h
	./prime.h
	./ripemd160.h
	./sha256.h
	./uint256.h
	./xptClient.h
	./xptServer.h
)

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-function -Wno-write-strings -std=gnu++0x")
	
	include_directories(${jhPrimeminer_SOURCE_DIR}/lib/linux/mpir)
else()
	include_directories(${jhPrimeminer_SOURCE_DIR}/lib)
endif()


add_executable(jhPrimeminer ${jhPrimeminer_SOURCES})

if(UNIX)
	target_link_libraries(jhPrimeminer 
		pthread
		${jhPrimeminer_SOURCE_DIR}/lib/linux/mpir/.libs/libmpir.so pthread) 
endif()

target_link_libraries(jhPrimeminer ${OPENSSL_LIBRARIES})
