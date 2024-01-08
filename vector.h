#include <cstddef>
#include <utility>

template <typename T>
class vector
{
public:
    /*
       容量相关
   */

    // 空间相关(不会修改元素)
    void reserve(size_t n); // 重新申请空间，只能多不能少(指的是空间大小而非元素个数)
    void shrink_to_fit();   // 重新申请空间，大小和当前元素的个数相同
    size_t capacity();      // 空间大小
    // 元素相关(不会直接修改空间，按正常空间增长模式进行，不会减小空间)
    void resize(size_t sz); // 直接设置元素, 多了用默认值初始化, 少了去掉末尾的
    void empty();           // 是否为空
    size_t size();          // 元素个数
    size_t max_size();      // 当前设备可以存放最多的元素个数(和设备有关)
};

class string
{
public:
    /*
       字符串操作相关
    */

    // 正向查找字串：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    size_t find(const char &c, size_t pos = 0);
    size_t find(const char &c, size_t pos, size_t n);
    size_t find(const string &str, size_t pos = 0);
    size_t find(const string &str, size_t pos, size_t n);
    // 反向查找字串：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    // 注意：反向查找中，给的参数也都是正向的参数，如: 0 表示开始位置索引
    size_t rfind(const char &c, size_t pos = 0);
    size_t rfind(const char &c, size_t pos, size_t n);
    size_t rfind(const string &str, size_t pos = 0);
    size_t rfind(const string &str, size_t pos, size_t n);
    // 正向查找字符：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    // 只要找到给定字符串中的任何一个字符时，就匹配成功(相当于是模糊匹配了)
    size_t find_first_of(const char &c, size_t pos = 0);
    size_t find_first_of(const char &c, size_t pos, size_t n);
    size_t find_first_of(const string &str, size_t pos = 0);
    size_t find_first_of(const string &str, size_t pos, size_t n);
    // 反向查找字符：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    // 只要找到给定字符串中的任何一个字符时，就匹配成功(相当于是模糊匹配了)
    size_t find_last_of(const char &c, size_t pos = 0);
    size_t find_last_of(const char &c, size_t pos, size_t n);
    size_t find_last_of(const string &str, size_t pos = 0);
    size_t find_last_of(const string &str, size_t pos, size_t n);
    // 正向查找不存在的字符：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    // 只要找到给定字符串中的任何一个不存在的字符时，就匹配成功(相当于是找不存在的了)
    size_t find_first_not_of(const char &c, size_t pos = 0);
    size_t find_first_not_of(const char &c, size_t pos, size_t n);
    size_t find_first_not_of(const string &str, size_t pos = 0);
    size_t find_first_not_of(const string &str, size_t pos, size_t n);
    // 反向查找不存在的字符：<目标字符/目标字符串> <开始查找的位置(索引)> <查找目标字符串中的前几个字符>
    // 只要找到给定字符串中的任何一个不存在的字符时，就匹配成功(相当于是找不存在的了)
    size_t find_last_not_of(const char &c, size_t pos = 0);
    size_t find_last_not_of(const char &c, size_t pos, size_t n);
    size_t find_last_not_of(const string &str, size_t pos = 0);
    size_t find_last_not_of(const string &str, size_t pos, size_t n);
};

template <typename T, typename U>
class unordered_map
{
    using Iterator = T *;
    /*
       修改元素相关
    */

    // 删除元素
    void clear(); // 清除所有元素
};

template <typename T>
class unordered_set
{
public:
    using Iterator = T *;
    /*
       修改元素相关
    */

    // 删除元素
    void clear(); // 清除所有元素
    // 插入元素
    std::pair<Iterator, bool> insert(const T &value); // 第一个迭代器指向对应元素，bool 反应是否插入成功
    void insert(std::initializer_list<T> ilist);      // 初始化列表插入，没有返回值

    /*
       查找元素相关
    */

    size_t count(const T &key); // 返回改元素的个数
};
