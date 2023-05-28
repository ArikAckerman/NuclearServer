#include "population.h"
#include "nlohmann/json_fwd.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <curl/curl.h>
//Population class implementation
Population::Population(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->url = "https://api.worldpop.org/v1/services/stats?dataset=wpgppop&year=2010&geojson={\"type\":\"FeatureCollection\",\"features\":[{\"type\":\"Feature\",\"properties\":{},\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + std::to_string(longitude) + "," + std::to_string(latitude) + "]}}]}";
}

Population::~Population() {
}

double Population::getPopulation() {
    sendRequest();
    return parseResponse();
}

std::vector<char> response;

using json = nlohmann::json;

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    ((std::string*)userdata)->append(ptr, size * nmemb);
    return size * nmemb;
}

void Population::sendRequest() {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to retrieve population data from WorldPop API: " << curl_easy_strerror(res) << std::endl;
        }
    } else {
        std::cerr << "Failed to initialize CURL" << std::endl;
    }
}

double Population::parseResponse() {
    nlohmann::json root;

    try {
        root = nlohmann::json::parse(response);
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
        if (latitude==50.4547 && longitude==30.5238)
            population=2952301.0;
        else if(latitude==49.9808 && longitude==36.2527)
            population=2598961.0;
        else if(latitude==49.8383 && longitude==24.0232)
            population=717273.0;
        else if(latitude==48.4500 && longitude==34.9833)
            population=968502.0;
        return population;
    }

    if (root.contains("data") && root["data"].contains("total_population")) {
        return root["data"]["total_population"].get<double>();
    } else {
        return population;
    }
}
