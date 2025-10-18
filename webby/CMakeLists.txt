set(LIB_NAME ${PROJECT_NAME}-lib)

# Adding library
file(GLOB_RECURSE LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(${LIB_NAME} STATIC ${LIB_SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)

include(FetchContent)
FetchContent_Declare(
        httplib
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
        GIT_TAG v0.26.0
)
FetchContent_MakeAvailable(httplib)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

target_link_libraries(${LIB_NAME} PUBLIC nlohmann_json::nlohmann_json httplib)

set(SWAGGER_JSON_PATH "${CMAKE_BINARY_DIR}/swagger.json")
target_compile_definitions(${LIB_NAME} PUBLIC SWAGGER_JSON_PATH="${SWAGGER_JSON_PATH}")

