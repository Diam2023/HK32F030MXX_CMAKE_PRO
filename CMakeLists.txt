cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE hk32-toolchain.cmake)
project(T12)
enable_language(ASM)

set(CMAKE_MAKE_PROGRAM CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE C_SOURCES CONFIGURE_DEPENDS
  Src/*.c
  Src/*.cc
  CMSIS/CM0/Core/*.c
  CMSIS/HK32F030M/Source/*.c
  HK32F030M_Lib/src/*.c)

add_executable(${CMAKE_PROJECT_NAME}.elf ${C_SOURCES} startup_hk32f030MF4P6.s)

target_include_directories(${CMAKE_PROJECT_NAME}.elf PRIVATE
  Inc
  CMSIS/CM0/Core
  CMSIS/HK32F030M/Include
  HK32F030M_Lib/inc)

target_compile_definitions(${CMAKE_PROJECT_NAME}.elf PRIVATE
  # USE_FULL_ASSERT
  HK32F030MF4P6)

set(MCU_FLAGS -mcpu=cortex-m0 -mthumb)

target_compile_options(${CMAKE_PROJECT_NAME}.elf PRIVATE ${MCU_FLAGS})
target_link_options(${CMAKE_PROJECT_NAME}.elf PRIVATE ${MCU_FLAGS}
  -T ${PROJECT_SOURCE_DIR}/HK32F030MF4P6_FLASH.ld)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -Oihex ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex
  COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin
  COMMENT "Invoking: Cross ARM GNU Print Size"
  COMMAND ${CMAKE_SIZE} --format=berkeley ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex)
