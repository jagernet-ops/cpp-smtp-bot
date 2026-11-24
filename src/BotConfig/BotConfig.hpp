#include <nlohmann/json.hpp>

using json = nlohmann::json;

/*
 * BotConfig loads JSON config file and provides
 * access to values.
 */
class BotConfig {
private:
    std::string token;
    std::string smtp_url;
    std::string smtp_pass;
    std::string email;
    std::vector<std::string> channels;
    int debounce_seconds;

public:
    BotConfig(const std::string& path);
    /* Discord App Token */
    std::string get_token();

    /* Like: smtps://smtp.example.org */
    std::string get_smtp_url();
    std::string get_smtp_pass();

    /* Your email */
    std::string get_email();

    /* Channels to listen to */
    std::vector<std::string> get_channels();

    /* Seconds to wait before sending email for consecutive messages */
    int get_debounce_seconds();
};
