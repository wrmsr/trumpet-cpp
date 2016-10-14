set(CURLCPP_INCLUDE_FILES
        include/curlcpp/cookie.h
        include/curlcpp/cookie_date.h
        include/curlcpp/cookie_datetime.h
        include/curlcpp/cookie_time.h
        include/curlcpp/curl_config.h
        include/curlcpp/curl_cookie.h
        include/curlcpp/curl_easy.h
        include/curlcpp/curl_easy_info.h
        include/curlcpp/curl_exception.h
        include/curlcpp/curl_form.h
        include/curlcpp/curl_global.h
        include/curlcpp/curl_header.h
        include/curlcpp/curl_info.h
        include/curlcpp/curl_interface.h
        include/curlcpp/curl_ios.h
        include/curlcpp/curl_multi.h
        include/curlcpp/curl_option.h
        include/curlcpp/curl_pair.h
        include/curlcpp/curl_receiver.h
        include/curlcpp/curl_sender.h
        include/curlcpp/curl_share.h
        include/curlcpp/curl_utility.h
        )

set(CURLCPP_SOURCE_FILES
        src/curlcpp/curl_easy.cpp
        src/curlcpp/curl_header.cpp
        src/curlcpp/curl_form.cpp
        src/curlcpp/curl_multi.cpp
        src/curlcpp/curl_share.cpp
        src/curlcpp/curl_info.cpp
        src/curlcpp/curl_cookie.cpp
        src/curlcpp/curl_exception.cpp
        src/curlcpp/cookie.cpp
        src/curlcpp/cookie_date.cpp
        src/curlcpp/cookie_time.cpp
        src/curlcpp/cookie_datetime.cpp
        )

add_library(curlcpp
        ${CURLCPP_INCLUDE_FILES}
        ${CURLCPP_SOURCE_FILES}
        )

target_include_directories(curlcpp PUBLIC
        include
        ${CURL_INCLUDE_DIRS}
        )

target_link_libraries(curlcpp
        ${CURL_LIBRARIES}
        )
