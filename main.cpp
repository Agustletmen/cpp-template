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