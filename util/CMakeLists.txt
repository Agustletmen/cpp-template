file(GLOB SRC_CODE
        "./math/*.h"
        "./math/*.hpp"
        "./math/*.cpp"
        "./math/*.cxx"
        "./math/*.c"
        "./math/*.cc"
)

add_library(util STATIC ${SRC_CODE})

# 强制指定链接语言（防止CMake误判）
set_target_properties(util PROPERTIES
        LINKER_LANGUAGE CXX  # 假设是C++代码，若是C则改为C
)