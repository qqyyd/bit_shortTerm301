#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include "chatform.h"

static QMap<QString, ChatForm*> NameToChatForm; // key: friendName value: ChatForm
static QMap<ChatForm*, QString> ChatFormToName; // key: ChatForm   value: friendName

#endif // GLOBAL_H
