project(executable)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

add_executable(${PROJECT_NAME}
	src/main.cpp
)