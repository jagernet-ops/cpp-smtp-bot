Configurable Discord to SMTP program
Michael Shalewski, Noah Dinan


Create an Application in Discord
================================
Navigate to the below URL to create your application in discord.
https://docs.discord.com/developers/quick-start/getting-started#step-1-creating-an-app

In your application, navigate to the 'OAuth2' tab
Generate a URL, selecting 'messages.read', 'bot', then in Bot Permissions
select 'View Channels', 'Use Slash Commands'.


Building
========

$ conan install . --build=missing -pr=./profiles/linux-gcc20-release
$ cmake --preset=conan-release
$ cmake --build --preset=conan-release

OR

$ make


Contributing
============

checkout a branch from 'master' like: 'feat/my-feature-branch'.

clearly specify which Bug(s), Planned Feature(s) you are tackling in your PR.
make sure you check off the bugs or features in 'readme.txt' too.

code review by one or more maintainers is required.


Planned Features
================
Tip: you can find relavent TODOs with `rg TODO-#`

0. [ ] miscellaneous stuff
1. [ ] use quill for logging
2. [x] read configuration from JSON (!4)


3. [ ] sending email notifications following some format
       message attachments should be added to the email.
       emojis should be converted to plaintext. example message below

       From: "Discord to SMTP" <noah@noah>
       To: "Noah Dinan" <noah@noah>
       Subject: [user1, user2, user3 in channel1] i wanted to go to a new restaur..

       channel1
       ========

       user1: i wanted to go to a new restaurant but i did not.
       user2: why?
       user1: i didn't have time
       user3: burgr
       user3: :burger:

       https://discordapp.com/url-to-message

       Note: must use CRLF for email file

       libcurl can be used to send the email:
           curl --ssl-reqd  -v
               --url "smtps://smtp.smtp.com"
               --user 'bob@bob:password'
               --mail-from 'bob@bob'
               --mail-rcpt 'bob@bob'
               --upload-file mail.txt


4. [ ] bot should only notify for watched channels.
       watch channels with a slash command.
       bot can see any channels you give it access to:
       /watch command flags a specific channel as readable, /forget undoes it

           /watch -> "Forwarding all messages in this channel to noah@noah"
           /forget -> "Messages in this channel are no longer forwarding to noah@noah"
           /channels  -> show all watched channels

       commands should ONLY be accessible to YOU.

5. [ ] debounce for many messages in a channel.
       when someone sends a message in a channel that the bot is watching,
       start building an email.. keep building the email for 60 seconds by default
       and then send all messages that were sent in that time.

6. [ ] CI pipeline to check for format / compile issues in PR.


Bugs
====
A. Bot reads messages from itself
