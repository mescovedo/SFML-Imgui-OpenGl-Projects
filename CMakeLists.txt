cmake_minimum_required(VERSION 4.0)
project(imguiProjects)

set(CMAKE_CXX_STANDARD 20)

# --- Paths ---
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/external/glfw)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
set(JSON_DIR ${CMAKE_SOURCE_DIR}/external/json)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/external/sfml)
set(IMGUI_SFML_DIR ${CMAKE_SOURCE_DIR}/external/imgui-sfml)
set(MINGW_BIN "${CMAKE_SOURCE_DIR}/external/mingw/bin")

# --- Default build type ---
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

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
target_include_directories(openGl PRIVATE ${GLFW_DIR}/include ${JSON_DIR}/include)
target_compile_definitions(openGl PRIVATE CONFIG_DIR="${CMAKE_SOURCE_DIR}")

# Link libraries
target_link_libraries(openGl PRIVATE imgui ${GLFW_DIR}/lib/libglfw3.a opengl32 gdi32)

# Enable warnings for your code only
if (MSVC)
    target_compile_options(openGl PRIVATE /W4 /permissive-)
else()
    target_compile_options(openGl PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

# --- SFML target ---
add_executable(sfml
    sfml/main.cpp
    sfml/CircleConfig.cpp
    sfml/RectangleConfig.cpp
    sfml/TriangleConfig.cpp
    sfml/SquareConfig.cpp
    sfml/shapeFactory.cpp
)

target_include_directories(sfml PRIVATE ${JSON_DIR}/include ${SFML_DIR}/include sfml)
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

# --- Optional static MinGW runtime ---
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()

# --- Subsystem WINDOWS / CONSOLE depending on build type ---
if(WIN32)
    if(MINGW)
        if(CMAKE_BUILD_TYPE STREQUAL "Debug")
            # Debug → console
            target_link_options(sfml PRIVATE "")
        else()
            # Release → GUI only
            target_link_options(sfml PRIVATE "-mwindows")
        endif()
    else()
        # MSVC: keep the original /SUBSYSTEM flag
        if(CMAKE_BUILD_TYPE STREQUAL "Debug")
            set_target_properties(sfml PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
        else()
            set_target_properties(sfml PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
        endif()
    endif()
endif()

# --- Copy SFML DLLs and MinGW runtime DLLs after build ---
if(WIN32)
    # Copy SFML DLLs
    add_custom_command(TARGET sfml POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SFML_DIR}/bin
        $<TARGET_FILE_DIR:sfml>
    )

    # Copy MinGW runtime DLLs
    if(MINGW)
        set(MINGW_DLLS
                ${MINGW_BIN}/libgcc_s_seh-1.dll
                ${MINGW_BIN}/libstdc++-6.dll
                ${MINGW_BIN}/libwinpthread-1.dll
        )
        foreach(dll ${MINGW_DLLS})
            add_custom_command(TARGET sfml POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${dll} $<TARGET_FILE_DIR:sfml>
            )
        endforeach()
    endif()
endif()

# --- Install rules (for distribution) ---
install(TARGETS sfml
    RUNTIME DESTINATION bin
)
install(DIRECTORY resources/ DESTINATION bin/resources)

# Copy SFML DLLs for install
if(WIN32)
    install(DIRECTORY ${SFML_DIR}/bin/ DESTINATION bin FILES_MATCHING PATTERN "*.dll")
endif()
