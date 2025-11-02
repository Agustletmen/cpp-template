#include <thread>
#include <mutex>
#include<atomic>

std::mutex mtx;  // 互斥锁，保证临界区独占访问
std::condition_variable var; // 条件变量，用于线程间等待 / 通知（如生产者 - 消费者模型）。
std::atomic atomic_var; // 原子操作，无锁同步（适合简单计数器）。
std::future fu;
std::promise pro; 异步任务结果获取（更高层封装）。


void safe_task() {
    std::lock_guard<std::mutex> lock(mtx);  // RAII 方式加锁，自动释放
    // 临界区操作（如修改共享变量）
}

void task(int num) {
    // 线程任务
}
int demo() {
    std::thread t1(task, 1);  // 传入函数和参数
    std::thread t2([] { /* 匿名函数任务 */ });
    t1.join();  // 等待线程结束
    t2.detach();  // 线程后台运行（脱离主线程控制）
    return 0;
}