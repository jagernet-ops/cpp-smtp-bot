#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json load_config() {
  std::ifstream f("config.json");

  if (!f.good()) {
    std::cout << "Cannot find 'config.json'" << std::endl;
    exit(1);
  }

  try {
    json j = json::parse(f);
    return j;
  } catch (json::exception j) {
    std::cout << "Invalid json in 'config.json'" << std::endl;
    std::cout << j.what() << std::endl;
    exit(1);
  }
}
