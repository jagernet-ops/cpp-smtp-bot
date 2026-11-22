Configurable Discord to SMTP program
Noah Dinan
Michael Shalewski


libs
====

g++ -std=20 ...
cmake
dpp  # discord thing
conan
libcurl
json
sqlite
quill


config.json
================
{
    "smtp_url": "smtp://smtp.smtp.com",
    "smtp_pass": "password",
    "channels": [
        "channel",
        "channel2"
    ],
    "debounce_seconds": 60
}


message structure
=================

decide on the email structure
    add attachments as email attachments
    add text as email body
    custom sender? as email address


From: "Nick Name" <bob@bob>
To: "Noah Dinan" <noah@noah>
Subject: first number of words of message from Nick Name

Here's the whole message
:hotdog:

curl --ssl-reqd  -v
    --url "smtps://smtp.smtp.com"
    --user 'bob@bob:password'
    --mail-from 'bob@bob'
    --mail-rcpt 'bob@bob'
    --upload-file mail.txt


Behavior
========

"Watched Channels" table? -> bot sets watched channels in memory on startup


when someone DMs the bot, send an email with their username.

Put the person and message in the subject, for multiple people add several names in
the subject + channel name

when someone sends a message in a channel that the bot is in, start building an email..
keep building the email for 5 minutes and then send all messages that were sent in that time.

format multiple messages in RFC email standard for replies:

    NOAH: hello how are you?
    BOB: i'm doing terrible
    SARAH: noah? are you dead?
    NOAH: @noah wtf
    BOB: kms fr rn

    https://discordapp.com/url-to-message


commands can only be run by me.
bot can see any channels you give it access to:
/listen command flags a specific channel as readable, /forget undoes it

    /listen -> "Forwarding all messages in this channel to noah@noah"
    /forget -> "Messages in this channel are no longer forwarding to noah@noah"

commands update in-memory watch channels
