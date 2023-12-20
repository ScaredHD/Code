#pragma once

#include <fstream>
#include <iostream>

#define STR(x) #x

class Logger {
  public:
    template <typename... Ts>
    static void log(const Ts&... args) {
        std::ofstream logfile{filename, std::ios_base::app};
        if (logfile.fail()) {
            std::cerr << "Can't open log file\n";
            return;
        }

        ((logfile << args), ...);
        logfile << "\n";
    }

  private:
    static inline const std::string filename{"debug_log.txt"};
};

#ifdef NDEBUG
#define LOG(...) ((void)0)
#else
#define LOG(...) Logger::log("[", __func__, "] ", __VA_ARGS__)
#endif

#define FORCE_LOG(...) Logger::log("[", __func__, "]  ", __VA_ARGS__)