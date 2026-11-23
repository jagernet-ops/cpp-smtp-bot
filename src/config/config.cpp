#include "config.hpp"
#include <format>
#include <fstream>
#include <iostream>

Config::Config(std::string path) {
  std::ifstream f(path);

  if (!f.good()) {
    std::cout << std::format("Cannot find '{}'", path) << std::endl;
    exit(1);
  }

  try {
    config = json::parse(f);
  } catch (json::exception j) {
    std::cout << j.what() << std::endl;
    exit(1);
  }
}

std::string Config::get(std::string key) {
  if (config != nullptr && config.contains(key)) {
    return config[key];
  }
  return "";
}
