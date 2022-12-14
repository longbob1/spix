/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "DropFromExt.h"

#include <CommandExecuter/CommandEnvironment.h>
#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

DropFromExt::DropFromExt(ItemPath path, PasteboardContent content)
: m_path(std::move(path))
, m_content(std::move(content))
{
}

void DropFromExt::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (!item) {
        env.state().reportError("DropFromExt: Item not found: " + m_path.string());
        return;
    }

    auto size = item->size();
    Point midPoint(size.width / 2.0, size.height / 2.0);
    env.scene().events().extMouseDrop(item.get(), midPoint, m_content);
}

std::string DropFromExt::toString() const
{
    std::stringstream sstream;
    sstream << "DropFromExt: ";
    sstream << "path: {" << m_path.string() << "} ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
