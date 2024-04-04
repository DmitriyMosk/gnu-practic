cmake_minimum_required(VERSION 3.27)
# Check version

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/gnu_ui/pract.ui DESTINATION ${CMAKE_BINARY_DIR}/gnu_ui)

project(Practice C)
#Project

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES main.c
        include/FileIO.h
        include/gtkMenu.h
        include/smartphone.h
        gtkMenu/gtk_Open.c
        smartphone/sm_InitSmartphones.c
        smartphone/sm_StoreSmartphone.c
        smartphone/sm_PrintSmartphones.c
        smartphone/sm_PrintSmartphone.c
        smartphone/sm_SaveSmartphoneList.c
        smartphone/sm_OpenSmartphoneList.c
        FileIO/FileIO_FileExists.c
        FileIO/FileIO_End.c
        FileIO/FileIO_Write.c
        FileIO/FileIO_Read.c
        gtkMenu/gtk_Activate.c
        gtkMenu/gtk_Events.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)
add_definitions(-I${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES})