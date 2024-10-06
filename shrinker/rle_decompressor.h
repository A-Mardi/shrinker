#pragma once

#ifndef RLE_DECOMPRESSOR_H
#define RLE_DECOMPRESSOR_H

#include <string>

void decompressRLE(const std::string& inputFilePath, const std::string& outputFilePath);

#endif // RLE_DECOMPRESSOR_H