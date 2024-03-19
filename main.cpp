#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <algorithm>

std::string findModelFile(const std::string& directory)
{
    DIR* dir;
    struct dirent* entry;
    std::vector<std::string> modelFiles;

    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            std::string filename = entry->d_name;
            size_t pos = filename.find_last_of(".");
            if (pos != std::string::npos &&
                filename.substr(pos + 1) == "xmodel") {
                modelFiles.push_back(filename);
            }
        }
        closedir(dir);

        // 對找到的檔案名稱進行排序
        std::sort(modelFiles.begin(), modelFiles.end());

        // 返回排序後的第一個檔案
        if (!modelFiles.empty()) {
            return directory + modelFiles[0];
        }
        std::cout << "Can not find any xmodel in.\n";
    } else {
        std::cout << "Dir not exist.\n";
    }

    return "";  // 如果找不到副檔名為.model的檔案，回傳空字串
}

int main()
{
    std::string directory =
        "/media/ccs/HueiRu_disk2/github-current/cpp_test/tttest/";
    std::string modelFilePath = findModelFile(directory);
    if (!modelFilePath.empty()) {
        std::cout << "找到模型檔案：" << modelFilePath << std::endl;
    } else {
        std::cout << "找不到副檔名為 .model 的檔案。" << std::endl;
    }
    return 0;
}
