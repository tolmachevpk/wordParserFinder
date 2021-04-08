cmake_minimum_required(VERSION 3.17)
project(wordParserFinder)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5Widgets REQUIRED)

add_executable(wordParserFinder Sources/main.cpp Headers/trie.h Sources/trie.cpp Headers/structTrie.h Headers/parser.h Sources/parser.cpp Headers/ahoKorasik.h Sources/ahoKorasik.cpp Headers/mainWindow.h Sources/mainWindow.cpp)

target_link_libraries(wordParserFinder Qt5::Widgets)