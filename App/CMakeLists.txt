set(SOURCES
src/main.cpp
src/BasicLayer.h
src/BasicLayer.cpp
)

add_executable(App)

target_sources(App PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_link_libraries(App PRIVATE Core)

target_include_directories(App PRIVATE src)

set_target_properties(App PROPERTIES
VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/App"
)
