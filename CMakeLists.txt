cmake_minimum_required(VERSION 3.15)
project(smtpBot CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(dpp REQUIRED)
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(GTest REQUIRED)
find_package(quill REQUIRED)

add_executable(
    smtpBot
    src/main.cpp
    src/config/config.cpp
)
target_link_libraries(smtpBot dpp::dpp)
target_link_libraries(smtpBot CURL::libcurl)
target_link_libraries(smtpBot nlohmann_json::nlohmann_json)
target_link_libraries(smtpBot SQLiteCpp)
target_link_libraries(smtpBot gtest::gtest)
target_link_libraries(smtpBot quill::quill)
