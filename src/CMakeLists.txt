set(SOURCES
    main.cpp
    binaryTree.cpp
    node.cpp
    stockPriceMovement.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCES})