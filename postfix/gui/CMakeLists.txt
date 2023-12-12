set(target ${postfixgui}postfix_gui)
set(nameMain "Main")

file(GLOB hdrs "*.h*" "../../postfixlib/*.h*")
file(GLOB srcs "*.cpp" "../../postfixlib/*.cpp")
file(GLOB resx "*.resx")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:${nameMain}")
add_executable(${target} WIN32 ${srcs} ${hdrs} ${resx}) 
target_link_libraries(${target}) 
set_target_properties(${target} PROPERTIES
    VS_DOTNET_REFERENCES "System;System.Data;System.Drawing;System.Windows.Forms;System.Xml"
    VS_GLOBAL_ROOTNAMESPACE ${target}
    COMMON_LANGUAGE_RUNTIME ""
    CMAKE_VS_TARGET_FRAMEWORK_VERSION "v4.7.2"
)

