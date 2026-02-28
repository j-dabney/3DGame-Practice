set(SOURCES
src/Core/Application.cpp
src/Core/Application.h
src/Core/Layer.cpp
src/Core/Layer.h
src/Core/Window.cpp
src/Core/Window.h
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

# For VS
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_link_libraries(Core raylib)

target_include_directories(Core PUBLIC "src")
