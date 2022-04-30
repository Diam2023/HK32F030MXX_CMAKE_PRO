set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(TOOLCHAIN_PREFIX "arm-none-eabi-")
set(CMAKE_C_COMPILER "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}g++")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_OBJCOPY "${TOOLCHAIN_PREFIX}objcopy")
set(CMAKE_SIZE "${TOOLCHAIN_PREFIX}size")

add_compile_options(
  -Wall -fdata-sections -ffunction-sections
  $<$<COMPILE_LANGUAGE:ASM>:-x> $<$<COMPILE_LANGUAGE:ASM>:assembler-with-cpp>
  $<$<CONFIG:Debug>:-Og> $<$<CONFIG:Debug>:-g>
  $<$<CONFIG:Release>:-Os>)

add_link_options(
  --specs=nano.specs
  --specs=nosys.specs
  -lc -lm -lnosys
  -Wl,--gc-sections,--print-memory-usage,-Map=${CMAKE_PROJECT_NAME}.map,--cref)
