#--------------------------------------------------------------------------
# example project
#--------------------------------------------------------------------------

PROJECT(Mesh_resources)
FILE(GLOB example_headers code/*.h)
FILE(GLOB example_sources code/*.cc)
FILE(GLOB example_sources code/*.cpp)

SET(files_example ${Mesh_resources_headers} ${example_sources})
SOURCE_GROUP("example" FILES ${files_example})

ADD_EXECUTABLE(Mesh_resources ${files_example})
TARGET_LINK_LIBRARIES(Mesh_resources core render)
ADD_DEPENDENCIES(Mesh_resources core render)