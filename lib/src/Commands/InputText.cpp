/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "InputText.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

InputText::InputText(ItemPath path, std::string text)
: m_path(std::move(path))
, m_text(std::move(text))
{
}

void InputText::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (item) {
        env.scene().events().stringInput(item.get(), m_text);
    } else {
        env.state().reportError("InputText: Item not found: " + m_path.string());
    }
}

std::string InputText::toString() const
{
    std::stringstream sstream;
    sstream << "InputText: ";
    sstream << "path: {" << m_path.string() << "} ";
    sstream << "text: '" << m_text << "' ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
