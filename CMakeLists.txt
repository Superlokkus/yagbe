cmake_minimum_required(VERSION 3.7)
project(yagbe VERSION 0.1)

set(TEST_ENABLED TRUE CACHE BOOL "Tests are enabled")
if (${TEST_ENABLED})
    enable_testing()
endif ()

add_subdirectory(${PROJECT_SOURCE_DIR}/src/yagbe_core)

add_executable(${PROJECT_NAME} src/main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} PRIVATE yagbe_core)

if (${TEST_ENABLED})
    find_package(Boost COMPONENTS system REQUIRED)
    set(${PROJECT_NAME}_test_src
            ${CMAKE_CURRENT_SOURCE_DIR}/test/general_tests.cpp
            )
    foreach (testSrc ${${PROJECT_NAME}_test_src})
        get_filename_component(testName ${testSrc} NAME_WE)
        add_executable(${PROJECT_NAME}_${testName} ${testSrc})
        set_property(TARGET ${PROJECT_NAME}_${testName} PROPERTY CXX_STANDARD 17)
        target_link_libraries(${PROJECT_NAME}_${testName} Boost::boost yagbe_core)
        add_test(NAME ${PROJECT_NAME}_${testName} COMMAND ${PROJECT_NAME}_${testName} -m HRF -l warning --build_info)
    endforeach (testSrc)
endif ()

install(TARGETS ${PROJECT_NAME}
        RUNTIME
        DESTINATION bin)

include(CPack)
