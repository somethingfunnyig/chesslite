cmake_minimum_required(VERSION 4.2)
project(chesslite)

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(chesslite
        "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

# ==========================================
# INCLUDE DIRECTORIES
# ==========================================

target_include_directories(chesslite PRIVATE
    #${PROJECT_SOURCE_DIR}/extern/wgpu-native/include
    #${PROJECT_SOURCE_DIR}/extern/wgpu-native
    #${PROJECT_SOURCE_DIR}/extern/glfw/include
    #${PROJECT_SOURCE_DIR}/extern/entt/include
    #${PROJECT_SOURCE_DIR}/extern/spdlog/include
    ${PROJECT_SOURCE_DIR}/extern/sfml/include
)

target_link_options(chesslite PRIVATE
    -static-libgcc
    -static-libstdc++
    -Wl,-Bstatic -lpthread -Wl,-Bdynamic
)

# ==========================================
# LIBRARIES
# ==========================================

# Gather all library files from the SFML lib directory
file(GLOB SFML_LIBRARIES
    "${PROJECT_SOURCE_DIR}/extern/sfml/lib/*.lib"
    "${PROJECT_SOURCE_DIR}/extern/sfml/lib/*.a"
    "${PROJECT_SOURCE_DIR}/extern/sfml/lib/*.so"
    "${PROJECT_SOURCE_DIR}/extern/sfml/lib/*.dylib"
)

target_link_libraries(chesslite PRIVATE
    ${SFML_LIBRARIES}
    #"${PROJECT_SOURCE_DIR}/extern/wgpu-native/libwgpu_native.dll.a"
)

# Automatically copy SFML DLLs to the output directory on Windows
file(GLOB SFML_DLLS "${PROJECT_SOURCE_DIR}/extern/sfml/bin/*.dll")
add_custom_command(TARGET chesslite POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DLLS} $<TARGET_FILE_DIR:chesslite>)


# ==========================================
# DEBUG
# ==========================================

get_target_property(INC_DIRS chesslite INCLUDE_DIRECTORIES)
message(STATUS "Include dirs: ${INC_DIRS}")