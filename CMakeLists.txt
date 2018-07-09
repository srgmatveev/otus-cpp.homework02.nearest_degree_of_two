cmake_minimum_required(VERSION 3.9)

if($ENV{TRAVIS_BUILD_NUMBER})
    project(nearest_degree_of_two VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(nearest_degree_of_two VERSION 0.0.1)
endif()

find_package(Boost REQUIRED)

configure_file(version.h.in version.h)



add_executable(nearest_degree_of_two main.cpp)


set_target_properties(nearest_degree_of_two PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

target_link_libraries(nearest_degree_of_two
        ${Boost_LIBRARIES}
        )


install(TARGETS nearest_degree_of_two RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT srgmatveev@gmail.com)

include (CPack)

