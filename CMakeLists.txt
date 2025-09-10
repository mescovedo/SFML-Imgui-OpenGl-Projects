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

# --- Low-level target ---
add_executable(openGl openGl/main.cpp ${IMGUI_SRC} ${IMGUI_BACKENDS_GL})
target_include_directories(openGl PRIVATE ${GLFW_DIR}/include ${IMGUI_DIR} ${IMGUI_DIR}/backends ${JSON_DIR}/include)
target_compile_definitions(openGl PRIVATE CONFIG_DIR="${CMAKE_SOURCE_DIR}")
target_link_libraries(openGl ${GLFW_DIR}/lib/libglfw3.a opengl32 gdi32)

# --- High-level target ---
add_executable(sfml sfml/main.cpp ${IMGUI_SRC} ${IMGUI_BACKENDS_SFML})
target_include_directories(sfml PRIVATE ${IMGUI_DIR} ${IMGUI_SFML_DIR} ${JSON_DIR}/include ${SFML_DIR}/include)
target_compile_definitions(sfml PRIVATE CONFIG_DIR="${CMAKE_SOURCE_DIR}")

if(WIN32)
    target_link_libraries(sfml
        ${SFML_DIR}/lib/libsfml-graphics.a
        ${SFML_DIR}/lib/libsfml-window.a
        ${SFML_DIR}/lib/libsfml-system.a
        opengl32
        winmm
        gdi32
    )

    add_custom_command(TARGET sfml POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SFML_DIR}/bin
            $<TARGET_FILE_DIR:sfml>)
endif()