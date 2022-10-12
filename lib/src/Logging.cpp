#include <Spix/Logging.h>

namespace {
    spix::logging::LoggingCallbackT gLoggingCallback;
}

namespace spix {
namespace logging {
    void setLoggingCallback(LoggingCallbackT callback) {
        gLoggingCallback = callback;
    }

    void log(const std::string& msg) {
        if (!gLoggingCallback)
            return;
		
        gLoggingCallback(msg);
    }
}
}