#include <nlohmann/json.hpp>

using json = nlohmann::json;

class BotConfig {
private:
    std::string token;
    std::string smtp_url;
    std::string email;
    std::string smtp_pass;
    std::vector<std::string> channels;
    int debounce_seconds;

public:
    BotConfig(const std::string& path);
    std::string get_token();
    std::string get_smtp_url();
    std::string get_email();
    std::string get_smtp_pass();
    std::vector<std::string> get_channels();
    int get_debounce_seconds();
};
