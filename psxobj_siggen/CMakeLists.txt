# Platform agnostic sources
set(SOURCE_FILES
    "FuncSignature.cpp"
    "FuncSignature.h"
    "Main.cpp"
    "ObjFileData.h"
    "ObjFileParser.cpp"
    "ObjFileParser.h"
)

set(OTHER_FILES
)

# Build the executable and setup IDE folders
add_executable(${PSXOBJ_SIGGEN_TGT_NAME} ${SOURCE_FILES} ${OTHER_FILES})
setup_source_groups("${SOURCE_FILES}" "${OTHER_FILES}")

# Setup target dependencies and compile options
target_link_libraries(${PSXOBJ_SIGGEN_TGT_NAME} ${REVERSING_COMMON_TGT_NAME})
add_common_target_compile_options(${PSXOBJ_SIGGEN_TGT_NAME})
