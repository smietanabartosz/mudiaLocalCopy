target_compile_definitions(
   board-config
      INTERFACE
   PROJECT_CONFIG_USER_DYNMEM_SIZE=9*1024*1024
   HW_SDRAM_64_MB=0
)

set (MEMORY_LINKER_FILE_PATH "${CMAKE_CURRENT_LIST_DIR}/memory_bell_P1.ld" CACHE INTERNAL "")
