# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rbc_2023: 5 messages, 0 services")

set(MSG_I_FLAGS "-Irbc_2023:/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rbc_2023_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_custom_target(_rbc_2023_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rbc_2023" "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" ""
)

get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_custom_target(_rbc_2023_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rbc_2023" "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" ""
)

get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_custom_target(_rbc_2023_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rbc_2023" "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" ""
)

get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_custom_target(_rbc_2023_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rbc_2023" "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" ""
)

get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_custom_target(_rbc_2023_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rbc_2023" "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
)
_generate_msg_cpp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
)
_generate_msg_cpp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
)
_generate_msg_cpp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
)
_generate_msg_cpp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
)

### Generating Services

### Generating Module File
_generate_module_cpp(rbc_2023
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rbc_2023_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rbc_2023_generate_messages rbc_2023_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_cpp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_cpp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_cpp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_cpp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_cpp _rbc_2023_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rbc_2023_gencpp)
add_dependencies(rbc_2023_gencpp rbc_2023_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rbc_2023_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
)
_generate_msg_eus(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
)
_generate_msg_eus(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
)
_generate_msg_eus(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
)
_generate_msg_eus(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
)

### Generating Services

### Generating Module File
_generate_module_eus(rbc_2023
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(rbc_2023_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(rbc_2023_generate_messages rbc_2023_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_eus _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_eus _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_eus _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_eus _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_eus _rbc_2023_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rbc_2023_geneus)
add_dependencies(rbc_2023_geneus rbc_2023_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rbc_2023_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
)
_generate_msg_lisp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
)
_generate_msg_lisp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
)
_generate_msg_lisp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
)
_generate_msg_lisp(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
)

### Generating Services

### Generating Module File
_generate_module_lisp(rbc_2023
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rbc_2023_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rbc_2023_generate_messages rbc_2023_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_lisp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_lisp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_lisp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_lisp _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_lisp _rbc_2023_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rbc_2023_genlisp)
add_dependencies(rbc_2023_genlisp rbc_2023_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rbc_2023_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
)
_generate_msg_nodejs(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
)
_generate_msg_nodejs(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
)
_generate_msg_nodejs(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
)
_generate_msg_nodejs(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
)

### Generating Services

### Generating Module File
_generate_module_nodejs(rbc_2023
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(rbc_2023_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(rbc_2023_generate_messages rbc_2023_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_nodejs _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_nodejs _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_nodejs _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_nodejs _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_nodejs _rbc_2023_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rbc_2023_gennodejs)
add_dependencies(rbc_2023_gennodejs rbc_2023_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rbc_2023_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
)
_generate_msg_py(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
)
_generate_msg_py(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
)
_generate_msg_py(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
)
_generate_msg_py(rbc_2023
  "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
)

### Generating Services

### Generating Module File
_generate_module_py(rbc_2023
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rbc_2023_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rbc_2023_generate_messages rbc_2023_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/UI2node.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_py _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/node2UI.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_py _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/xy.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_py _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/recive.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_py _rbc_2023_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rbc/ros_work/rbc_ws/src/rbc_2023/msg/imu.msg" NAME_WE)
add_dependencies(rbc_2023_generate_messages_py _rbc_2023_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rbc_2023_genpy)
add_dependencies(rbc_2023_genpy rbc_2023_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rbc_2023_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rbc_2023
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rbc_2023_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rbc_2023
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(rbc_2023_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rbc_2023
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(rbc_2023_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rbc_2023
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(rbc_2023_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rbc_2023
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rbc_2023_generate_messages_py std_msgs_generate_messages_py)
endif()
