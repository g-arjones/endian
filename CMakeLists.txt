cmake_minimum_required(VERSION 3.5)
project(Endian VERSION 0.1)

add_library(endian STATIC
  src/be_uint16_t.cpp
  src/le_uint16_t.cpp
)

include_directories(include)

configure_file(endian-config.cmake.in endian-config.cmake @ONLY)

enable_testing()

function(endian_add_test TEST_NAME)
  add_executable(test_${TEST_NAME}
    test/test_${TEST_NAME}.cpp
  )

  target_link_libraries(test_${TEST_NAME} endian)

  add_test(
    NAME test_${TEST_NAME}
    COMMAND test_${TEST_NAME}
  )
endfunction()

endian_add_test(be_uint16_t)
endian_add_test(le_uint16_t)

install(
  TARGETS endian
  ARCHIVE DESTINATION lib
)

install(
  DIRECTORY include/endian
  DESTINATION include
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/endian-config.cmake
  DESTINATION share/Endian/cmake)

