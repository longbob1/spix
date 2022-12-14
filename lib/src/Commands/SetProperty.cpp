/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "SetProperty.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

SetProperty::SetProperty(ItemPath path, std::string propertyName, std::string propertyValue)
: m_path(std::move(path))
, m_propertyName(std::move(propertyName))
, m_propertyValue(std::move(propertyValue))
{
}

void SetProperty::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (item) {
        item->setStringProperty(m_propertyName, m_propertyValue);
    } else {
        env.state().reportError("SetProperty: Item not found: " + m_path.string());
    }
}

std::string SetProperty::toString() const
{
    std::stringstream sstream;
    sstream << "Screenshot: ";
    sstream << "itemPath: {" << m_path.string() << "} ";
    sstream << "propertyName: '" << m_propertyName << "' ";
    sstream << "propertyValue: '" << m_propertyValue << "' ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
