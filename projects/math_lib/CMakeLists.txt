#--------------------------------------------------------------------------
# example project
#--------------------------------------------------------------------------

PROJECT(mathlib)
FILE(GLOB example_headers code/*.h)
FILE(GLOB example_sources code/*.cc)
FILE(GLOB example_sources code/*.cpp)

SET(files_example ${example_headers} ${example_sources})
SOURCE_GROUP("example" FILES ${files_example})

ADD_EXECUTABLE(mathlib ${files_example})
TARGET_LINK_LIBRARIES(mathlib core render)
ADD_DEPENDENCIES(mathlib core render)