```c++
// g++ -std=c++20 -Wall -Wpedantic scraping.cpp -lcurl -o scraping
//////////////////////////////////////////////////////////////////
#include <iostream>
#include <curl/curl.h>

// This function will be called by libcurl when new data is received
static size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::string* str = static_cast<std::string*>(userdata);
    str->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a CURL handle
    CURL* curl = curl_easy_init();

    // Set the URL to fetch
    std::string url = "https://example.com/api?key=value";

    // Set the URL and query string
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Set the callback function for libcurl to call when new data is received
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Send the HTTP request and receive the response
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    else {
        std::cout << "Response: " << response << std::endl;
    }

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
```
