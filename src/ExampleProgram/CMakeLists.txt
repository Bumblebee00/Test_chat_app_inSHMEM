project(ExampleProgram)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)    # Adds source code

target_link_libraries(${PROJECT_NAME}       # Add a line here if you want to link a library
                      toml11::toml11
                      ${MOSQUITTO_LIBRARY}
                      )
