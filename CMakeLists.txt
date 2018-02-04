cmake_minimum_required(VERSION 3.5)
project(sir)

set(SOURCES src/main.cpp src/strjob.cpp src/ftpcheck.cpp)

add_executable(sir ${SOURCES})

include_directories(include /usr/include/)
link_directories(/usr/lib/x86_64-linux-gnu/)
target_link_libraries(sir curlpp curl)
add_definitions('-D_GLIBCXX_USE_CXX11_ABI=0')

