#include "Filesystemhelpers.hpp"
#include "Usage.hpp"
#include "ItemMock.hpp"
#include "FactoryMock.hpp"
#include <memory>

#include "gtest/gtest.h"

using namespace src;

class FileSystemTC : public testing::Test
{
public:
    FileSystemTC()
    {
        std::cout<< "Running Ctor\n";
        createDirectory(path);
    }
    ~FileSystemTC()
    {
        std::cout<< "Running Dtor\n";
        // removeFile(path + fileN);
        removeDirectory(path);
    }
    void createFile(const std::string& fileName, const std::string& content)
    {
        std::ofstream outfile (fileName);

        outfile << content;

        outfile.close();
    }

protected:
    std::string path = "./tmp/";
    std::string fileN = "dupa.txt";
};

TEST_F(FileSystemTC, firstTest)
{
   auto pathFile = path + fileN;
    {
        const std::string content = "michal jest super";
        
        createFile(pathFile, content);
        EXPECT_TRUE(doesFileExists(pathFile));
        EXPECT_EQ(content, getFileContent(pathFile));
    }
    {
        removeFile(pathFile);
        EXPECT_FALSE(doesFileExists(pathFile));
    }
}

TEST_F(FileSystemTC, secondTest)
{
    auto pathFile = path + fileN;
    {
        const std::string content = "dupa_12";
        
        createFile(pathFile, content);
        EXPECT_TRUE(doesFileExists(pathFile));
        EXPECT_EQ(content, getFileContent(pathFile));
    }
    {
        removeFile(pathFile);
        EXPECT_FALSE(doesFileExists(pathFile));
    }
}