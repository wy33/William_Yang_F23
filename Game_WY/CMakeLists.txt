set(HEADER_FILES
	Coconut.h
	Timer.h
	MyGame.h
)

set(SOURCE_FILES
	Coconut.cpp
	Timer.cpp
	MyGame.cpp
	main.cpp
)

add_executable(Game_WY ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_WY Egg)

include_directories(../Egg/include)