/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "ExistsAndVisible.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

ExistsAndVisible::ExistsAndVisible(ItemPath path, std::promise<bool> promise)
: m_path(std::move(path))
, m_promise(std::move(promise))
{
}

void ExistsAndVisible::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (item) {
        m_promise.set_value(item->visible());
    } else {
        m_promise.set_value(false);
    }
}

std::string ExistsAndVisible::toString() const
{
    std::stringstream sstream;
    sstream << "ExistsAndVisible: ";
    sstream << "path: {" << m_path.string() << "} ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
