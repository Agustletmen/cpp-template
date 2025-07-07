// #include <iostream>
// #include <vector>
// #include <string>

// // Boost 库头文件
// #include <boost/algorithm/string.hpp>
// #include <boost/filesystem.hpp>
// #include <boost/regex.hpp>

// // 1. 使用 Boost 算法库分割字符串
// std::vector<std::string> split_string(const std::string& input, const std::string& delimiter) {
//     std::vector<std::string> tokens;
//     boost::split(tokens, input, boost::is_any_of(delimiter));
//     return tokens;
// }

// // 2. 使用 Boost 文件系统库检查文件是否存在
// bool file_exists(const std::string& path) {
//     return boost::filesystem::exists(path);
// }

// // 3. 使用 Boost 正则表达式匹配
// bool validate_email(const std::string& email) {
//     const boost::regex pattern("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
//     return boost::regex_match(email, pattern);
// }

// // 4. 使用 Boost 字符串算法转换大小写
// std::string to_upper(const std::string& input) {
//     std::string result = input;
//     boost::to_upper(result);
//     return result;
// }

// int main() {
//     // 测试字符串分割
//     std::string text = "hello,world,boost,c++";
//     auto parts = split_string(text, ",");
//     std::cout << "Split result: ";
//     for (const auto& part : parts) {
//         std::cout << "[" << part << "] ";
//     }
//     std::cout << std::endl;

//     // 测试文件检查
//     std::cout << "File exists test: " << (file_exists("example.txt") ? "Yes" : "No") << std::endl;

//     // 测试邮箱验证
//     std::string email = "test@example.com";
//     std::cout << "Email validation: " << (validate_email(email) ? "Valid" : "Invalid") << std::endl;

//     // 测试大小写转换
//     std::cout << "Uppercase: " << to_upper("hello boost") << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <boost/asio.hpp>

// using namespace boost::asio;

// int main()
// {
//     io_context io;
//     serial_port sp(io, "COM1");

//     // 设置串口参数
//     sp.set_option(serial_port::baud_rate(9600));
//     sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
//     sp.set_option(serial_port::parity(serial_port::parity::none));
//     sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));
//     sp.set_option(serial_port::character_size(8));

//     // 读取数据
//     char buf[128];
//     boost::system::error_code ec;
//     size_t n = sp.read_some(buffer(buf), ec);

//     if (!ec)
//     {
//         std::cout << "Read " << n << " bytes: " << buf << std::endl;
//     }
//     else
//     {
//         std::cerr << "Error: " << ec.message() << std::endl;
//     }

//     return 0;
// }

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

int main()
{
    io_context io;
    serial_port sp(io, "COM1");

    // 设置串口参数
    sp.set_option(serial_port::baud_rate(9600));
    sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
    sp.set_option(serial_port::parity(serial_port::parity::none));
    sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));
    sp.set_option(serial_port::character_size(8));

    std::cout << "开始监听串口..." << std::endl;
    
    try {
        char buf[128];
        while (true) {
            size_t n = sp.read_some(buffer(buf));
            if (n > 0) {
                std::cout << "收到 " << n << " 字节: ";
                for (size_t i = 0; i < n; ++i)
                    std::cout << std::hex << static_cast<int>(static_cast<unsigned char>(buf[i])) << " ";
                std::cout << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}