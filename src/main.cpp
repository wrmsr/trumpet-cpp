#include <signal.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curlcpp/curl_easy.h>
#include <curlcpp/curl_exception.h>

static int received_shutdown_signal = 0;

static void handle_shutdown_signal(int sig) {
    received_shutdown_signal = sig;
}

int main(int argc, const char *const argv[]) {
    signal(SIGINT, handle_shutdown_signal);
    signal(SIGTERM, handle_shutdown_signal);

    curl::curl_easy easy;
    easy.add<CURLOPT_URL>("https://api.remind.com/v2/chats");
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);
    try {
        easy.perform();
    } catch (curl::curl_easy_exception error) {
        curl::curlcpp_traceback errors = error.get_traceback();
        error.print_traceback();
    }

    boost::property_tree::ptree root;

    return 0;
}
