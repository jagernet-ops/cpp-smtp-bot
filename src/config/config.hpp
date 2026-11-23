#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Config {
private:
  json config = nullptr;

public:
  Config(std::string path);
  std::string get(std::string key);
};
