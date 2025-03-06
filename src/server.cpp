#include <uwebsockets/App.h>
#include <iostream>
#include <fstream>

std::string loadHTML(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "<h1>Error Loading HTML</h1>";
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

int main() {
    std::string html = loadHTML("../public/index.html");

    uWS::App().get("/*", [&html](auto *res, auto *req) {
        res->writeHeader("Content-Type", "text/html")->end(html);
    }).listen(8080, [](auto *token) {
        if (token) {
            std::cout << "Server running on http://localhost:8080\n";
        }
    }).run();

    return 0;
}
