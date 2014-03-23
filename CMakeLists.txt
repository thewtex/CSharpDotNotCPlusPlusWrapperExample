cmake_minimum_required( VERSION 2.8 )

project( ClassLibrary1 )

#list( INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake )


include_directories( include ${PROJECT_BINARY_DIR} )

if(CMAKE_CXX_FLAGS_DEBUG MATCHES "/RTC1")
  string(REPLACE "/RTC1" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

if(CMAKE_CXX_FLAGS MATCHES "/EHsc")
  string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

add_executable( Class1Exe src/Class1Exe.cxx )
set_target_properties( Class1Exe PROPERTIES COMPILE_FLAGS "/clr /EHa" )
include(GenerateExportHeader)
add_library( ClassLibrary1Wrapper SHARED src/Class1Wrapper.cxx )
set_target_properties( ClassLibrary1Wrapper PROPERTIES COMPILE_FLAGS "/clr /EHa" )
generate_export_header( ClassLibrary1Wrapper 
  BASE_NAME ClassLibrary1Wrapper
  EXPORT_MACRO_NAME ClassLibrary1Wrapper_EXPORT
  EXPORT_FILE_NAME ClassLibrary1Wrapper_Export.h
  )

add_executable( ClassLibrary1WrapperTest test/ClassLibrary1WrapperTest.cxx )
target_link_libraries( ClassLibrary1WrapperTest ClassLibrary1Wrapper )
set_target_properties( ClassLibrary1WrapperTest PROPERTIES COMPILE_FLAGS "/EHsc" )
enable_testing()
add_test( NAME ClassLibrary1WrapperTest COMMAND $<TARGET_FILE:ClassLibrary1WrapperTest> )
