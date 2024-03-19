#include <iostream>
#include <sys/statvfs.h>

int main()
{
    const char* path = "/";  // 这里设置你要查询的文件系统路径，通常是根目录 "/"
    struct statvfs buf;

    if (statvfs(path, &buf) == 0) {
        unsigned long long totalSpace = buf.f_blocks * buf.f_frsize;
        unsigned long long freeSpace = buf.f_bfree * buf.f_frsize;
        unsigned long long availableSpace = buf.f_bavail * buf.f_frsize;

        std::cout << "Total space: " << totalSpace / (1024 * 1024 * 1024)
                  << " GB" << std::endl;
        std::cout << "Free space: " << freeSpace / (1024 * 1024 * 1024) << " GB"
                  << std::endl;
        std::cout << "Available space: "
                  << availableSpace / (1024 * 1024 * 1024) << " GB"
                  << std::endl;
    } else {
        std::cerr << "Error occurred while getting file system information."
                  << std::endl;
        return 1;
    }

    return 0;
}
