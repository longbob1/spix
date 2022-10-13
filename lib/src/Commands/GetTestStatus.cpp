/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "GetTestStatus.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

GetTestStatus::GetTestStatus(bool /*errorsOnly*/, std::promise<StatusStrings> promise)
: m_promise(std::move(promise))
{
}

void GetTestStatus::execute(CommandEnvironment& env)
{
    m_promise.set_value(env.state().errors());
}

std::string GetTestStatus::toString() const
{
    return "GetTestStatus";
}
} // namespace cmd
} // namespace spix
