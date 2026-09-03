# Bit Bang drivers

target_sources(${PROJECT_NAME}
    PRIVATE
        src/bbspi.c
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS/Include/
        ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS/Device/ST/STM32F4xx/Include
)
