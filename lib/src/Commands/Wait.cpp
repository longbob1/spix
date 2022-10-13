/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "Wait.h"
#include <sstream>

namespace spix {
namespace cmd {

Wait::Wait(std::chrono::milliseconds waitTime)
: m_waitTime(waitTime)
{
}

void Wait::execute(CommandEnvironment&)
{
}

bool Wait::canExecuteNow()
{
    if (!m_timerInitialized) {
        m_timerInitialized = true;
        m_startTime = std::chrono::steady_clock::now();
        return false;
    }

    auto timeSinceStart = std::chrono::steady_clock::now() - m_startTime;
    return timeSinceStart >= m_waitTime;
}

std::string Wait::toString() const
{
    std::stringstream sstream;
    sstream << "Wait: ";
    sstream << "waitTime: '" << m_waitTime.count() << "' ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
