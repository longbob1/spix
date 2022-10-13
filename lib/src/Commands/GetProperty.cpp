/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "GetProperty.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

GetProperty::GetProperty(ItemPath path, std::string propertyName, std::promise<std::string> promise)
: m_path(std::move(path))
, m_propertyName(std::move(propertyName))
, m_promise(std::move(promise))
{
}

void GetProperty::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (item) {
        auto value = item->stringProperty(m_propertyName);
        m_promise.set_value(value);
    } else {
        m_promise.set_value("");
        env.state().reportError("GetProperty: Item not found: " + m_path.string());
    }
}

std::string GetProperty::toString() const
{
    std::stringstream sstream;
    sstream << "GetProperty: ";
    sstream << "path: {" << m_path.string() << "} ";
    sstream << "propertyName: '" << m_propertyName << "' ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
