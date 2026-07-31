cmake_minimum_required(VERSION 3.10)
project(react-native-jsi-cpr)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PACKAGE_NAME "react-native-jsi-cpr")

find_package(fbjni REQUIRED CONFIG)
find_package(ReactAndroid REQUIRED CONFIG)
find_package(curl REQUIRED CONFIG)

add_library(
  ${PACKAGE_NAME}
  SHARED
  src/main/cpp/HttpHelper.cpp
  ../cpp/JsiHttp.cpp
  ../cpp/JsiUtils.cpp
  ../cpp/Logger.cpp
  ../cpp/cpr/accept_encoding.cpp
  ../cpp/cpr/async.cpp
  ../cpp/cpr/auth.cpp
  ../cpp/cpr/bearer.cpp
  ../cpp/cpr/cert_info.cpp
  ../cpp/cpr/cookies.cpp
  ../cpp/cpr/cprtypes.cpp
  ../cpp/cpr/curl_container.cpp
  ../cpp/cpr/curlholder.cpp
  ../cpp/cpr/curlmultiholder.cpp
  ../cpp/cpr/error.cpp
  ../cpp/cpr/file.cpp
  ../cpp/cpr/interceptor.cpp
  ../cpp/cpr/multipart.cpp
  ../cpp/cpr/multiperform.cpp
  ../cpp/cpr/parameters.cpp
  ../cpp/cpr/payload.cpp
  ../cpp/cpr/proxies.cpp
  ../cpp/cpr/proxyauth.cpp
  ../cpp/cpr/redirect.cpp
  ../cpp/cpr/response.cpp
  ../cpp/cpr/session.cpp
  ../cpp/cpr/ssl_ctx.cpp
  ../cpp/cpr/threadpool.cpp
  ../cpp/cpr/timeout.cpp
  ../cpp/cpr/unix_socket.cpp
  ../cpp/cpr/util.cpp
)

target_compile_definitions(
  ${PACKAGE_NAME}
  PRIVATE
  FOLLY_NO_CONFIG=1
  FOLLY_HAVE_CLOCK_GETTIME=1
  FOLLY_HAVE_MEMRCHR=1
  FOLLY_USE_LIBCPP=1
  FOLLY_MOBILE=1
  ON_ANDROID
  ONANDROID
)

target_include_directories(
  ${PACKAGE_NAME}
  PRIVATE
  src/main/cpp
  ../cpp
  ../cpp/include
)

find_library(LOG_LIB log)
find_library(Z_LIB z)

target_link_libraries(
  ${PACKAGE_NAME}
  fbjni::fbjni
  ReactAndroid::jsi
  ReactAndroid::reactnative
  curl::curl_static
  ${LOG_LIB}
  ${Z_LIB}
  android
)

target_compile_reactnative_options(${PACKAGE_NAME} PRIVATE)
