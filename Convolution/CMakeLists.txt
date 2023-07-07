cmake_minimum_required(VERSION 3.0.0)
project(LearnBANG-Convolution VERSION 0.1.0 LANGUAGES C CXX)


# 设置 NEUWARE_HOME 变量
set(NEUWARE_HOME "/usr/local/neuware")
# 设置使用 c++ 11 版本
set(CMAKE_CXX_STANDARD 11)
#include_directories("${PROJECT_SOURCE_DIR}/include")

# 如果存在 NEUWARE_HOME 那么就设置相应的 头文件目录、库文件目录
if(EXISTS ${NEUWARE_HOME})
  include_directories("${NEUWARE_HOME}/include")
  include_directories("${NEUWARE_HOME}/lib/clang/5.0.1/include")
  link_directories("${NEUWARE_HOME}/lib64")
  link_directories("${NEUWARE_HOME}/lib")
  set(NEUWARE_ROOT_DIR "${NEUWARE_HOME}")
  
else()
  message(FATAL_ERROR "NEUWARE directory cannot be found, refer README.md to prepare NEUWARE_HOME environment.")
endif()

# 设置 cmake 查找 BANG 的.cmake文件目录
# setup cmake search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake"
  "${NEUWARE_HOME}/cmake"
  "${NEUWARE_HOME}/cmake/modules"
)

# 查找 BANG 
find_package(BANG)

if(NOT BANG_FOUND)
  message(FATAL_ERROR "BANG cannot be found.")
elseif (NOT BANG_CNCC_EXECUTABLE)
  message(FATAL_ERROR "cncc not found, please ensure cncc is in your PATH env or set variable BANG_CNCC_EXECUTABLE from cmake. Otherwise you should check path used by find_program(BANG_CNCC_EXECUTABLE) in FindBANG.cmake")
else()
  #message(STATUS "Found BANG.")
  # 设置 cncc 编译器参数
  set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} -O2 -g")
  #set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} -fPIC -pthread -Wall")
  set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} -fPIC -Wall")
  #set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} --bang-mlu-arch=mtp_220")
  set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} --bang-mlu-arch=mtp_270")
  # 设置 CNCC 的 c++ 版本
  set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} -std=c++17")
  #set(BANG_CNCC_FLAGS "${BANG_CNCC_FLAGS} --bang-mlu-arch=mtp_290")
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/local/neuware/lib64/ -lcnrt")
  set(BANG_EXIST ON)
endif()

# 使用 cncc 编译器编译 main.mlu
bang_add_executable(LearnBANG-Convolution main.mlu)

# 链接需要用的到 cnrt cnnl 库
#target_link_libraries(LearnBANG-Convolution cnrt pthread)
target_link_libraries(LearnBANG-Convolution cnrt cnnl)

