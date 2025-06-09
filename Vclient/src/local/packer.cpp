#include "packer.h"

void packer::write(const std::string& path, const unsigned char* data, size_t size) {
    std::ofstream file(path, std::ios::binary | std::ios::trunc);
    /*
        if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
        std::cerr << "Error code: " << GetLastError() << std::endl;
        return;
    }
    */
    file.write(reinterpret_cast<const char*>(data), size);
    file.close();
}

unsigned char* packer::read(const std::string& path, size_t& outSize) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        outSize = 0;
        return nullptr;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (size <= 0) {
        outSize = 0;
        return nullptr;
    }

    unsigned char* buffer = new unsigned char[size];
    if (!file.read(reinterpret_cast<char*>(buffer), size)) {
        delete[] buffer;
        outSize = 0;
        return nullptr;
    }

    outSize = static_cast<size_t>(size);
    return buffer;
}
