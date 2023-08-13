# project(tempsense)

# rest of your project
add_executable(tempsense
    main.c
    dht22-pico.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(tempsense 1)
pico_enable_stdio_uart(tempsense 0)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(
    tempsense 
    pico_stdlib 
    pico_cyw43_arch_none
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(tempsense)