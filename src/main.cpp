#include "BotConfig/BotConfig.hpp"
#include <dpp/dpp.h>

const std::string CONFIG_JSON_PATH = "config.json";

int main()
{
    // TODO-0: handle exceptions for config loading
    auto config = BotConfig(CONFIG_JSON_PATH);

    dpp::cluster bot(config.get_token(), dpp::i_default_intents | dpp::i_message_content);

    // TODO-1: use quill logger
    bot.on_log(dpp::utility::cout_logger());

    bot.on_message_create([](const dpp::message_create_t& event) {
        std::string content = event.msg.content;
        std::string author = event.msg.author.global_name;

        // TODO-A: bot should return if message is from itself
        if (event.msg.author.is_bot()) {
            return;
        }

        if (event.msg.is_dm()) {
            event.reply(std::format("you said '{}'", content));
        }
        else {
            event.reply(std::format("{} said '{}'", author, content));
        }
    });

    bot.start(dpp::st_wait);
}
