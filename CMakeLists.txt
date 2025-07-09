cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_NAME bookmark)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройки FLTK (файлы в проекте)
set(FLTK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fltk")
include_directories(${FLTK_DIR}) # для поиска заголовочных файлов (папка FL)
link_directories(${FLTK_DIR}/lib/Release) # для поиска библиотек

add_executable(${PROJECT_NAME} src/main.cpp src/cipher.cpp src/gui.cpp)

# Подключение FLTK библиотек
target_link_libraries(${PROJECT_NAME} PRIVATE fltk fltk_images gdiplus ws2_32 comctl32)

# Для поиска заголовочных файлов (папка inc и папка с проектом)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR})