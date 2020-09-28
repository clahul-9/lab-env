#--------------------------------------------------------------------------
# example project
#--------------------------------------------------------------------------

PROJECT(Mesh resources)
FILE(GLOB example_headers code/*.h)
FILE(GLOB example_sources code/*.cc)
FILE(GLOB example_sources code/*.cpp)

SET(files_example ${example_headers} ${example_sources})
SOURCE_GROUP("example" FILES ${files_example})

ADD_EXECUTABLE(Mesh resources ${files_example})
TARGET_LINK_LIBRARIES(Mesh resources core render)
ADD_DEPENDENCIES(Mesh resources core render)