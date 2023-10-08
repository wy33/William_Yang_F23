set(HEADER_FILES

)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_WY ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_WY Egg)

include_directories(../Egg/include)