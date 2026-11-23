#include "BotConfig.hpp"
#include <format>
#include <fstream>
#include <iostream>

BotConfig::BotConfig(std::string path) {
  std::ifstream f(path);

  if (!f.good()) {
    std::cout << std::format("Cannot find '{}'", path) << std::endl;
    exit(1);
  }

  try {
    auto config = json::parse(f);
    token = config["token"];
    smtp_url = config["smtp_url"];
    email = config["email"];
    smtp_pass = config["smtp_pass"];
    channels = config["channels"];
    debounce_seconds = config["debounce_seconds"];
    f.close();
  } catch (json::exception j) {
    std::cout << j.what() << std::endl;
    f.close();
    exit(1);
  }
}

std::string BotConfig::get_token() { return token; }
std::string BotConfig::get_smtp_url() { return smtp_url; }
std::string BotConfig::get_email() { return email; }
std::string BotConfig::get_smtp_pass() { return smtp_pass; }
std::vector<std::string> BotConfig::get_channels() { return channels; }
int BotConfig::get_debounce_seconds() { return debounce_seconds; }
