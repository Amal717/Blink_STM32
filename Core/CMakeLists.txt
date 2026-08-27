add_library(Core STATIC)

target_sources(Core
    PRIVATE
        Src/system_stm32f4xx.c
        Src/led.c
)

target_include_directories(Core
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(Core
    PUBLIC
        hal
)
