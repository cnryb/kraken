/*
 * Copyright (C) 2021 Alibaba Inc. All rights reserved.
 * Author: Kraken Team.
 */

#ifndef KRAKENBRIDGE_MODULE_MANAGER_H
#define KRAKENBRIDGE_MODULE_MANAGER_H

#include "js_context.h"

namespace kraken::binding::qjs {
void bindModuleManager(std::unique_ptr<JSContext> &context);
}

#endif // KRAKENBRIDGE_MODULE_MANAGER_H
