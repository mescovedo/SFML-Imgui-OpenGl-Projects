cmake_minimum_required(VERSION 4.0)
project(imguiProjects)

set(CMAKE_CXX_STANDARD 20)

# --- Paths ---
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/external/glfw)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
set(JSON_DIR ${CMAKE_SOURCE_DIR}/external/json)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/external/sfml)
set(IMGUI_SFML_DIR ${CMAKE_SOURCE_DIR}/external/imgui-sfml)

# --- ImGui sources ---
set(IMGUI_SRC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
)

set(IMGUI_BACKENDS_GL
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(IMGUI_BACKENDS_SFML
        ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)

# --- ImGui Library ---
add_library(imgui STATIC ${IMGUI_SRC} ${IMGUI_BACKENDS_GL} ${IMGUI_BACKENDS_SFML})

# Include directories for ImGui library
target_include_directories(imgui
        PUBLIC
        ${IMGUI_DIR}                 # ImGui core
        ${IMGUI_DIR}/backends        # Backends (GLFW, OpenGL3)
        ${IMGUI_SFML_DIR}            # SFML binding
        ${GLFW_DIR}/include           # GLFW headers
        ${SFML_DIR}/include           # SFML headers
)

# Disable warnings for ImGui library
if(MSVC)
    target_compile_options(imgui PRIVATE /w)
else()
    target_compile_options(imgui PRIVATE -w)
endif()

# --- openGl target ---
add_executable(openGl openGl/main.cpp)

# Include directories for openGl target
target_include_directories(openGl
        PRIVATE
        ${GLFW_DIR}/include
        ${JSON_DIR}/include
)

# Compile definitions
target_compile_definitions(openGl PRIVATE CONFIG_DIR="${CMAKE_SOURCE_DIR}")

# Link libraries
target_link_libraries(openGl PRIVATE imgui ${GLFW_DIR}/lib/libglfw3.a opengl32 gdi32)

# Enable warnings for your code only
if (MSVC)
    target_compile_options(openGl PRIVATE /W4 /permissive-)
else()
    target_compile_options(openGl PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()


# --- High-level target ---
add_executable(sfml sfml/main.cpp
)

# Include directories for sfml target
target_include_directories(sfml
        PRIVATE
        ${JSON_DIR}/include
        ${SFML_DIR}/include
        sfml
)

# Compile definitions
target_compile_definitions(sfml PRIVATE CONFIG_DIR="${CMAKE_SOURCE_DIR}")

# Link libraries
target_link_libraries(sfml PRIVATE imgui
        ${SFML_DIR}/lib/libsfml-graphics.a
        ${SFML_DIR}/lib/libsfml-window.a
        ${SFML_DIR}/lib/libsfml-system.a
        opengl32 winmm gdi32
)

# Enable warnings for your code only
if (MSVC)
    target_compile_options(sfml PRIVATE /W4 /permissive-)
else()
    target_compile_options(sfml PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

# --- Copy SFML DLLs on Windows ---
if(WIN32)
    add_custom_command(TARGET sfml POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SFML_DIR}/bin
            $<TARGET_FILE_DIR:sfml>)
endif()
