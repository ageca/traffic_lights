add_executable(traffic_lights traffic_lights.c
                              lights.c
                              sensor.c
                              periodic.c)

target_link_libraries(traffic_lights pthread rt)