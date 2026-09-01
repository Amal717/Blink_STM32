add_library(hal STATIC)

target_sources(hal
    PRIVATE
        src/clock.c
        src/pinmux.c
        src/gpio.c
        src/uart.c
        src/gpio_types.c
)

target_include_directories(hal
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS/Include/
    ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS/Device/ST/STM32F4xx/Include
)

target_compile_definitions(hal
    PUBLIC
        STM32F407xx
)
