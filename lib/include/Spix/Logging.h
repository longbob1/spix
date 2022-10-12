#pragma once
#include <functional>
#include <string>

namespace spix {
namespace logging {
    using LoggingCallbackT = std::function<void(const std::string&)>;

    void setLoggingCallback(LoggingCallbackT callback);
    void log(const std::string& msg);
}
}