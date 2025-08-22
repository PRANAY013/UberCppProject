#include <drogon/drogon.h>
#include "interfaces/rest/RideController.h"

int main()
{
    // Start the server
    std::cout << "Starting server on 127.0.0.1:8848" << std::endl;
    drogon::app().loadConfigFile("/Users/pranay/Pranay/PROG/UberCppProject/build/config.json");
    drogon::app().addListener("127.0.0.1", 8848);
    LOG_INFO << "Server running on 127.0.0.1:8848";
    drogon::app().run();

    return 0;
}
