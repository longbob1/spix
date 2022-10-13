/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#pragma once

#include "Command.h"
#include <Spix/Data/ItemPath.h>

#include <future>

namespace spix {
namespace cmd {

class GetGlobalPosition : public Command {
public:
    GetGlobalPosition(ItemPath path, std::promise<std::string> promise);

    void execute(CommandEnvironment& env) override;
    std::string toString() const override;

private:
    ItemPath m_path;
    std::promise<std::string> m_promise;
};

} // namespace cmd
} // namespace spix
