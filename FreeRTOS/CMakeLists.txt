# FreeRTOS/CMakeLists.txt
add_library(FreeRTOS)

target_sources(FreeRTOS
    PRIVATE
        kernel/croutine.c
        kernel/event_groups.c
        kernel/list.c
        kernel/queue.c
        kernel/stream_buffer.c
        kernel/tasks.c
        kernel/timers.c
        portable/${FreeRTOS_PORT}/port.c
        portable/MemMang/${FreeRTOS_HEAP}.c
)

target_include_directories(FreeRTOS
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
