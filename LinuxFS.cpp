#include<iostream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cout << "Cach chay: ./LinuxFS <xau can tim> <thu muc cha>\n";
        return 0;
    }
    
    std::string name2find = argv[1];
    try
    { 
        for (const auto & entry : fs::recursive_directory_iterator(argv[2]))
        {
            if(!entry.is_directory())
            {
                fs::path filePath(entry);
                std::string filePath_str = filePath.filename();
                if(filePath_str.find(name2find) != std::string::npos)
                {
                    std::cout << std::string(filePath) << std::endl;
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}