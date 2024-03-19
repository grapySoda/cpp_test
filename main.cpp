#include <iostream>
#include <sys/statvfs.h>

double getDiskUsageRatio(const std::string& path)
{
    struct statvfs fsInfo;

    // 使用 statvfs 函數獲取指定路徑的文件系統信息
    if (statvfs(path.c_str(), &fsInfo) != 0) {
        std::cerr << "Error: Failed to get filesystem stats for path: " << path
                  << std::endl;
        return -1.0;  // 返回負值表示錯誤
    }

    // 計算已使用空間與總空間的比率
    double totalSpace =
        static_cast<double>(fsInfo.f_blocks) * fsInfo.f_frsize;  // 總空間
    double usedSpace = static_cast<double>(fsInfo.f_blocks - fsInfo.f_bfree) *
                       fsInfo.f_frsize;  // 已使用空間
    double usageRatio = usedSpace / totalSpace;
    return usageRatio;
}

int main()
{
    std::string path;
    std::cout << "Enter the path: ";
    std::cin >> path;

    double usageRatio = getDiskUsageRatio(path);
    if (usageRatio >= 0) {
        std::cout << "Disk usage ratio at " << path << ": " << usageRatio
                  << std::endl;
    }

    return 0;
}
