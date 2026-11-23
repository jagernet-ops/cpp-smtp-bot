#include "config.cpp"
#include <dpp/dpp.h>

int main() {
  auto config = load_config();
  dpp::cluster bot(config["token"]);

  // logger
  bot.on_log(dpp::utility::cout_logger());

  // message that is viewable by the bot
  bot.on_message_create([](const dpp::message_create_t &event) {
    std::string content = event.msg.content;
    std::string author = event.msg.author.global_name;

    // TODO: should only be this bot...
    if (event.msg.author.is_bot()) {
      return;
    }

    if (event.msg.is_dm()) {
      event.reply(std::format("you said '{}'", content));
    } else {
      event.reply(std::format("{} said '{}'", author, content));
    }
  });

  bot.start(dpp::st_wait);
}
