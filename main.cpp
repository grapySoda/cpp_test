#include <iostream>
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

int main()
{
    std::string str;
    auto console_logger = spdlog::stdout_logger_mt("console");

    while (true) {
        std::cin >> str;
        console_logger->info(str);
    }

    return 0;
}
