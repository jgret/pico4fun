set(NAME square_wave) # <--- set name here

add_executable(${NAME})

# generate header file with compiled pio program
pico_generate_pio_header(${NAME} ${CMAKE_CURRENT_LIST_DIR}/wave.pio)

target_sources(${NAME} PRIVATE main.c) # <--- add c files here

target_link_libraries(${NAME} PRIVATE
    pico_stdlib
    hardware_pio
                # <--- add libraries here
)

pico_add_extra_outputs(${NAME})