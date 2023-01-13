project(ExampleLibrary)

add_library(${PROJECT_NAME} STATIC
            include/ExampleClass.hpp
            source/ExampleClass.cpp
            )

target_link_libraries(${PROJECT_NAME}
                      # add libraries here
                      )

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )
