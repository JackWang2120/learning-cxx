#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
static int func(int param) {
    static int static_ = param;
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
/*这里的 static 修饰局部变量 static_，使其具有静态存储期。它的生命周期贯穿整个程序的运行过程，而不是像普通局部变量那样在函数调用结束时就被销毁。
关于 static 变量必须赋初值的问题，实际上 static 变量在未显式初始化时会被自动初始化为默认值（对于整型变量，默认值为 0）。在这个例子中，static int static_ = param; 是显式初始化，使用函数参数 param 来初始化 static_。虽然 param 是一个变量，但这并不影响初始化过程。在函数第一次被调用时，param 的值被用于初始化 static_，之后 static_ 就保留了这个值，并且在后续函数调用中不再重新初始化。
3. 程序执行过程
第一次调用 func(5) 时：
static int static_ = param; 执行，static_ 被初始化为 5。
return static_++; 执行，返回 static_ 的当前值 5，然后 static_ 自增为 6。
第二次调用 func(4) 时：
由于 static_ 已经在第一次调用时初始化过，这次不会再次执行 static int static_ = param;。
return static_++; 执行，返回 static_ 的当前值 6，然后 static_ 自增为 7。
后续调用以此类推，每次调用 func 函数时，static_ 的值都会在前一次的基础上自增。*/
