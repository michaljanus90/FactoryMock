#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

void createDirectory(const std::string& directoryPath)
{
    int status;
    status = mkdir(directoryPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    std::cout << "Status(" << __func__ << ") is" << status << std::endl;
}

void removeDirectory(const std::string& directoryPath)
{
    int status;
    status = rmdir(directoryPath.c_str());
    std::cout << "Status(" << __func__ << ") is" << status << std::endl;
}

void copyFile(const std::string& source, const std::string& dstPath)
{
    std::ifstream  src(source.c_str(), std::ios::binary);
    std::ofstream  dst(dstPath.c_str(),   std::ios::binary);

    dst << src.rdbuf();
}

void removeFile(const std::string& filePath)
{
    if( remove( filePath.c_str() ) != 0 )
        throw std::runtime_error("Unable to remove file:" + filePath);
    else
        std::cout << "File successfully deleted" << std::endl;
}

bool doesFileExists(const std::string& name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

std::string getFileContent(const std::string& name)
{
    if (not doesFileExists(name))
        throw std::runtime_error("File does not exists" + name);

    std::ifstream file(name);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}