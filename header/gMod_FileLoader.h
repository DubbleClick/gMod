#pragma once

#include <vector>
#include <string>
#include <ranges>
#include <libzippp.h>

struct TpfEntry {
    std::string name;
    std::string entry;
    uint32_t crc_hash;
    void* data;
    unsigned long long size;
};

class gMod_FileLoader {
    std::string file_name;
    const std::string TPF_PASSWORD{
        0x73, 0x2A, 0x63, 0x7D, 0x5F, 0x0A, static_cast<char>(0xA6), static_cast<char>(0xBD),
        0x7D, 0x65, 0x7E, 0x67, 0x61, 0x2A, 0x7F, 0x7F,
        0x74, 0x61, 0x67, 0x5B, 0x60, 0x70, 0x45, 0x74,
        0x5C, 0x22, 0x74, 0x5D, 0x6E, 0x6A, 0x73, 0x41,
        0x77, 0x6E, 0x46, 0x47, 0x77, 0x49, 0x0C, 0x4B,
        0x46, 0x6F
    };

public:
    gMod_FileLoader(const std::string& fileName);

    std::vector<TpfEntry> GetContents();

private:

    std::vector<TpfEntry> GetTpfContents();

    std::vector<TpfEntry> GetFileContents();

    void LoadEntries(libzippp::ZipArchive& archive, std::vector<TpfEntry>& entries);
};
